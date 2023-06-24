#include "database.h"

int menu(){

    int n;
    char any[20];

    point:
    system("cls");
    title();

    printf("\n1. Add books\n\n");
    printf("2. Show books\n\n");
    printf("3. Delete books\n\n");
    printf("4. Edits books\n\n");
    printf("5. Search books\n\n");
    printf("6. exit\n\n\n");
    printf("\n=>  ");

    scanf("%d", &n);

    switch(n){

    case 1:
        system("cls");
        title();
        add();
        printf("\nPress any key to continue ...\n=>  ");
        scanf(" %[^\n]s", any);
        menu();
        break;

    case 2:
        system("cls");
        title();
        view();
        printf("\nPress any key to continue ...\n=>  ");
        scanf(" %[^\n]s", any);
        menu();
        break;

    case 3:
        system("cls");
        title();
        del();
        printf("\nPress any key to continue ...\n=>  ");
        scanf(" %[^\n]s", any);
        menu();
        break;

    case 4:
        system("cls");
        title();
        update();
        printf("\nPress any key to continue ...\n=>  ");
        scanf(" %[^\n]s", any);
        menu();
        break;

    case 5:
        system("cls");
        title();
        find();
        printf("\nPress any key to continue ...\n=>  ");
        scanf(" %[^\n]s", any);
        menu();
        break;

    case 6:
        return 0;
        break;

    default:
        goto point;
    }
}


