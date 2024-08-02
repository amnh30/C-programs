#include <stdio.h>

int number;
int counter;
int cash;
int main()
{
    printf("PLease enter the number:");
    scanf("%i", &number);

    for (counter = 1; counter <= number; counter +=2)
    {
        cash += counter;
        printf("counter : %i\n", counter);
        
        
    }
    printf("The sum is %i" , cash);

    return 0;
}
