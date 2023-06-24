#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <unistd.h>

#include "menu.h"
#include "login.h"
#include "splash.h"

int main() {

    char name[50];
    char pass[50];
    char any[20];

    splachScreen ();

    point:
    system("cls");
    title();

    printf( "\n\nEnter username: " );
    scanf( " %[^\n]s", name );

    printf( "\nEnter pass: " );
    scanf( " %[^\n]s", pass );

    if( loginAccess( name, pass ) == 1 ) {
        menu();
    }
    else if( loginAccess( name, pass ) == -1 ) {
        printf( "\nPassword is invalid! Press any key to continue: " );
        scanf(" %[^\n]s", any);
        goto point;
    }
    else if( loginAccess( name, pass ) == -2 ) {
        printf( "\nUser name is invalid! Press any key to continue: " );
        scanf( " %[^\n]s", any);
        goto point;
    }
    else {
        printf( "\nBoth user name & password is invalid! Press any key to continue: " );
        scanf( " %[^\n]s", any);
        goto point;
    }

    return 0;
}


