#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "Tag.h"

FILE *fp;

struct product
{
    char name[20];
    int size;
    int bhk;
    char location[50];
    int price;
    int code;
} p;

int Access()
{
    fflush(stdin);
    char admin[30];
    static char password[5];
    int a;
    printf("\n\t\t\tEnter Admin username: ");
    scanf("%s", &admin);
    if (strcmpi(admin, "masroor") == 0)
    {
        printf("\n\n\t\t\tWelcome %s!", admin);
        printf("\n\t\t\tEnter password: \n\t\t\t ");
        for (int i = 0; i < 5; i++)
        {
            password[i] = getch();
            if (password[i] == '\r')
            {
                break;
            }
            else
                printf("*");
        }
        if (strcmp(password, "12345") == 0)
        {
            puts("\a\n\n\n\t\t\tACCESS GRANTED");
            getch();
            a = 1;
        }
        else
        {
            puts("\a\n\n\n\t\t\tACCESS DENIED!");
            a = 0;
        }
    }
    else
    {
        nametag();
        puts("\n\n\n\t\t\tUNKNOWN IDENTITY");
        a = 0;
    }
    return a;
}

void Update(void)
{
    system("cls");
    char c = 'y';
    fp = fopen("shopdatabase.txt", "w");
    printf("Current Selection: Addition of new property\n");
    char name[20];
    char location[50];
    while (c == 'y')
    {
        fflush(stdin);
        printf("Code: ");
        scanf("%d", &p.code);
        printf("\nName of property: ");
        scanf(" %s", name);
        strcpy(p.name, name);
        printf("\nSize : ");
        scanf("%d", &p.size);
        printf("\nBHK : ");
        scanf("%d", &p.bhk);
        printf("Loaction : ");
        scanf(" %s", location);
        strcpy(p.location, location);
        printf("Price (Tk.) : ");
        scanf("%d", &p.price);
        fwrite(&p, sizeof(struct product), 1, fp);
        printf("\n\nEnter 'y' to add another property or any other key to end process : ");
        scanf(" %c", &c);
    }
    printf("\nPress any key to return to previous menu...\n");
    getchar();

    fclose(fp);
    adminpermit();
}

void View(void)
{

        FILE *fp = fopen("shopdatabase.txt", "r");
        if (fp == NULL)
        {
            printf("Error opening the file.\n");
            return 1;
        }

        struct product p;

        while (fread(&p, sizeof(struct product), 1, fp) == 1)
        {
            printf("Name: %s\n", p.name);
            printf("Size: %d\n", p.size);
            printf("BHK: %d\n", p.bhk);
            printf("Location: %s\n", p.location);
            printf("Price: %d\n", p.price);
            printf("Code: %d\n", p.code);
            printf("\n");
        }

        fclose(fp);

        return 0;
    }


void Search(void)
{
    nametag();
    int n, code, size, bhk, price;
    char name[20];
    char location[50];

    fp = fopen("shopdatabase.txt", "rb");
    printf("\n***Search Available Apartments***\n\n");
    printf("Choose option to search with:\n");
    printf("1.Porperty Name\n2.Price\n3.Size\n4.Code\n5.BHK\n6.Location\n");
    printf("Your choice : ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    {
        printf("Enter Apartment Name : ");
        scanf(" %s", name);

        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (strcmpi(name, p.name) == 0)
            {
                printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
            }
            else
            {
                printf("Apartment not found!!\n\n");
                break;
            }
        }
    }
    break;

    case 2:
    {
        printf("Enter Apartment Price : ");
        scanf("%d", &price);

        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (p.price == price)
            {
                printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
            }
            else
            {
                printf("Apartment not found!!\n\n");
                break;
            }
        }
    }
    break;

    case 3:
    {
        printf("Enter Apartment Size (sq.ft) : ");
        scanf("%d", &size);

        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (p.size == size)
            {
                printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
            }
            else
            {
                printf("Apartment not found!!\n\n");
                break;
            }
        }
    }
    break;
    case 4:
    {
        printf("Enter Apartment Code : ");
        scanf("%d", &code);

        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (p.code == code)
            {
                printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
            }
            else
            {
                printf("Apartment not found!!\n\n");
                break;
            }
        }
    }
    break;
    case 5:
    {
        printf("Enter Apartment BHK : ");
        scanf("%d", &bhk);

        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (p.bhk == bhk)
            {
                printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
            }
            else
            {
                printf("Apartment not found!!\n\n");
                break;
            }
        }
    }
    break;

    case 6:
    {
        printf("Enter Apartment Location : ");
        scanf(" %s", location);

        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (strcmpi(location, p.location) == 0)
            {
                printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
            }
            else
            {
                printf("Apartment not found!!\n\n");
                break;
            }
        }
    }
    break;
    }
}

void adminpermit(void)
{

    system("color 0");
    int choice1;
    fp = fopen("shopdatabase.txt", "ab+");
    fseek(fp, 0, 0);
    nametag();
    adminportal();
    printf("1. Add New Apartment");
    printf("\n2. View Available Apartments");
    printf("\n3. Search Apartment");
    printf("\n4. Exit program");
    printf("\nEnter a choice: ");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        Update();
        break;
    case 2:
        View();
        break;
    case 3:
        Search();
        break;
    case 4:
        exit(1);
    }
    printf("Enter any key to go back to previous menu >> ");
    getchar();
    adminpermit();
}
