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

    // flag: 

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
                if (balance < 100) {
                    puts("You don't have enough BC! Sorry :(");
                    break;
                }
                puts("How many cucumbers do you want to buy?");
                __uint16_t count;
                scanf("%hu", &count);
                balance -= count * 100;
                printf("You bought %hu cucumbers!\n", count);
                break;
            case 2:
                if (balance < 200) {
                    puts("You don't have enough BC! Sorry :(");
                    break;
                }
                puts("How many carrots do you want to buy?");
                scanf("%hu", &count);
                balance -= count * 200;
                printf("You bought %hu carrots!\n", count);
                break;
            case 3:
                if (balance < 50) {
                    puts("You don't have enough BC! Sorry :(");
                    break;
                }
                puts("How many potatoes do you want to buy?");
                scanf("%hu", &count);
                balance -= count * 50;
                printf("You bought %hu potatoes!\n", count);
                break;
            
            case 4:
                if (balance < 322) {
                    puts("You don't have enough BC! Sorry :(");
                    break;
                }
                puts("How many garlics do you want to buy?");
                scanf("%hu", &count);
                balance -= count * 322;
                printf("You bought %hu garlics!\n", count);
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

        printf("Your balance: %d BC\n", balance);
    }
}
