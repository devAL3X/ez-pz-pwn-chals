#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void init() {
    alarm(60);
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

void print_menu(){
    puts("======== menu ========");
    puts("1. register");
    puts("2. login");
    puts("3. admin panel");
    puts("4. change password");
    puts("0. exit");
}

struct user
{
    int is_admin;
    char name[20];
    char password[20];
};

struct user USERS[10];
struct user *current_user = NULL;

void register_user(){
    for(int i=0; i < sizeof(USERS) / sizeof(*USERS); i++){
        if(USERS[i].name[0] == '\0'){
            printf("name: ");
            scanf("%19s", USERS[i].name);
            printf("password: ");
            scanf("%19s", USERS[i].password);
            USERS[i].is_admin = 0;
            current_user = &USERS[i];
            printf("Registered successful as %s\n", current_user->name);
            return;
        }
    }
    puts("users limit exceeded");
}

void login(){
    char name[20];
    char password[20];
    printf("name: ");
    scanf("%19s", name);
    printf("password: ");
    scanf("%19s", password);
    for(int i=0; i < sizeof(USERS) / sizeof(*USERS); i++){
        if(strcmp(USERS[i].name, name) == 0 && strcmp(USERS[i].password, password) == 0){
            current_user = &USERS[i];
            printf("Logged in successful as %s\n", current_user->name);
            return;
        }
    }
    puts("login failed");
}

void admin_panel(){
    if(current_user == NULL){
        puts("login first");
        return;
    }
    if(current_user->is_admin == 0){
        puts("you are not admin");
        return;
    }
    puts("welcome, admin!");
    FILE *f = fopen("flag.txt", "r");
    if(f == NULL){
        puts("flag not found");
        return;
    }
    char flag[100];
    fgets(flag, sizeof(flag), f);
    printf("here is your flag: %s\n", flag);
    fclose(f);
}

void change_password(){
    if(current_user == NULL){
        puts("login first");
        return;
    }
    // confirm password
    char password[20];
    printf("current password: ");
    scanf("%s", password);
    if(strcmp(current_user->password, password) != 0){
        puts("wrong password");
        return;
    }

    printf("new password: ");
    scanf("%s", current_user->password);
    puts("password changed");
}

int main(){
    init();

    while(1){
        print_menu();
        printf("> ");
        int choice;
        scanf("%d", &choice);
        switch (choice){
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            case 3:
                admin_panel();
                break;
            case 4:
                change_password();
                break;
            case 0:
                puts("bye");
                exit(0);
            default:
                puts("invalid choice");
                break;
        }
    }
    return 0;
}
