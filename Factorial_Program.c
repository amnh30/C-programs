#include <stdio.h>
#include <stdio.h>

 char number;
 char counter;
 char cash = 1;
int main()
{
    printf("PLease enter the factorial number:");
    scanf("%i", &number);
    if(number <=0 ){
        printf("please enter positve number");

    
    }
    else{
        for (counter = 1; counter <= number; counter++)
    {

        cash *= counter;
        printf("%i\n", cash);
        
    }
    }
    return 0;
}
