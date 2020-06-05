#include <stdio.h>
//#include<stdlib.h>
#include <string.h> 
#define MAXCHAR 1000


int main(int argc,char* argv[]) 
{
    char key[20];
    
    FILE *fp;
    FILE *fpw;
    char* check=NULL;
    char str[MAXCHAR];
    char filename[100];

    if(argc==1)
    {
    printf("Plz enter the word");
    scanf("%s",&key);
    printf("Plz enter the Path");
    scanf("%s",&filename);
    printf("%s",filename);
    printf("Plz enter the path%s",filename);
    }
    else if(argc==3)
    {
      strcpy(filename,argv[1]);
      strcpy(key,argv[2]);
    }
    else
      {
      printf("Not optimum arguments");
    return 0;
    }
  
    fp = fopen(filename, "r");
    
   fpw = fopen(".\\newfile.txt","w");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        {
        check=strstr(str,key);
        if(check)
        {
          printf("%s", str);
          fprintf(fpw,"%s",str);
        }
        }
    fclose(fp);
    fclose(fpw);
    return 0;
}