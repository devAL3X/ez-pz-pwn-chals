#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void init() {
    alarm(60);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

int main(){
    init();
    char name[64];
    char flag[64];

    FILE *f = fopen("flag.txt", "r");
    if (f == NULL) {
        puts("flag.txt not found!");
        exit(1);
    }
    fgets(flag, sizeof(flag), f);
    fclose(f);

    printf("What's your name?\n");
    scanf("%63s", name);
    getchar(); // eat \n

    puts("According to al3x research, the average person can make a one-letter typo even in their own name.");
    puts("Do you want to fix typo? (y/n) ");
    char c = getchar();
    getchar(); // eat \n

    if (c == 'y') {
        puts("enter index of letter to fix: ");
        int idx;
        scanf("%d", &idx);
        getchar(); // eat \n
        if (idx < 0 || idx > sizeof(name)) {
            puts("nonono, you're trying to exploit me!");
            exit(1);
        }
        puts("enter correct letter: ");
        char letter = getchar();
        getchar(); // eat \n
        name[idx] = letter;
    } else if (c == 'n') {
        puts("Okay, I'll use the name you entered first.");
    } else {
        puts("Damn, you're realy not good at typing.");
        exit(1);
    }

    printf("Hello, %s!\n", name);
    return 0;
}
