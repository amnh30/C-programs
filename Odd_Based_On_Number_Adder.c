#include <stdio.h>

int number;
int counter;
int cash;
int main()
{
    printf("PLease enter the number:");
    scanf("%i", &number);
    number *= 2;
    printf("the Numbers : (");
    for (counter = 1; counter <= number; counter += 2)
    {
        cash += counter;

        printf(" %i ", counter);
    }
    printf(")\n");
    printf("The sum is %i", cash);

    return 0;
}
