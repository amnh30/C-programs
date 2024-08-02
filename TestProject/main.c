/************************************************************************************
**  File_Name :  Calculator.c                                                      **
**  Title     :  full Calculator                                                   **
**  Version   : 1.0.0                                                              **
**  Author    : Ahmed Nageeb                                                       **
************************************************************************************/
/*----------IncludingsectionStart-----------*/
#include <stdio.h>
//#include "motor.h"
//#include "motor.h"
//#pragma GCC error "hello world"
int va = 10000;
//#define summing(Name1, Name2) (Name1 + Name2)
/*----------IncludingsectionEnd-------------*/

/*-------------Variable-Section---------*/

/*--------------------------------------*/
unsigned int stdIds[5] = {1,5,6,8,3};
void Printstids(const unsigned int stdIdsarray[], const unsigned int arraysize);
/*---------Main-Fun-section-------------*/
int main()
{   
    //#if 0
    //printhelllo();
    //printf("the sum is %i",summing(3,3) );
    //printf("hello %d",va);
   //printf("\nvar is %i \n",setcar());
   //getchar();
   //#endif
//    printf("%s\n",__DATE__);
//    printf("%s\n",__FILE__);
//    printf("%i\n",__LINE__);
//    #line 565 "motor.c"
//    printf("%i\n",__LINE__);
//    printf("%s\n",__FILE__);
//    char arraay[5] = "Ahmed";
//    char arraay2[5] = "Ahmed ";
//    printf("%i\n",sizeof(arraay));
//    //printf("%s",arraay);
//    printf("%i",sizeof(arraay2));
// char array[50]= "AhmedHElllooasdasd";
// printf("%s\n",array);
// scanf("%s",&array);
// gets(array);
// printf("%s\n",array);



Printstids(stdIds,5);



















   
    return 0;
}
/*--------------------------------------*/ 

void Printstids(const unsigned int stdIdsarray[], const unsigned int arraysize){
    unsigned int stdindex = 0;
    for ( stdindex = 0; stdindex < arraysize; stdindex++)
    {
        printf("stdIds[%i] = %i \n",stdindex,stdIdsarray[stdindex]);
    }
    
}