#include <stdio.h>
#include <string.h>
#include "Book.h"
#include "Splash.h"

void menu(void)
{
    int choice;
    int acc;
    splashScreen();
    system("color 2F");
    nametag();
    login();
    puts("\tWhat would you like to do?");
    puts("	1. Book Apartment");
    puts("	2. Login as administrator");
    puts("	3. Exit program");

    printf("\nEnter a choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        book();
        break;
    }
    case 2:
    {
        system("color 1F");
        acc = Access();
        if (acc == 1)
            adminpermit();
        else
        {
            getchar();
            menu();
        }
        break;
    }

    case 3:
    {
        nametag();
        system("color 80");
        puts("\n\n\n\n\n\n\t\tTHANK YOU");
        puts("\n\t\tFOR CHOOSING PROPERTY BD");
        puts("\n\t\t^-^");
        getchar();
        exit(0);
    }
    }
}
