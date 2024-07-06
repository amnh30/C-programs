#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

short ModeCount;
short CounterMin, CounterSec;

void Welcome();
void Selection();
void Modes();
void CountDown();
void TimeSelector();
int main()
{

  Welcome();

  return 0;
}

void Welcome()
{

  system("cls");
  printf("Hi Ahmed \n");
  Sleep(1000);
  printf("Please Select your Program");
  Sleep(500);
  system("cls");
  for (short i = 0; i < 10; i++)
  {
    if (i % 2 == 0)
      printf("%d   %d \n", i, i + 1);
    if (i == 9)
      printf("Chicken Mode\nBeef Mode \n");
  }
  Selection();
}

void Selection()
{

  char ProgSelect[1];
  scanf("%s", ProgSelect);

  if (0 == (strcmp(ProgSelect, "c") || 0 == strcmp(ProgSelect, "C")) || 0 == strcmp(ProgSelect, "Chicken"))
  {
    ModeCount = 1;

    Modes();
  }
  else if (0 == (strcmp(ProgSelect, "b") || 0 == strcmp(ProgSelect, "B")) || 0 == strcmp(ProgSelect, "Beef"))
  {
    ModeCount = 2;
    Modes();
  }
  else
  {
    TimeSelector();
  }
}
void Modes()
{
  char ProgSelect[1];
  /* printf("%d",ModeCount);*/
  system("cls");
  if (ModeCount == 1)
    printf("%02d:%02d\n", CounterMin = 36, CounterSec = 0);
  else if (ModeCount == 2)
    printf("%02d:%02d\n", CounterMin = 47, CounterSec = 0);

  printf("%s", ProgSelect);
  scanf("%s", ProgSelect);
  if (strcmp(ProgSelect, "s") == 0)
    CountDown();

  else if (strcmp(ProgSelect, "can") == 0)
    Welcome();
}
void CountDown()
{

  for (short Seccounter = CounterSec; Seccounter >= 0; Seccounter--)
  {

    printf("%02d:%02d\n", CounterMin, Seccounter);
    // system("cls");
    if (CounterMin == 0 && Seccounter == 0)
    {
      printf("Finished");
      break;
    }
    if (Seccounter == 00)
      Seccounter = 60, CounterMin--;
    // Sleep(1000);
  }
}
void TimeSelector()
{
  short TimeSelector;
  for (short i = 0; i < 4; i++)
  {
    scanf("%d", TimeSelector);
    
  }
  
  scanf("%d", TimeSelector);

}