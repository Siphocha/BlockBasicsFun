
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>

void print_hash(unsigned char *hash, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Unable to open file");
        return 1;
    }

    // 1. Initialize the context
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    const EVP_MD *md = EVP_sha256(); // We are using SHA-256 for blockchain tasks
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    EVP_DigestInit_ex(mdctx, md, NULL);

    // 2. Read file in chunks and update the hash
    unsigned char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        EVP_DigestUpdate(mdctx, buffer, bytesRead);
    }

    // 3. Finalize the hash
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);

    // Clean up
    EVP_MD_CTX_free(mdctx);
    fclose(file);

    printf("SHA-256 Hash of %s: \n", argv[1]);
    print_hash(hash, hash_len);

    return 0;
}