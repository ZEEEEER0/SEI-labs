#include "domofon.h"

static uint8_t needReset;
static uint32_t nextResetTime;
static int simbolIndex;

void domofon_setup()
{
    needReset = false;
    nextResetTime = 0;
    simbolIndex = 0;

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    own_stdio_setup();
    printf("Enter PIN\n");
}

void check_code(char *code)
{
    if (strcmp(code, ACCESS_CODE) == 0)
    {
        digitalWrite(LED_GREEN, HIGH);
        printf("\fAccess granted");

    }
    else
    {
        digitalWrite(LED_RED, HIGH);
        printf("\fAccess denied");

    }
    needReset = true;
    nextResetTime = millis() + RESET_TIME;  
}

void resetAccess(void)
{
    if (!needReset)
    {
        return;
    }
    else
    {
        if (millis() < nextResetTime)
        {
            return;
        }

        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
        needReset = false;
        printf("\fEnter PIN\n");
    }
}

void getCode(char ch)
{
    static char code[CODE_LENGTH] = {0};

    if (simbolIndex >= CODE_LENGTH - 1)
    {
        code[simbolIndex++] = ch;
        simbolIndex = 0;
        check_code(code);
    }
    else
    {
        code[simbolIndex++] = ch;
    }
}

void wasResetPress(const char ch)
{
    if (ch == RESET_KEY)
    {
        simbolIndex = 0;
        needReset = true;
        nextResetTime = 0;
        resetAccess();
        return;
    }
}

void domofon_loop()
{   
    char ch = 0;

    if (keypadGetState())
    {
        scanf("%c", &ch);
        if (!needReset) 
        {
            printf("*");
            getCode(ch);
        }
        wasResetPress(ch);
    }

    resetAccess();
}