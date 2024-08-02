/************************************************************************************
**  File_Name :  DataType.c                                                        **
**  Title     :  DataType viewer                                                   **
**  Version   : 1.0.0                                                              **
**  Author    : Ahmed Nageeb                                                       **
************************************************************************************/
/*----------IncludingsectionStart-----------*/
#include <stdio.h>
#include <windows.h>
/*----------IncludingsectionEnd-------------*/

/*-------------Variable-Section---------*/

/*--------------------------------------*/

/*---------Main-Fun-section-------------*/
int main()
{
    system("cls");
    
    //printf("Char data size is %d\n",sizeof(char));
    printf("unsigned char data size is %d\n",sizeof(unsigned char));
    printf("signed char data size is %d\n",sizeof(signed char));
    printf("int data size is %d\n",sizeof(int));
    printf("unsigned int data size is %d\n",sizeof(unsigned int));
    printf("short int data size is %d\n",sizeof(short int));
    printf("unsigned short data size is %d\n",sizeof(unsigned short));
    printf("long data size is %d\n",sizeof(long));
    printf("long long data size is %d\n",sizeof(long long));
    printf("unsigned long data size is %d\n",sizeof(unsigned long));
    
    
}
/*--------------------------------------*/