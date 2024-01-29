#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void init() {
    alarm(60);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
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

void redactText(char *text, const char *placeholder, unsigned int index) {
    unsigned int textLength = strlen(text);
    unsigned int placeholderLength = strlen(placeholder);

    if (index > textLength - placeholderLength) {
        printf("Invalid index\n");
        exit(1);
    }

    for (unsigned int i = 0; i < placeholderLength; ++i) {
        text[index + i] = placeholder[i];
    }
}

void challenge(){
    char text[BUFFER_SIZE], placeholder[BUFFER_SIZE];
    unsigned int index;

    printf("Enter some text: ");
    fgets(text, BUFFER_SIZE, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter a placeholder: ");
    fgets(placeholder, BUFFER_SIZE, stdin);
    placeholder[strcspn(placeholder, "\n")] = 0; // Remove newline character

    printf("Enter the index of the stuff to redact: ");
    if (scanf("%u", &index) != 1) {
        printf("Failed to read index\n");
        return;
    }

    redactText(text, placeholder, index);
    printf("Redacted text: %s\n", text);
}

int main() {
    init();
    challenge();
    return 0;
}
