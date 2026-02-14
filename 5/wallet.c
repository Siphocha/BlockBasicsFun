#include <stdio.h>
#include <string.h>

struct Wallet{
    int id;
    char owner[50];
    int balance;
    int address;
    char publickey[50];
    char privkey[50];
};

void createWallet(struct Wallet *wallet, int id, int *balance){
    wallet->id = id;
    wallet->balance = balance;

    


}

int main(){

}