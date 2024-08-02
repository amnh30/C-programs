/************************************************************************************
**  File_Name :  Hollow Diamond Inscribed in a Rectangle.c                         **
**  Title     :  Hollow Diamond Inscribed in a Rectangle                           **
**  Version   : 1.0.0                                                              **
**  Author    : Ahmed Nageeb                                                       **
************************************************************************************/
/*----------IncludingsectionStart-----------*/
#include <stdio.h>
/*----------IncludingsectionEnd-------------*/

/*-------------Variable-Section---------*/
unsigned int row;
unsigned int left;
unsigned int space;
unsigned int decrease = 5;
unsigned int increase = 0;
/*--------------------------------------*/

/*---------Main-Fun-section-------------*/
int main()
{

    for (row = 0; row < 5; row++)
    {
        for (left = decrease; left > 0; left--)
        {
            printf("*");
        }
        for (space = increase; space < 5; space--)
        {
            printf(" ");
            printf(" ");
        }
        for (left = decrease; left > 0; left--)
        {
            printf("*");
        }
        printf("\n");
        --decrease;
        ++increase;
    }
    for (row = 0; row < 5; row++)
    {
        for (left = decrease; left < 10; left++)
        {
            printf("*");
        }
        for (space = increase; space > 5; space--)
        {
            printf(" ");
            printf(" ");
        }
        for (left = decrease; left < 10; left++)

            printf("\n");
        ++decrease;
        --increase;
    }

    return 0;
}
/*--------------------------------------*/