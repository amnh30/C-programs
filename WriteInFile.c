
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Return_Value 0

FILE *MyFile = NULL;
UINT8  x;
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

    for (int i = 0; i < 10; i++)
    {
        printf("Please Ente the Number ");
        scanf("%i", &x);

        fprintf(MyFile, "%i", x);
    }

    if (Return_Value == fclose(MyFile))
    {
        printf("File closed Sucsessfuly");
    }
    else
    {
        printf("Error !!");
    }
}
