/**************************************************** 
 	 Author: Mahmoud Gamal, Mohammed Ibrahim, Mostafa Said 
************************************************/
#ifndef AFIO_REGISTER_H
#define AFIO_REGISTER_H



typedef struct 
{
	u32 EVCR;			/*	EVENTOUT IS A MODE USED TO WAKE UP OTHER CONTROLERS, NOT HANDLED IS THIS DRIVER YET!	*/
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
}AFIO_t;


#define		AFIO_BASEADDRESS		0X40010000

volatile AFIO_t* AFIO = (volatile AFIO_t*)AFIO_BASEADDRESS;



#endif
