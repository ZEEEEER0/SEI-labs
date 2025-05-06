#include "interpreter.h"    

const char *commands[] = {
    "relay on",
    "relay off",
    "relay toggle",
    "relay set",
    "relay get",
    "relay status",
    "help"
};

const char *responses[] = {
    "Relay turned on",
    "Relay turned off",
    "Relay toggled",
    "Set command executed",
    "Get command executed",
    "Status command executed",
    "Help command executed"
};

const char *error_mesages[] = {
    "Error: Invalid command",
    "Error: Invalid parameters",
    "Error: Command not found",
    "Error: Unknown error",
    "Relay already on",
    "Relay already off",
};

const char *help_message = "Available commands:\n"
                            "1. relay on\n"
                            "2. relay off\n"
                            "3. relay toggle\n"
                            "4. relay set <parameter>\n"
                            "5. relay get <parameter>\n"
                            "6. relay status\n";
    uint8_t command = INVALID_COMMAND; // Declare 'command' with an appropriate type



const char *get_command_string(uint8_t command) {
    if (command < sizeof(commands) / sizeof(commands[0])) {
        return commands[command];
    } else {
        return NULL; // Invalid command
    }
}

void (*command_handlers[])(lightbulb_t *) = {
    lightbulb_on,
    lightbulb_off,
    lightbulb_toggle,
    NULL, // "relay set" command handler not implemented
};

lightbulb_t *lightbulb; // Global lightbulb object

void interpreter_init(lightbulb_t *main_lightbulb) {
    command = NULL;
    lightbulb = main_lightbulb; // Initialize the global lightbulb object

    printf("Instructions:\n");
    printf("1. Type 'help' to see available commands.\n");
    printf("Enter command: ");
}

void interpreter_loop(void) {
    char input [20];
    printf("Enter command: ");
    scanf("%19s", input); 

}

void interpreter_process_command(const char *input) {
    for (size_t i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        if (strcmp(input, commands[i]) == 0) {
            printf("%s\n", responses[i]); // Print the corresponding response
            if (command_handlers[i] != NULL) {
                command_handlers[i](lightbulb); // Call the corresponding command handler
            }
            return;
        }
    }
    printf("Error: Command not found\n"); // Print an error if the command is not found
}

void interpreter_loop(void) {
    char input[20];
    printf("Enter command: ");
    scanf("%19s", input); // Read the next command from the user
    interpreter_process_command(input); // Process the new command
}

