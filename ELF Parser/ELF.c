#include <stdio.h>
#include"STD_TYPES.h"
#include <string.h>
#include <Windows.h>


#define ELF_TYPE_EXECUTABLE 0x2
#define ELF_PT_LOAD 0x1
#define ELF_PT_X 0x1
#define ELF_PT_R 0x2
#define ELF_PT_W 0x4

#define COM_PORT_NAME "\\\\.\\COM"


#define PAGE_SIZE       1024


#define     BL_CMD_WRITE_SECTOR         0
#define     BL_CMD_FLASH_NEW_APP        1
#define     BL_CMD_VERIFY_DATA          2


#define     APP_FLASH_SIZE              0x5800      
#define     APP1_FLASH_ADDRESS          0x08003C00      
#define     APP2_FLASH_ADDRESS          0x08008000  

#define     BL_VERIFY_OK                0x55
#define     BL_VERIFY_NOK               0xFF

#define ROM_SIZE     65536

#define  SIZE  1024*1024


typedef struct __attribute__((packed))
{
	u8 req_counter;
	u8 cmd;
}BL_comm_header_t;



typedef struct __attribute__((packed))
{
	u32 baseAddress;
	u16 fileSize;
	BL_comm_header_t BL_comm_header;
}new_app_t;


typedef struct 
{
	uint8_t identity[16];
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry;
	uint32_t ph_offset;
	uint32_t sh_offset;
	uint32_t flags;
	uint16_t header_size;
	uint16_t ph_size;
	uint16_t ph_num;
	uint16_t sh_size;
	uint16_t sh_num;
	uint16_t strtab_index;
}elf_header;

typedef struct __attribute__((packed))
{
	uint32_t type;
	uint32_t offset;
	uint32_t virtual_address;
	uint32_t physical_address;
	uint32_t file_size;
	uint32_t mem_size;
	uint32_t flags;
	uint32_t align;
}elf_phead;




void flashNewApp(void);
void sendHeader(u16 counter, u8 cmd);
void sendpage(void);

void MAIN_initComm(void);

void MAIN_sendComm(char *buffer, int size);
void MAIN_readComm(char * buffer);

int is_elf(elf_header *elf);
void load_elf_segment(uint8_t *data, elf_phead *phead);

int load_elf(uint8_t *data);


u8 DataToBeSend[ROM_SIZE]={0};
u32 Data_Position        =0;
u32 DataSendingPosition        =0;


int G_fileSize=0;
HANDLE hComm; 
uint32_t filepos;
uint32_t filesize;

char  ComPortName[13]; // Name of the Serial port(May Change) to be opened,

FILE *python; 

u8 buffer[SIZE];

void main(int argc,char* argv[])
{

	u8 idx;
	u8 responseBuffer;
	char file_name[30];
	char filename[30];
	FILE *fd; 
	FILE *gui; 
	elf_header * Header;
	u8 writeCounter=0;
	u8 maxCount;
	u8 header_error=0;
	char com[5];
	int installationFlag = 1;
	strcpy(ComPortName, COM_PORT_NAME);
	if(argc > 1)
	{
		strcpy(file_name, argv[1]);

		printf("%s\n", file_name);


		if(argv[2][3] == '1')
		{
			ComPortName[7] = argv[2][3] ;		
			ComPortName[8] = argv[2][4] ;
		}
		else
		{
			ComPortName[7] = argv[2][3] ;	
		}




	}
	else if( argc == 1)
	{
		printf("enter file name: ");
		scanf("%s",filename);
		strcpy(file_name, filename);

		printf("enter COM number: ");
		scanf("%s",com);

		if(com[3] == '1')
		{
			ComPortName[7] = com[3] ;		
			ComPortName[8] = com[4] ;
		}
		else
		{
			ComPortName[7] = com[3] ;	
		}

	}

	MAIN_initComm();

	fd = fopen(file_name, "r");
	if(fd)
	{
		fread(buffer,SIZE, 1,fd);
		load_elf(buffer);
	}



	flashNewApp()  ;
	maxCount = G_fileSize/PAGE_SIZE;
	if(G_fileSize%PAGE_SIZE)
	{
		maxCount++;
	}
	while(writeCounter<maxCount)
	{
		MAIN_readComm((char*)&responseBuffer);  //rx response  
		if( responseBuffer == BL_VERIFY_OK)
		{
			sendHeader(writeCounter++,BL_CMD_WRITE_SECTOR);
			MAIN_readComm((char*)&responseBuffer);  //rx response  
			if( responseBuffer == BL_VERIFY_OK)
			{
				sendpage();    //send 1024
				DataSendingPosition +=PAGE_SIZE;
			}
			else
			{
				printf("\ncouldn't send bootloader\n");
				header_error = 1;
				installationFlag = 0;
				break;
			}

		}

		else
		{
			printf("\ncouldn't send bootloader\n");
			installationFlag = 0;
			break;
		}
		if(header_error == 1)
		{
			break;
		}

	}

	fclose(fd);

	CloseHandle(hComm);							//Closing the Serial Port
	gui = fopen("GUI.txt", "w");
	if(installationFlag == 1){
		printf("\n\tYour Application is now installed :D\n");
		fprintf(gui,"%s","Your Application is now installed :D");
	}
	else {
		fprintf(gui,"%s","couldn't send bootloader");
		
	}
	fclose(gui);
	printf("\n ==========================================\n");
}


void flashNewApp(void)
{
	printf("\n\tInstalling Application...\n");
	new_app_t new_app;
	new_app.BL_comm_header.req_counter=1           ; 
	new_app.BL_comm_header.cmd=BL_CMD_FLASH_NEW_APP; //1
	new_app.baseAddress = APP1_FLASH_ADDRESS; //0x08005000 
	printf("\n- The files size is %d bytes\n", G_fileSize);
	new_app.fileSize = G_fileSize; 

	MAIN_sendComm((char * )&new_app,(u16)sizeof(new_app_t));
}

void sendHeader(u16 counter, u8 cmd)
{

	BL_comm_header_t BL_comm_header={
			.req_counter = counter,
			.cmd = cmd
	};

	/*	those three lines are for the GUI	*/

	printf("\n- %d KB has been sent \n", counter);
	MAIN_sendComm((char * )&BL_comm_header,(u16)sizeof(BL_comm_header_t));
}

void sendpage(void)
{

	int count = 0;
	char ch;


	MAIN_sendComm((char*)(&DataToBeSend[DataSendingPosition]),PAGE_SIZE);
}


void MAIN_initComm(void)
{

	BOOL   Status;

	printf("\n\n +==========================================+");
	printf("\n |  Serial Transmission (Win32 API)         |");
	printf("\n +==========================================+\n");
	/*----------------------------------- Opening the Serial Port --------------------------------------------*/

	hComm = CreateFile( ComPortName,                       // Name of the Port to be Opened
			GENERIC_READ | GENERIC_WRITE,      // Read/Write Access
			0,                                 // No Sharing, ports cant be shared
			NULL,                              // No Security
			OPEN_EXISTING,                     // Open existing port only
			0,                                 // Non Overlapped I/O
			NULL);                             // Null for Comm Devices

	if (hComm == INVALID_HANDLE_VALUE)
		printf("\n   Error! - Port %s can't be opened", ComPortName);
	else 
		printf("\n   Port %s Opened\n ", ComPortName);


	/*------------------------------- Setting the Parameters for the SerialPort ------------------------------*/

	DCB dcbSerialParams = { 0 };                        // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	Status = GetCommState(hComm, &dcbSerialParams);     //retreives  the current settings

	if (Status == FALSE)
		printf("\n   Error! in GetCommState()");

	dcbSerialParams.BaudRate = CBR_115200;      // Setting BaudRate = 115200
	dcbSerialParams.ByteSize = 8;             // Setting ByteSize = 8
	dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1
	dcbSerialParams.Parity   = NOPARITY;      // Setting Parity = None 

	Status = SetCommState(hComm, &dcbSerialParams);  //Configuring the port according to settings in DCB 

	if (Status == FALSE)
	{
		printf("\n   Error! in Setting DCB Structure");
	}
	else
	{
		printf("\n   Setting DCB Structure Successfull\n");
		printf("\n       Baudrate = %d", dcbSerialParams.BaudRate);
		printf("\n       ByteSize = %d", dcbSerialParams.ByteSize);
		printf("\n       StopBits = %d", dcbSerialParams.StopBits);
		printf("\n       Parity   = %d", dcbSerialParams.Parity);
	}

	/*------------------------------------ Setting Timeouts --------------------------------------------------*/

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout         = 50;
	timeouts.ReadTotalTimeoutConstant    = 50;
	timeouts.ReadTotalTimeoutMultiplier  = 10;
	timeouts.WriteTotalTimeoutConstant   = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (SetCommTimeouts(hComm, &timeouts) == FALSE)
		printf("\n   Error! in Setting Time Outs");
	else
		printf("\n\n   Setting Serial Port Timeouts Successfull");
}


void MAIN_sendComm(char *buffer, int size)
{

	BOOL   Status;
	DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
	DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port
	dNoOFBytestoWrite = size; // Calculating the no of bytes to write into the port
	int success=FlushFileBuffers(hComm);
	if (!success)
	{
		printf("\n\n\n Failed to flush\n");
	}
	Status = WriteFile(hComm,               // Handle to the Serialport
			buffer,            // Data to be written to the port 
			dNoOFBytestoWrite,   // No of bytes to write into the port
			&dNoOfBytesWritten,  // No of bytes written to the port
			NULL);


}

void MAIN_readComm(char * buffer)
{
	/*------------------------------------ Setting Timeouts --------------------------------------------------*/

	BOOL   Status;
	DWORD dwEventMask;                     // Event mask to trigger
	char  TempChar;                        // Temperory Character
	int i = 0;

	DWORD NoBytesRead;                     // Bytes read by ReadFile()

	/*------------------------------------ Setting Receive Mask ----------------------------------------------*/

	Status = SetCommMask(hComm, EV_RXCHAR); //Configure Windows to Monitor the serial device for Character Reception
	if (Status == FALSE)
		printf("\n\n    Error! in Setting CommMask");
	else
		//printf("\n\n    Setting CommMask successfull");
	/*------------------------------------ Setting WaitComm() Event   ----------------------------------------*/


	Status = WaitCommEvent(hComm, &dwEventMask, NULL); //Wait for the character to be received
	/*-------------------------- Program will Wait here till a Character is received ------------------------*/             
	if (Status == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else //If  WaitCommEvent()==True Read the RXed data using ReadFile();
	{
		int success=FlushFileBuffers(hComm);
		if (!success)
		{
			printf("\n\n\n Failed to flush\n");
		}

		success=FlushFileBuffers(hComm);
		if (!success)
		{
			printf("\n\n\n Failed to flush\n");
		}
		do
		{
			Status = ReadFile(hComm, &TempChar, sizeof(TempChar), &NoBytesRead, NULL);
			buffer[i] = TempChar;
			i++;
		}
		while (NoBytesRead > 0);
	}

}

int is_elf(elf_header *elf)
{



	int iself = -1;
	if((elf-> identity[0] == 0x7f) && \
			!strncmp((char *)&elf->identity[1], "ELF", 3))
	{
		iself = 0;
	}
	if(iself != -1)
		iself = elf->type;
	return iself;
}


void load_elf_segment(uint8_t *data, elf_phead *phead)
{
	static int enteranceFlag = 0;
	static int lastFileSize = 0;
	static int lastPhysicalAddress = 0;
	static u32 counter = 0;

	uint32_t memsize = phead->mem_size;         // Size in memory
	uint32_t filesize = phead->file_size;      // Size in file
	uint32_t mempos = phead->virtual_address; // Offset in memory
	filepos = phead->offset;       			  // Offset in file
	u32 index;


	if(enteranceFlag == 0)
	{
		enteranceFlag++;
		lastPhysicalAddress = phead->physical_address;
		lastFileSize = phead->file_size; 
	}
	else
	{
		if(phead->physical_address<0x20000000)
		{
			int diff = phead->physical_address - (lastPhysicalAddress + lastFileSize);
			if(diff<0)
			{
				printf("\ndiff is smaller than 0\n");
			}
			for(int padding = 0; padding < diff; padding ++)
			{	
				DataToBeSend[Data_Position++]=0xFF;
				G_fileSize++;
			}	

			lastPhysicalAddress = phead->physical_address;
			lastFileSize = phead->file_size; 
		}
	}

	for ( index=0;index < filesize ;index++)
	{
		DataToBeSend[Data_Position++] = data[filepos+index];

	}

}

int load_elf(uint8_t *data)
{
	elf_header *elf = (elf_header *)data;
	if(is_elf(elf) != ELF_TYPE_EXECUTABLE )
		return -1;
	elf_phead *phead = (elf_phead*)&data[elf->ph_offset];
	uint32_t i;
	for(i = 0; i < elf->ph_num; i++)
	{
		if(phead[i].type == ELF_PT_LOAD)
		{
			G_fileSize+=phead[i].mem_size;
			load_elf_segment(data, &phead[i]);
		}
	}
	return 0;
}

