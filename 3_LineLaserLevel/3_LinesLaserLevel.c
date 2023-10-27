/************************************************************************************
**  File_Name :  3_LinesLaserLevel.c
**  Title     :  Used For 3 lines Measure
**  Version   : 1.0.0
**  Author    : Ahmed Nageeb
************************************************************************************/

/*----------Including sectionStart-----------*/
#include <stdio.h>
/*----------Including sectionEnd-------------*/

/*----------Variable DefinitionStart---------*/

// Define the push buttons
int HPB; /*Horizontal Push Button Definition*/
int VPB; /*Vertical Push Button Definition*/

// Define the push button counters
int HPBCounter; /*Horizontal Push Button Counter Definition*/
int VPBCounter; /*Vertical Push Button Counter Definition*/

// Define the manual and virtual switches
int ManualSwitch;  /*Lock Switch Definition*/
int VirtualSwitch; /*Out Push Button Definition*/

// Define the horizontal error sensor
int HorizontalError; /*Horizontal Error Sensor Definition*/

/*----------Variable DefinitionEnd-----------*/

/*----------Function DeclarationStart--------*/

// Declare the horizontal button function
void HorizontalButton(void);

// Declare the vertical button function
void VerticalButton(void);

// Declare the laser flashing function
void Flashing(void);

// Declare the run function, which calls all of the other functions
void Run(void);

/*----------Function DeclarationEnd----------*/

/*----------MainFunctionStart---------------*/

int main()
{
    // Create an infinite loop to keep the program running
    while (1)
    {
        // Call the run function
        Run();
    }

    // Return 0 to indicate that the program terminated successfully
    return 0;
}

/*----------MainFunctionEnd-----------------*/

/*----------HorizontalButtonFunctionStart----*/

void HorizontalButton(void)
{
    // Print a prompt to the user
    printf("Enter the value of the horizontal push button: ");

    // Read the value of the horizontal push button
    scanf("%i", &HPB);

    // If the horizontal push button is pressed, toggle the horizontal Laser
    if (HPB == 1)
    {
        HPBCounter = !HPBCounter;
        printf("The horizontal Laser is now %i\n", HPBCounter);
    }
}

/*----------HorizontalButtonFunctionEnd----*/

/*----------VerticalButtonFunctionStart----*/

void VerticalButton(void)
{
    // Print a prompt to the user
    printf("Enter the value of the vertical push button: ");

    // Read the value of the vertical push button
    scanf("%i", &VPB);

    // Increment the vertical push button counter
    VPBCounter += VPB;

    // Use a switch statement to determine what to do based on the value of the vertical push button counter
    switch (VPBCounter)
    {
    case 1:
        printf("The first vertical Laser is now on\n");
        break;
    case 2:
        printf("The first vertical Laser is still on\n");
        printf("The second vertical Laser is now on\n");
        break;
    case 3:
        // If the vertical push button counter is equal to 3, turn off both vertical Lasers and reset the counter
        printf("The first vertical Laser is now off\n");
        printf("The second vertical Laser is now off\n");
        VPBCounter = 0;
        break;
    }
}

/*----------VerticalButtonFunctionEnd----*/

/*----------ButtonFuntionsStart---------------*/

void Flashing(void)
{
    // Prompt the user to enter the horizontal error
    printf("Enter the horizontal error: ");
    scanf("%i", &HorizontalError);

    // If the manual switch is on and the horizontal error is present, or if the manual switch is on and the virtual switch is on, flash all of the Lasers
    if ((ManualSwitch == 1 && HorizontalError == 1) || (ManualSwitch == 1 && VirtualSwitch == 1))
    {
        printf("All of the Lasers are now on\n");
        printf("Delay(100);\n");
        printf("All The Lasers are off\n");
    }
}
void Run(void)
{
    // Prompt the user to enter the state of the manual and virtual switches
    printf("Enter the state of the manual switch: ");
    scanf("%i", &ManualSwitch);
    printf("Enter the state of the virtual switch: ");
    scanf("%i", &VirtualSwitch);

    // If either the manual or virtual switch is on, call the Flashing(), HorizontalButton(), and VerticalButton() functions
    if (ManualSwitch == 1 || VirtualSwitch == 1)
    {
        // Flash the Lasers
        Flashing();

        // Check the state of the horizontal push button
        HorizontalButton();

        // Check the state of the vertical push button
        VerticalButton();
    }
}