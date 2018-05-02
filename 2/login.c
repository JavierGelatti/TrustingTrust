#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_ACC 4

typedef char* string;
typedef struct {
    string usr, pwd;
} account;

account accounts[NUM_ACC];

bool equals(string a, string b) {
    return strcmp(a, b) == 0;
}

bool authorized(account accounts[], string usr, string pwd) {
    for (int i = 0; i < NUM_ACC; i++) {
        account a = accounts[i];
        if (equals(usr, a.usr) && equals(pwd, a.pwd)) {
            return true;
        }
    }
    return false;
}

void show(string message) {
    printf("%s\n", message);
}

int main(int argc, string argv[]) {
    if (argc < 3) {
        show("Argumentos insuficientes");
        exit(1);
    }

    string usr = argv[1];
    string pwd = argv[2];

    account systemAccounts[] = {
        { .usr = "javier", .pwd = "1234" },
        { .usr = "diego",  .pwd = "1111" },
        { .usr = "flor",   .pwd = "0000" },
        { .usr = "franco", .pwd = "eldt" }
    };

    if (authorized(systemAccounts, usr, pwd)) {
        show("Autorizado :)");
    } else {
        show("Acceso rechazado.");
    }
}
