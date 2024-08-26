
#include <stdio.h>
#include <windows.h>
#define Return_Value 0
FILE *MyFile = NULL;
void main()
{

  MyFile = fopen("S.txt", "w");
  if (NULL != MyFile)
  {
    printf("File Created\n");
  }
  else
  {
    printf("Error !!\n");
  }

  if (Return_Value == fclose(MyFile))
  {
    printf("File closed Sucsessfuly");
  }
  else{
    printf("Error !!");
  }
}
