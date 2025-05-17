#include "my_tasks.h"

void systemSetup()
{
    own_stdio_setup();
    printf("Sistem Started!\r\n");
}

bool redRelayControl(const char *command)
{
    if (!strcmp(command, "red"))
    {
        red.control(TOGGLE);
        printf("red status: %d\r\n", red.getState());
        return 1;
    }
    else if (!strcmp(command, "red_state"))
    {
        printf("red status: %d\r\n", red.getState());
        return 1;
    }
    return 0;
}

bool greenRelayControl(const char *command)
{
    if (!strcmp(command, "green"))
    {
        green.control(TOGGLE);
        printf("green status: %d\r\n", green.getState());
        return 1;
    }
    else if (!strcmp(command, "green_state"))
    {
        printf("green status: %d\r\n", green.getState());
        return 1;
    }
    return 0;
}

bool blueRelayControl(const char *command)
{
    if (!strcmp(command, "blue"))
    {
        blue.control(TOGGLE);
        printf("blue status: %d\r\n", blue.getState());
        return 1;
    }
    else if (!strcmp(command, "blue_state"))
    {
        printf("blue status: %d\r\n", blue.getState());
        return 1;
    }
    return 0;
}   

void getHelp(void)
{
  printf("Available commands:\r\n");
  printf("```General```\r\n");
  printf("sys_state: show all relay state\r\n");
  printf("```Red```\r\n");
  printf("red: Toggle red relay\r\n");
  printf("red_state: Get red relay state\r\n");
  printf("```Green```\r\n");
  printf("green: Toggle green relay\r\n");
  printf("green_state: Get green relay status\r\n");
  printf("```Blue```\r\n");
  printf("blue: Toggle blue relay\r\n");
  printf("blue_state: Get blue relay status\r\n");
  printf("```End```\r\n");
}

void parsing(const char *command)
{
    static bool err1 = 0;
    static bool err2 = 0;
    static bool err3 = 0;

    err1 = redRelayControl(command);
    err2 = greenRelayControl(command);
    err3 = blueRelayControl(command);

    if (!strcmp(command, "help"))
    {
        getHelp();
    }
    else if (!strcmp(command, "sys_state"))
    {
        redRelayControl("red_state");
        greenRelayControl("green_state");
        blueRelayControl("blue_state");
    }
    else if (err1 && err2 && err3)
    {
        printf("Unknown command. Type 'help' for a list of available commands.\r\n");
    }
}