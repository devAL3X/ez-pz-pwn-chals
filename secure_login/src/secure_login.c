#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char password[64];

void init() {
    alarm(60);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

void print_flag(){
    char flag[100];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL) {
        puts("Flag file not found!");
        exit(0);
    }
    fgets(flag, 100, f);
    printf("%s", flag);
    fclose(f);
}

void gen_pass() {
        FILE *file = fopen("/dev/urandom","r");
        fgets(password, 64, file);
        fclose(file);
}

void main() {
    init();
    puts("Welcome to ultra secure login service!");

    gen_pass();

    char input[64];
    printf("Enter the password: ");
    fgets(input, 64, stdin);

    if (strcmp(input, password) == 0) {
            print_flag();
    } else {
            puts("Wrong!");
    }
}
