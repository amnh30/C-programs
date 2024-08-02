
#include <stdio.h>
#include <windows.h>
unsigned char array[10] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,};
unsigned char *ptr1 = NULL;
unsigned char *ptr2 = NULL;

char *Name[2][20] = {"Ahmed ", "Abd Elghafar"};
char (*ptr)[20] = NULL;



void *ptr3 = NULL;

const char *text = "helo ahmed";
//char *ptr = &text;


void main()
{
  //system("cls");

      
  printf("0X%X\n",&text );
  printf("%s\n",text );
  printf("0X%X\n",*text );
    *text = 'w';






}
