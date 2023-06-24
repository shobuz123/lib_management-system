#define USER "admin"
#define password "admin"

int loginAccess( char name[], char pass[] ) {
    if( !strcmp( name, USER ) == 1 && !strcmp( pass, password ) == 1 ) return 1;
    else if( !strcmp( name, USER ) == 1  && !strcmp( pass, password ) != 1 ) return -1;
    else if( !strcmp( name, USER ) != 1  && !strcmp( pass, password ) == 1 ) return -2;
    else return 0;
}


