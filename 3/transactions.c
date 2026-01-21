#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define NAME_LEN  50

// User account structure
typedef struct {
    char name[NAME_LEN];
    double balance;
} Account;

// Find user index by name
int findUser(Account users[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Transfer funds between users
void transfer(Account users[], int count) {
    char senderName[NAME_LEN], receiverName[NAME_LEN];
    double amount;

    printf("Sender name: ");
    scanf("%s", senderName);

    printf("Receiver name: ");
    scanf("%s", receiverName);

    printf("Amount to transfer: ");
    scanf("%lf", &amount);

    int sender = findUser(users, count, senderName);
    int receiver = findUser(users, count, receiverName);

    if (sender == -1 || receiver == -1) {
        printf("❌ User not found.\n");
        return;
    }

    if (users[sender].balance < amount) {
        printf("❌ Insufficient balance.\n");
        return;
    }

    users[sender].balance -= amount;
    users[receiver].balance += amount;

    printf("Transaction IS SUCCESSFUL!\n");
}

// Display all accounts
void displayAccounts(Account users[], int count) {
    printf("\n--- ETH Account Balances ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", users[i].name, users[i].balance);
    }
}

int main() {
    Account users[MAX_USERS] = {
        {"Henry", 10000.0},
        {"Sipho", 55500.0},
        {"Tesi", 30.0}
    };

    int userCount = 3;
    int choice;

    do {
        printf("\n=== Blockchain Transaction Simulator ===\n");
        printf("1.Viewing accounts\n");
        printf("2.Sending funds\n");
        printf("0.Exiting\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAccounts(users, userCount);
                break;
            case 2:
                transfer(users, userCount);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 0);

    return 0;
}
