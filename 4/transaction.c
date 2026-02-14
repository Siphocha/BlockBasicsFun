#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint64_t simple_hash(const char *input, uint32_t nonce) {
    uint64_t hash = 5381;
    int c;
    char buffer[256];
    
    sprintf(buffer, "%s%u", input, nonce);
    
    char *ptr = buffer;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void mine_block(char *transaction, int difficulty) {
    uint32_t nonce = 0;
    uint64_t hash;
    uint64_t target = 1ULL << (64 - difficulty);

    printf("Mining transaction: %s\n", transaction);
    printf("Target threshold: %llu\n", target);

    do {
        nonce++;
        hash = simple_hash(transaction, nonce);
    } while (hash >= target);

    printf("Block has been Mined!\n");
    printf("Number used only once (Nunce): %u\n", nonce);
    printf("Hash: %llx\n", hash);
}

int main() {
    char transaction[] = "Sipho is sending ETH to Tesi! 100 ETH";
    int difficulty = 16; 

    mine_block(transaction, difficulty);

    return 0;
}