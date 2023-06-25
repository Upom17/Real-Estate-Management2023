#include <stdio.h>
#include <string.h>
#include <unistd.h>

void login(void)
{
    struct login
    {
        char FirstName[30],
            LastName[20],
            User_ID[30],
            Password[20],
            Location[30],
            mobile[12];
    };

    FILE *fp;
    fp = fopen("login.txt", "w");
    struct login user;

    printf("Enter First Name : ");
    gets(user.FirstName);
    printf("Enter Last Name : ");
    gets(user.LastName);
    printf("Enter Location : ");
    gets(user.Location);
    printf("Enter Phone Number : ");
    gets(user.mobile);
    printf("Enter User ID : ");
    gets(user.User_ID);
    printf("Enter Password : ");
    gets(user.Password);

    fwrite(&user, sizeof(user), 1, fp);

    fclose(fp);

    printf("\nRegistration Successful\n");

    sleep(2);
    system("cls");

    char User_ID[20],
        Password[20];

    fp = fopen("login.txt", "r");
    while (1)
    {

        printf("UserID : ");
        gets(User_ID);
        printf("Password : ");
        gets(Password);

        fread(&user, sizeof(user), 1, fp);

        if (strcmp(User_ID, user.User_ID) == 0 && strcmp(Password, user.Password) == 0)
        {
            printf("Login Successful \n");
            sleep(2);
            system("cls");
            break;
        }
        else
        {
            printf("Incorrect UserID and Password\n");
            printf("Try Again\n");
            sleep(2);
            system("cls");
        }
    }

    fclose(fp);
}
