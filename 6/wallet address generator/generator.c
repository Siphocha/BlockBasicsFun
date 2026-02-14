#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void simulate_hash(const char *input, char *output) {
    unsigned long hash = 5381;
    int c;
    const char *temp = input;
    while ((c = *temp++)) {
        hash = ((hash << 5) + hash) + c;
    }
    sprintf(output, "0x%08lx%08lx%08lx", hash, hash ^ 0xFA2B3C4D, hash << 2);
}

void generate_random_key(char *key, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < len; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[len] = '\0';
}

int main() {
    char command[20];
    char current_address[65] = "No address generated yet!!!";
    char mock_public_key[32];
    
    srand(time(NULL));

    while (1) {
        printf("\nCommands: generate, show, exit\n> ");
        if (scanf("%19s", command) != 1) break;

        if (strcmp(command, "generate") == 0) {
            generate_random_key(mock_public_key, 16);
            simulate_hash(mock_public_key, current_address);
            printf("Success! New wallet address generated.\n");
        } 
        else if (strcmp(command, "show") == 0) {
            printf("Current Wallet Address is: %s\n", current_address);
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } 
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}