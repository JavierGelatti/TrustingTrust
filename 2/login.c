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

int main(int argc, string argv[]) {
    if (argc < 3) {
        printf("Argumentos insuficientes\n");
        exit(1);
    }

    string usr = argv[1];
    string pwd = argv[2];

    account systemAccounts[] = {
        { .usr = "javier", .pwd = "1342" },
        { .usr = "diego",  .pwd = "Ho1A" },
        { .usr = "flor",   .pwd = "@5sQ" },
        { .usr = "franco", .pwd = "eldt" }
    };

    if (authorized(systemAccounts, usr, pwd)) {
        printf("Inició sesión %s\n", usr);
    } else {
        printf("Acceso rechazado.\n");
    }
}
