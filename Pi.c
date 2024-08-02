#include <Arduino.h>
#include "BluetoothSerial.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#define PodeMasterTS 32
#define PodeSlaveTS 33
#define PodeMasterRLED 25
#define PodeMasterGLED 26
#define PodeSlaveRLED 27
#define PodeSlaveGLED 14
int Fixminutes, Fixseconds;
byte TestLEDCounter = 5;
int StepsCounter = 0;
int led1Counter = 0;
int led2Counter = 0;
int minutes, seconds;
int buttonState1 = 0; // variable for reading the pushbutton status
int Game = 1;
int selector ;

String Mode;
unsigned long startTime1 = 0;     // variable to store the time when the button is pressed
unsigned long endTime1 = 0;       // variable to store the time when the button is released
unsigned long pressDuration1 = 0; // variable to store the duration of button press

int buttonState2 = 0;             // variable for reading the pushbutton status
unsigned long startTime2 = 0;     // variable to store the time when the button is pressed
unsigned long endTime2 = 0;       // variable to store the time when the button is released
unsigned long pressDuration2 = 0; // variable to store the duration of button press

const char *pin = "1234";

String device_name = "Plaze";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
void waitblue();
void stringToTime(const String &str, int &minutes, int &seconds);
bool isValidTimeString(const String &str);
void countdownWithReadCounter(void *parameter);
void GetReadyCounter();
void PodeSelector(void *parameter);
void Start();
void LEDsDefaultState();
void TestLEDs();
void Timeout();
void Rater();
BluetoothSerial SerialBT;
TaskHandle_t countdownTask;
TaskHandle_t podeSelectorTask;
void setup()
{
  Serial.begin(115200);
  SerialBT.begin(device_name); // Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
// Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
#ifdef USE_PIN
  SerialBT.setPin(pin);
  Serial.println("Using PIN");
#endif

  int PinsConfigArray[] = {PodeMasterTS, PodeSlaveTS, PodeMasterRLED, PodeMasterGLED, PodeSlaveRLED, PodeSlaveGLED};
  for (short i = 0; i < 6; i++)
  {
    if (i == 0 || i == 1)
      pinMode(PinsConfigArray[i], INPUT);
    else
    {
      pinMode(PinsConfigArray[i], OUTPUT);
    }
  }
  randomSeed(analogRead(0));
}

void loop()
{
  TestLEDs();
  Start();
}

void waitblue()
{
  while (!SerialBT.available())
  {
    delay(100); // Adjust delay time as needed
  }
}
bool isValidTimeString(const String &str)
{
  if (str.length() != 4)
  {
    return false;
  }
  for (size_t i = 0; i < str.length(); ++i)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

// Function to convert a string representing minutes and seconds to minutes and seconds
void stringToTime(const String &str, int &minutes, int &seconds)
{
  minutes = (str.substring(0, 2)).toInt();
  seconds = (str.substring(2)).toInt();
  Fixminutes = minutes;
  Fixseconds = seconds;
}
void countdownWithReadCounter(void *pvParameters)
{
  for (; minutes >= 0; minutes--)
  {
    for (; seconds >= 0; seconds--)
    {
      // SerialBT.print("Countdown: ");
      // SerialBT.print(minutes);
      // SerialBT.print(":");
      // SerialBT.println(seconds);
      // delay(1000); // Wait for 1 second
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    seconds = 59; // Reset seconds for the next minute
  }
  SerialBT.println("Congratulations Good job");
  char message[50]; // Define a char array to hold the formatted message
  StepsCounter = led1Counter + led2Counter;
  // Format the message using sprintf
  sprintf(message, "%d per %d:%d", StepsCounter, Fixminutes, Fixseconds);

  // Print the formatted message using Serial
  SerialBT.println(message);
  if (minutes == -1 && seconds == 59)
  {

    Timeout();
    LEDsDefaultState();
    // Serial.println(StepsCounter);
  }
  vTaskDelete(NULL); // Delete the task once done
}

void GetReadyCounter()
{
  // 5-second read counter
  Serial.println("Get Ready !!");
  SerialBT.println("Get Ready !!");
  for (int i = 5; i > 0; i--)
  {

    Serial.println(i);
    SerialBT.println(i);
    delay(1000); // Wait for 1 second
  }
}

void PodeSelector(void *pvParameters)
{
  int selectedLED = random(1); // Randomly select an LED
  while (minutes != 0 || seconds != 0)
  {

    if (selectedLED == 0)
    {
      digitalWrite(PodeMasterRLED, HIGH);
      while (true)
      {

        buttonState1 = digitalRead(PodeMasterTS); // read the state of the pushbutton

        if (buttonState1 == HIGH)
        {                        // if button is pressed down
          startTime1 = millis(); // record the start time
          while (buttonState1 == HIGH)
          { // wait until button is released
            buttonState1 = digitalRead(PodeMasterTS);
          }
          endTime1 = millis();                    // record the end time
          pressDuration1 = endTime1 - startTime1; // calculate the duration of button press
          digitalWrite(PodeMasterRLED, LOW);
          led1Counter++;
          Serial.print("Button pressed for: ");
          Serial.print(pressDuration1);
          Serial.println(" milliseconds");
          // Serial.print("Button pressed for: ");
          SerialBT.print("Button pressed for: ");
          SerialBT.print(pressDuration1);
          SerialBT.println(" milliseconds");
          Rater();
          Serial.print("Counter :");
          Serial.println(led1Counter);
          delay(500); // debounce delay
          selectedLED = 1;
          break;
        }
      }
    }
    else
    {

      digitalWrite(PodeSlaveRLED, HIGH);
      while (true)
      {

        buttonState2 = digitalRead(PodeSlaveTS); // read the state of the pushbutton

        if (buttonState2 == HIGH)
        {                        // if button is pressed down
          startTime2 = millis(); // record the start time
          while (buttonState2 == HIGH)
          { // wait until button is released
            buttonState2 = digitalRead(PodeSlaveTS);
          }
          endTime2 = millis();                    // record the end time
          pressDuration2 = endTime2 - startTime2; // calculate the duration of button press
          digitalWrite(PodeSlaveRLED, LOW);
          led2Counter++;
          Serial.print("Button pressed for: ");
          Serial.print(pressDuration2);

          Serial.println(" milliseconds");
          SerialBT.print("Button pressed for: ");
          SerialBT.print(pressDuration2);
          SerialBT.println(" milliseconds");
          Rater();
          Serial.print("Counter :");
          Serial.println(led2Counter);
          delay(500); // debounce delay
          selectedLED = 0;
          break;
        }
      }
    }
    Serial.print("The Total Count:");
    Serial.println(led1Counter + led2Counter);
  }
  vTaskDelete(NULL); // Delete the task once done
}

void Start()
{

  if (Serial.available())
  {
    SerialBT.println("Please write s to start");
    delay(5000);
  }
  char incomingChar = SerialBT.read();
  if (incomingChar == 's')
  {
    SerialBT.println("Please Select the Mode");
    SerialBT.println("1 --> Main Mode");
    SerialBT.println("2 --> Rate Mode");
    waitblue();
    Mode = SerialBT.readStringUntil('\n');

    SerialBT.println("Please write countdown in this format MMSS 0530");
    waitblue();

    String RecievedTime = SerialBT.readStringUntil('\n');
    Serial.println(RecievedTime);
    if (isValidTimeString(RecievedTime))
    {

      stringToTime(RecievedTime, minutes, seconds);

      // Output the converted values
      Serial.print("Minutes: ");
      Serial.println(minutes);
      Serial.print("Seconds: ");
      Serial.println(seconds);
      GetReadyCounter();
      // countdownWithReadCounter(minutes, seconds);
      // PodeSelector();
      xTaskCreatePinnedToCore(
          countdownWithReadCounter, // Function to run on the core
          "countdownTask",          // Name of the task
          10000,                    // Stack size (bytes)
          NULL,                     // Parameter to pass to the function
          1,                        // Task priority
          //&countdownTask,           // Task handle
          NULL,
          0); // Core to run the task on

      xTaskCreatePinnedToCore(
          PodeSelector,       // Function to run on the core
          "podeSelectorTask", // Name of the task
          10000,              // Stack size (bytes)
          NULL,               // Parameter to pass to the function
          1,                  // Task priority
          // &podeSelectorTask,  // Task handle
          NULL,
          1);
    }
  }
  else
  {
    Serial.println("Invalid input string. It should consist of 4 numerical digits.");
  }

  waitblue();

  // Data is available, process it
}
void Timeout()
{
  StepsCounter = 0;
  led1Counter = 0;
  led2Counter = 0;
  buttonState1 = 0;   // variable for reading the pushbutton status
  startTime1 = 0;     // variable to store the time when the button is pressed
  endTime1 = 0;       // variable to store the time when the button is released
  pressDuration1 = 0; // variable to store the duration of button press

  buttonState2 = 0;   // variable for reading the pushbutton status
  startTime2 = 0;     // variable to store the time when the button is pressed
  endTime2 = 0;       // variable to store the time when the button is released
  pressDuration2 = 0; // variable to store the duration of button press
  Mode = '0';
  byte i = 5;
  while (i)
  {

    digitalWrite(PodeSlaveGLED, LOW);
    digitalWrite(PodeMasterGLED, LOW);
    delay(200);
    digitalWrite(PodeSlaveGLED, HIGH);
    digitalWrite(PodeMasterGLED, HIGH);
    delay(200);
    i--;
  }
}
void LEDsDefaultState()
{
  digitalWrite(PodeSlaveRLED, LOW);
  digitalWrite(PodeMasterRLED, LOW);
  digitalWrite(PodeSlaveGLED, LOW);
  digitalWrite(PodeMasterGLED, LOW);
}
void TestLEDs()

{

  while (TestLEDCounter)
  {
    digitalWrite(PodeSlaveGLED, HIGH);

    ;
    digitalWrite(PodeMasterGLED, HIGH);
    delay(200);
    digitalWrite(PodeSlaveGLED, LOW);

    digitalWrite(PodeMasterGLED, LOW);
    delay(200);
    TestLEDCounter--;
  }
}
// delay(20);
/*int time  = SerialBT.read();
int firstPart = time / 100; // Extract the first part (e.g., thousands)
int secondPart = time % 100;*/
void Rater()
{
  if (Mode.equals("2"))
    if (Game = 1)
    {

      if (160 >= pressDuration1 || 160 >= pressDuration2)
      {
        SerialBT.print("Excellent ");
      }
      else if (235 >= pressDuration1 && 160 < pressDuration1 || 235 >= pressDuration2 && 160 < pressDuration2)
      {
        SerialBT.println("Good");
      }
      else if (300 >= pressDuration1 && 235 < pressDuration1 || 300 >= pressDuration2 && 235 < pressDuration2)
      {
        SerialBT.println("bad");
      }
      else if (300 < pressDuration1 || 300 < pressDuration2)
      {
        SerialBT.println("You need practice reaction tranings  ");
      }
    }
    else if (Game = 2)
    {

      if (170 >= pressDuration1 || 170 >= pressDuration2)
      {
        SerialBT.println("Excellent ");
      }
      else if (235 >= pressDuration1 && 170 < pressDuration1 || 235 >= pressDuration2 && 170 < pressDuration2)
      {
        SerialBT.println("Good");
      }
      else if (300 >= pressDuration1 && 235 < pressDuration1 || 300 >= pressDuration2 && 235 < pressDuration2)
      {
        SerialBT.println("bad");
      }
      else if (300 < pressDuration1 || 300 < pressDuration2)
      {
        SerialBT.println("You need practice reaction tranings  ");
      }
    }

    else if (Game = 3)
    {

      if (180 >= pressDuration1 || 180 >= pressDuration2)
      {
        SerialBT.println("Excellent ");
      }
      else if (270 >= pressDuration1 && 180 < pressDuration1 || 270 >= pressDuration2 && 180 < pressDuration2)
      {
        SerialBT.println("Good");
      }
      else if (300 >= pressDuration1 && 235 < pressDuration1 || 300 >= pressDuration2 && 235 < pressDuration2)
      {
        SerialBT.println("bad");
      }
      else if (300 < pressDuration1 || 300 < pressDuration2)
      {
        SerialBT.println("You need to parctice rection traning ");
      }
    }
    else if (Game = 4)
    {
      if (190 >= pressDuration1 || 190 >= pressDuration2)
      {
        SerialBT.println("Excellent ");
      }
      else if (280 >= pressDuration1 && 190 < pressDuration1 || 280 >= pressDuration2 && 190 < pressDuration2)
      {
        SerialBT.println("Good");
      }
      else if (300 >= pressDuration1 && 280 < pressDuration1 || 300 >= pressDuration2 && 280 < pressDuration2)
      {
        SerialBT.println("bad");
      }
      else if (300 < pressDuration1 || 300 < pressDuration2)
      {
        SerialBT.println("You need to parctice rection traning ");
      }
    }
    // swimming
    else if (Game = 5)
    {
      if (180 >= pressDuration1 || 180 >= pressDuration2)
      {
        SerialBT.println("Excellent ");
      }
      else if (280 >= pressDuration1 && 180 < pressDuration1 || 280 >= pressDuration2 && 180 < pressDuration2)
      {
        SerialBT.print("Good");
      }
      else if (350 >= pressDuration1 && 280 < pressDuration1 || 350 >= pressDuration2 && 280 < pressDuration2)
      {
        SerialBT.println("bad");
      }
      else if (350 < pressDuration1 || 350 < pressDuration2)
      {
        SerialBT.println("You need to parctice rection traning ");
      }
    }
}
void Mode3(){
int PodLedSelect1=0;
int PodLedSelect2=0;

int selectorMode = random(20);
if (selectorMode % 2 ==0  )
{

for (int i = 0; i < selectorMode; i++)
{
  
}
}
if (PodLedSelect1=1)
{
  while (true)
      {

        buttonState1 = digitalRead(PodeMasterTS); // read the state of the pushbutton

        if (buttonState1 == HIGH)
        {                        // if button is pressed down
          startTime1 = millis(); // record the start time
          while (buttonState1 == HIGH)
          { // wait until button is released
            buttonState1 = digitalRead(PodeMasterTS);
          }
          endTime1 = millis();                    // record the end time
          pressDuration1 = endTime1 - startTime1; // calculate the duration of button press
          digitalWrite(PodeMasterRLED, LOW);
          led1Counter++;
          Serial.print("Button pressed for: ");
          Serial.print(pressDuration1);
          Serial.println(" milliseconds");
          // Serial.print("Button pressed for: ");
          SerialBT.print("Button pressed for: ");
          SerialBT.print(pressDuration1);
          SerialBT.println(" milliseconds");
          Rater();
          Serial.print("Counter :");
          Serial.println(led1Counter);
          delay(500); // debounce delay
     
          break;
        }
      }
}

else if (PodLedSelect2=1)
{
  while (true)
      {

        buttonState2 = digitalRead(PodeSlaveTS); // read the state of the pushbutton

        if (buttonState2 == HIGH)
        {                        // if button is pressed down
          startTime2 = millis(); // record the start time
          while (buttonState2 == HIGH)
          { // wait until button is released
            buttonState2 = digitalRead(PodeSlaveTS);
          }
          endTime2 = millis();                    // record the end time
          pressDuration2 = endTime2 - startTime2; // calculate the duration of button press
          digitalWrite(PodeSlaveRLED, LOW);
          led2Counter++;
          Serial.print("Button pressed for: ");
          Serial.print(pressDuration2);

          Serial.println(" milliseconds");
          SerialBT.print("Button pressed for: ");
          SerialBT.print(pressDuration2);
          SerialBT.println(" milliseconds");
          Rater();
          Serial.print("Counter :");
          Serial.println(led2Counter);
          delay(500); // debounce delay
       
          break;
        }
      }
}












}