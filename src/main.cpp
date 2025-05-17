#include "main.h"


void setup()
{
    systemSetup();
}

void loop()
{

}

void serialEvent(void)
{
  char command[15] = {0};
  printf("Enter command:\r\n");
  scanf("%15s", command);

  printf("%s\r\n", command);
  
  parsing(command);
}