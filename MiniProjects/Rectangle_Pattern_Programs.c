/************************************************************************************
**  File_Name :  Rectangle Pattern Programs.c                                      **
**  Title     :  Rectangle Pattern Programs                                        **
**  Version: 1.0.2                                                                 **
**  Author : Ahmed Nageeb                                                          **
************************************************************************************/
/*----------Including-section-----------*/
#include <stdio.h>
/*--------------------------------------*/

/*-------------Variable-Section---------*/
unsigned int Width;
unsigned int Length;
/*--------------------------------------*/

/*---------Main-Fun-section-------------*/
int main()
{

    printf("Please Ente the Width: ");
    scanf("%i", &Width);
    printf("Please Ente the Length: ");
    scanf("%i", &Length);
    printf("---------------------SolideRectangle---------------------\n");

    for (int LengthCounter = 1; LengthCounter <= Length; LengthCounter++)
    {
        for (int WidthCounter = 1; WidthCounter <= Width; WidthCounter++)
        {
            printf("*");
            if (WidthCounter == Width)
            {
                printf("\n");
            }
        }
    }
    printf("---------------------HollowRectangle---------------------\n");
    for (int LengthCounter = 1; LengthCounter <= Length; LengthCounter++)
    {
        for (int WidthCounter = 1; WidthCounter <= Width; WidthCounter++)
        {
            if ((LengthCounter == 1 || LengthCounter == Length) || (WidthCounter == 1 || WidthCounter == Width))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            if (WidthCounter == Width)
            {
                printf("\n");
            }
        }
    }
    return 0;
}
/*--------------------------------------*/