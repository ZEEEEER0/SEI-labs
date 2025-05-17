#include "my_tasks.h"

// --- Configurare pini L298 ---
#define L298_IN1 7
#define L298_IN2 6
#define L298_EN  5

static int8_t motor_power = 0; // [-100, 100]
static int8_t last_reported_power = -127;

void motorSetup(void) {
    motor.stop();
}

static void motorApply(int8_t power) {
    power = constrain(power, -100, 100);
    if (power == 0) {
        digitalWrite(L298_IN1, LOW);
        digitalWrite(L298_IN2, LOW);
        analogWrite(L298_EN, 0);
    } else if (power > 0) {
        digitalWrite(L298_IN1, HIGH);
        digitalWrite(L298_IN2, LOW);
        analogWrite(L298_EN, map(power, 0, 100, 0, 255));
    } else {
        digitalWrite(L298_IN1, LOW);
        digitalWrite(L298_IN2, HIGH);
        analogWrite(L298_EN, map(-power, 0, 100, 0, 255));
    }
    motor_power = power;
}

void motorParseCommand(const char *command) {
    int val;
    if (sscanf(command, "motor set %d", &val) == 1) {
        val = constrain(val, -100, 100);
        motor.setPower(val); // Folosește driverul L298 corect
        printf("Motor set to %d%%\n", val);
    } else if (strcmp(command, "motor stop") == 0) {
        motor.stop();
        printf("Motor stopped\n");
    } else if (strcmp(command, "motor max") == 0) {
        int8_t cur = motor.getPower();
        if (cur >= 0)
            motor.setPower(100);
        else
            motor.setPower(-100);
        printf("Motor set to max (%d%%)\n", motor.getPower());
    } else if (strcmp(command, "motor inc") == 0) {
        int8_t cur = motor.getPower();
        int8_t new_power = cur + (cur >= 0 ? 10 : -10);
        if (cur == 0) new_power = 10;
        new_power = constrain(new_power, -100, 100);
        motor.setPower(new_power);
        printf("Motor increased to %d%%\n", motor.getPower());
    } else if (strcmp(command, "motor dec") == 0) {
        int8_t cur = motor.getPower();
        int8_t new_power = cur - (cur > 0 ? 10 : (cur < 0 ? -10 : 0));
        if (cur == 0) new_power = -10;
        new_power = constrain(new_power, -100, 100);
        if (cur > 0 && new_power < 0) new_power = 0;
        if (cur < 0 && new_power > 0) new_power = 0;
        motor.setPower(new_power);
        printf("Motor decreased to %d%%\n", motor.getPower());
    } else if (strcmp(command, "motor state") == 0) {
        motorReport();
    }
}

void motorReport(void) {
    printf("Motor: %s, Power: %d%%\n", motor.getDirection(), motor.getPower());
}

// --- Integrare cu sistemul existent ---

void systemSetup()
{
    own_stdio_setup();
    printf("Sistem Started!\n");
    motorSetup();
}

void getHelp(void)
{
  printf("Available commands:\n");
  printf("motor set [-100..100] : Set motor power and direction\n");
  printf("motor stop            : Stop motor\n");
  printf("motor max             : Set max power in current direction\n");
  printf("motor inc             : Increase power by 10%%\n");
  printf("motor dec             : Decrease power by 10%%\n");
  printf("motor state           : Show current motor state\n");
  printf("help                  : Show this help\n");
}

void parsing(const char *command)
{
    if (strncmp(command, "motor", 5) == 0) {
        motorParseCommand(command);
    } else if (!strcmp(command, "help")) {
        getHelp();
    } else {
        printf("Unknown command. Type 'help' for a list of available commands.\n");
    }
}