typedef struct libraryStorage{
    char title[200]; // amr sonar bangla
    char author[100]; // rafiul omar
    char publishedDate[50];
    char edition[50]; // 2nd
    char bookCode[50]; // BD-2002-2nd-111

    int catagories;
    int searchId;

}storage;


void catagories(){

    printf( "\n1. History " );
    printf( "\n2. Historical Fiction " );
    printf( "\n3. Fiction " );
    printf( "\n4. Romance " );
    printf( "\n5. Biography " );
    printf( "\n6. Nonfiction " );
    printf( "\n7. Fantasy " );
    printf( "\n8. Science fiction " );
    printf( "\n9. Mystery " );
    printf( "\n10. Memoir " );
    printf( "\n11. Classics " );
    printf( "\n12. Children's literature " );
    printf( "\n13. Thriller " );
    printf( "\n14. Literary fiction " );
    printf( "\n15. Science " );
    printf( "\n16. Graphic novel " );
    printf( "\n17. True crime " );
    printf( "\n18. Adventure fiction " );
    printf( "\n19. Essay " );
    printf( "\n20. Short stories " );
    printf( "\n21. Autobiography " );
    printf( "\n22. Textbook " );
    printf( "\n23. Politics " );

    printf( "\n\nEnter ( 1-23 ) to add Catagories \n=>  " );

}


void catagoriesSelection( int type, char cata[] ){

    switch(type){

    case 1:
        strcpy( cata, "History" );
        break;
    case 2:
        strcpy( cata, "Historical Fiction" );
        break;
    case 3:
        strcpy( cata, "Fiction" );
        break;
    case 4:
        strcpy( cata, "Romance" );
        break;
    case 5:
        strcpy( cata, "Biography" );
        break;
    case 6:
        strcpy( cata, "Nonfiction" );
        break;
    case 7:
        strcpy( cata, "Fantasy" );
        break;
    case 8:
        strcpy( cata, "Science fiction" );
        break;
    case 9:
        strcpy( cata, "Mystery" );
        break;
    case 10:
        strcpy( cata, "Memoir" );
        break;
    case 11:
        strcpy( cata, "Classics" );
        break;
    case 12:
        strcpy( cata, "Children's literature" );
        break;
    case 13:
        strcpy( cata, "Thriller" );
        break;
    case 14:
        strcpy( cata, "Literary fiction" );
        break;
    case 15:
        strcpy( cata, "Science" );
        break;
    case 16:
        strcpy( cata, "Graphic novel" );
        break;
    case 17:
        strcpy( cata, "True crime" );
        break;
    case 18:
        strcpy( cata, "Adventure fiction" );
        break;
    case 19:
        strcpy( cata, "Essay" );
        break;
    case 20:
        strcpy( cata, "Short stories" );
        break;
    case 21:
        strcpy( cata, "Autobiography" );
        break;
    case 22:
        strcpy( cata, "Textbook" );
        break;
    case 23:
        strcpy( cata, "Politics" );
        break;
    default:
        strcpy( cata, "None" );
    }
}

void view(){

    storage st;
    FILE *fp = fopen( "records.txt", "r" );

    printf( "\n%6s|\t%35s|\t%20s|\t%10s|\t%25s|\t%10s|\t%5s\n", "ID", "Title", "Author", "Edition", "Catagories", "Published date","Code" );
    printf( "\n%6s-\t%35s-\t%20s-\t%10s-\t%25s-\t%10s-\t%5s\n\n", "--", "-----", "------", "-------", "----------", "--------------","--------" );

    int book_count = 0;
    while( fread(&st, sizeof(storage), 1, fp ) ) {

        char catagories[50];

        catagoriesSelection( st.catagories, catagories );


        printf( "%6d|\t%35s|\t%20s|\t%10s|\t%25s|\t%10s|\t%5s\n", st.searchId, st.title, st.author, st.edition, catagories, st.publishedDate, st.bookCode );

        book_count++;
    }

    printf("\n\n\t\t\t\tTotal number of book = %d\n\n\n", book_count );

    fclose( fp );
}


void add() {

    FILE *fp;
    int size = 0;

    printf( "How many books do you want to add: " );
    scanf( "%d", &size );

    storage st[size];

    fp = fopen( "records.txt", "a" );

    for( int i = 0; i < size; i++ ) {
        system("cls");
        printf( "\nEnter (%d) no Book title \n=>  ", i+1 );
        scanf( " %[^\n]s", st[i].title );

        printf( "\nEnter  Author name of \"%s\" \n=>  ", st[i].title );
        scanf( " %[^\n]s", st[i].author );

        printf( "\nEnter edition of \"%s\" \n=>  ", st[i].title );
        scanf( " %[^\n]s", st[i].edition );

        printf( "\nEnter book code  of \"%s\" \n=>  ", st[i].title );
        scanf( " %[^\n]s", st[i].bookCode );

        printf( "\nEnter published date of \"%s\" \n=>  ", st[i].title );
        scanf( " %[^\n]s", st[i].publishedDate );

        catagories();
        scanf( "%d", &st[i].catagories );

        printf( "\nMake a id for this book \n=>  " );
        scanf( "%d", &st[i].searchId );

        fwrite( &st[i], sizeof(storage), 1, fp );
    }

    fclose( fp );

}

void del(){

    storage st;
    FILE *fp, *fp1;

    fp = fopen("records.txt", "r");
    fp1 = fopen("temp.txt", "w");

    int id, found = 0;
    printf("Enter Id to delete: ");
    scanf("%d", &id);
    while(fread(&st, sizeof(storage), 1, fp)){
        if(st.searchId == id){
            found = 1;
        }else
            fwrite(&st, sizeof(storage), 1, fp1);
    }

    fclose(fp);
    fclose(fp1);



    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("records.txt", "w");

        while(fread(&st, sizeof(storage), 1, fp1)){
            fwrite(&st, sizeof(storage), 1, fp);
        }

        printf("\nId: %d deleted permanently\n", id);

        fclose(fp1);
        fclose(fp);
    }else{
        printf("\nRecord not found!\n");
    }

}

void find(){

    storage st;
    FILE *fp = fopen("records.txt", "r");

    int id, found = 0;

    printf("Enter account Id to search: ");
    scanf("%d", &id);

    printf( "\n%6s|\t%35s|\t%20s|\t%10s|\t%25s|\t%10s|\t%5s\n", "ID", "Title", "Author", "Edition", "Catagories", "Published date","Code" );
    printf( "\n%6s-\t%35s-\t%20s-\t%10s-\t%25s-\t%10s-\t%5s\n\n", "--", "-----", "------", "-------", "----------", "--------------","--------" );

    while(fread(&st, sizeof(storage), 1, fp)){
        if(st.searchId == id){
            found = 1;
            char catagories[50];

            catagoriesSelection( st.catagories, catagories );
            printf( "%6d|\t%35s|\t%20s|\t%10s|\t%25s|\t%10s|\t%5s\n", st.searchId, st.title, st.author, st.edition, catagories, st.publishedDate, st.bookCode );

        }
    }

    if(!found){
        system("cls");
        printf("\n Id: %d, Not Found\n", id);
    }

    fclose(fp);

}

void update(){
    storage st;
    FILE *fp, *fp1;
    fp = fopen("records.txt", "r");
    fp1 = fopen("temp.txt", "w");

    int id, found = 0;
    printf("Enter Id to update: ");
    scanf("%d", &id);

    while(fread(&st, sizeof(storage), 1, fp)){
        if(st.searchId == id){
            found = 1;

            system("cls");
            printf( "\nEnter Book title \n=>  " );
            scanf( " %[^\n]s", st.title );

            printf( "\nEnter  Author name of \"%s\" \n=>  ", st.title );
            scanf( " %[^\n]s", st.author );

            printf( "\nEnter edition of \"%s\" \n=>  ", st.title );
            scanf( " %[^\n]s", st.edition );

            printf( "\nEnter book code  of \"%s\" \n=>  ", st.title );
            scanf( " %[^\n]s", st.bookCode );

            printf( "\nEnter published date of \"%s\" \n=>  ", st.title );
            scanf( " %[^\n]s", st.publishedDate );

            catagories();
            scanf( "%d", &st.catagories );
        }

        fwrite(&st, sizeof(storage), 1, fp1);
    }

    fclose(fp);
    fclose(fp1);

    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("records.txt", "w");

        while(fread(&st, sizeof(storage), 1, fp1)){
            fwrite(&st, sizeof(storage), 1, fp);
        }

        fclose(fp);
        fclose(fp1);
    }else{
        printf("\nRecord not found!\n");
    }
}


