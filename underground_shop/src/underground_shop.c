#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void init() {
    alarm(60);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

void print_menu(){
    puts("1. Cucmber 🥒 - 100 BC");
    puts("2. Carrot 🥕 - 200 BC");
    puts("3. Potato 🥔 - 50 BC");
    puts("4. Garlic 🧄 - 322 BC");
    puts("5. Flag 🚩 - 1337 BC");
    puts("0. Exit");
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

int main(){
    init();

    __uint16_t balance = 1000;

    puts("Welcome to the underground shop!");
    puts("You can buy following items, if you have enough BC (Bipka Coins):");
    printf("Your balance: %d BC\n", balance);

    while(1) {
        print_menu();    
        printf("Enter item number: ");
        __uint8_t item;
        scanf("%hhu", &item);

        switch(item) {
            case 1:
                balance -= 100;
                puts("You bought cucumber!");
                break;
            case 2:
                balance -= 200;
                puts("You bought carrot!");
                break;
            case 3:
                balance -= 50;
                puts("You bought potato!");
                break;
            case 4:
                balance -= 322;
                puts("You bought garlic!");
                break;
            case 5:
                if (balance < 1337) {
                    puts("You don't have enough BC! Sorry :(");
                    break;
                }
                puts("Coungrats! You bought the flag!");
                print_flag();
                break;
            case 0:
                puts("Bye!");
                exit(0);
            default:
                puts("Invalid item number!");
                break;
        }

        if (balance < 0) {
            puts("You don't have enough BC!");
            exit(0);
        }

        printf("Your balance: %d BC\n\n", balance);
    }
}
