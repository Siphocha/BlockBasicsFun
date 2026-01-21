#include <stdio.h>
#include <string.h>

struct Block {
    int index;
    char data[100];
    char previousHash[100];
    char hash[100];
};

void createBlock(struct Block *block, int index, char *data, char *prevHash) {
    block->index = index;
    strcpy(block->data, data);
    strcpy(block->previousHash, prevHash);

    // Simple hash simulation
    sprintf(block->hash, "HASH_%d", index);
}

int main() {
    struct Block blockchain[3];

    // Genesis Block
    createBlock(&blockchain[0], 0, "Genesis Block", "0");

    // Block 1
    createBlock(&blockchain[1], 1, "Transaction Data 1", blockchain[0].hash);

    // Block 2
    createBlock(&blockchain[2], 2, "Transaction Data 2", blockchain[1].hash);

    // Display blocks
    for (int i = 0; i < 3; i++) {
        printf("Block %d\n", blockchain[i].index);
        printf("Data: %s\n", blockchain[i].data);
        printf("Previous Hash: %s\n", blockchain[i].previousHash);
        printf("Hash: %s\n\n", blockchain[i].hash);
    }

    return 0;
}