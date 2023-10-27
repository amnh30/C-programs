// Online C compiler to run C program online
#include <stdio.h>
int pb;
int counter;

int main()
{

    while (1)
    {
        scanf("%i", &pb);
        counter +=pb;
        if (counter%2 ==1)
        {
           printf("The Led is on");
        }
        else if (counter%2 ==0)
        {
            printf("The Led is off");
        }
        
    }
    return 0;
}