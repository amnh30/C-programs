#include<stdio.h>
int HPB;
int HPBCounter;
int VPB;
int VPBCounter;
int ManualSwitch;
int VirtualSwitch;
int HorizontalError;
void HorizontalButton(void);
void VerticalButton(void);
void Flashing(void); 
void Run(void);
int main()
{
    while(1){
        Run();
    }
    return 0;
}


void HorizontalButton(void){

printf("the value of HPB\n");
scanf("%i", & HPB);

if(1 == HPB){
HPBCounter  = !HPBCounter;
printf("the Horizontal led is %i\n", HPBCounter);

}
}
void VerticalButton(void){

printf("the vertical led\n");
scanf("%i", & VPB);
VPBCounter += VPB;
switch (VPBCounter){

    case 1:

        printf("the V led one is on\n");
        break;
    case 2:
        printf("the V led one is still on\n");
        printf("the V led two is on\n");
        break;
    case 3:   
        printf("the V led one is off\n");
        printf("the V led two is off\n");
        VPBCounter=0;
        break;
    }    
}
void  Flashing(void){
    printf("Enter The Horizontal Error ");
    scanf("%i", &HorizontalError);
    if((1 == ManualSwitch && 1==HorizontalError)||(1==ManualSwitch &&1==VirtualSwitch)){
        printf("All The LEDs are on\n");
        printf("Delay(100);\n");
        printf("All The LEDs are off\n");
    }
}
void Run(void){
    printf("Enter The Manual Switch ");
    scanf("%i", &ManualSwitch);
    printf("Enter The Virtual Switch ");
    scanf("%i", &VirtualSwitch);
    if(1 == VirtualSwitch ||1 == ManualSwitch ){
        Flashing();
        HorizontalButton();
        VerticalButton();
    }
}