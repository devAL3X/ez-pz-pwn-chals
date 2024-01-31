#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void init() {
    alarm(60);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

void read_n(char *buf, int n) {
    int i;
    for (i = 0; i < n; i++) {
        buf[i] = getchar();
        if (buf[i] == '\n') 
            return;
    }
}

void win(){
    asm("pop %rax"); // костыль
    puts("You win!");
    char flag[100];
    FILE *f = fopen("flag.txt","r");
    if (f == NULL) {
        printf("Flag File is Missing.\n");
        exit(0);
    }
    fgets(flag, 100, f);
    printf("%s\n", flag);
    fclose(f);
    exit(0);
}

struct Order {
    char name[0x20];
    char pizza[0x20];
    int more_cheese;
    int add_pineapple;
    int price;
    char address[40];
};

void challenge(){
    puts("Welcome to pizzeria! 🇮🇹");

    puts("Wanna order some pizza? 🍕");
    puts("1. Yes");
    puts("2. Yes, but next time");

    int choice;
    scanf("%d%*c", &choice);
    putchar('\n');
    
    if (choice != 1) {
        puts("Bye!");
        return;
    }

    struct Order order;

    puts("What's your name?");
    read_n(order.name, 0x20);
    putchar('\n');

    puts("What pizza do you want?");
    read_n(order.pizza, 0x20);
    putchar('\n');

    puts("Do you want more cheese? 🧀");
    puts("1. Yes");
    puts("2. No");
    scanf("%d%*c", &choice);
    putchar('\n');
    

    if (choice == 1) {
        order.more_cheese = 1;
    } else {
        order.more_cheese = 0;
    }

    puts("Do you want to add pineapple? 🍍");
    puts("1. Yes");
    puts("2. No");
    scanf("%d%*c", &choice);


    if (choice == 1) {
        order.add_pineapple = 1;
        puts("Realy? 🤢");
    } else {
        order.add_pineapple = 0;
    }
    putchar('\n');

    puts("Do you need delivery? 🛵");
    puts("1. Yes");
    puts("2. No");
    scanf("%d%*c", &choice);
    putchar('\n');

    if (choice == 1) {
        puts("What's your address?");
        read_n(order.address, 0x40);
        printf("Did I get your address right? %s\n", order.address);

        puts("1. Yes");
        puts("2. No");
        scanf("%d%*c", &choice);
        putchar('\n');
        
        if (choice == 1) {
            puts("Ok. Wait for your delivery");
        } else {
            puts("Ok. I'll ask you again");
            puts("What's your address?");
            read_n(order.address, 0x40);
            puts("Oh I see. Wait for your delivery");
        }
    } else {
        puts("Ok, you can take your pizza in 15 minutes");
    }
}

int main(){
    init();
    challenge();
    return 0;
}