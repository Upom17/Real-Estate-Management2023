#include <stdio.h>
#include <string.h>
#include "Admin.h"
#include "Login.h"

void bill(void)
{
    printf("\n\n***Booking Details:***\n");
    printf("Apartment Details:\n\nName: %s\nCode: %d\nSize(sq.ft) : %d\nBHK: %d\nLocation : %s\nPrice: %d\n", p.name, p.code, p.size, p.bhk, p.location, p.price);
    printf("Payment Due (Broker's Fees) : BDT.500/=\n");
}

void book(void)
{
    nametag();
    customerportal();
    int code, option;
    printf("1.View All Apartments\n2.Search Specific Apartment\n\n");
    printf("Choose an option:");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    {
        View();
        puts("\nEnter Apartment Code (Press '0' if you want to go back to the previous menu) : ");
        scanf("%d", &code);
        nametag();
        fp = fopen("shopdatabase.txt", "rb");
        while (fread(&p, sizeof(struct product), 1, fp))
        {
            if (code == 0)
            {
                customerportal();
                book();
            }
            if (p.code == code)
            {
                printf("\nYour selected apartment: %s\n\n", p.name);
                printf("Enter any key to proceed...\n");
                getchar();
                bill();
                printf("Enter 'Y' to confirm your booking and '0' to terminate & go back to previous menu...");
                char c;
                scanf(" %c", &c);
                if (c == '0')
                {
                    customerportal();
                    book();
                }
                else if (c == 'Y' || c == 'y')
                {
                    nametag();
                    printf("Your booking is confirmed.\n\nOur broker will guide you to the apartment.\n\n");
                    printf("Thank you for choosing PROPERTY BD !!\n\n");
                }
            }
        }
        fclose(fp);
        break;
    }
    case 2:
    {
        Search();
        printf("Enter any key to go back to previous menu...\n");
        getchar();
        system("cls");
        customerportal();
        book();
    }
    }
}