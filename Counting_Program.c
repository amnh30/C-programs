#include <stdio.h>

int number;
int counter;
int cash;
int main()
{
    printf("PLease enter the number:");
    scanf("%i", &number);

    for (counter = 0; counter <= number; counter++)
    {

        cash += counter;
        
    }
    printf("%i\n", cash);
    return 0;
}
