#include <stdio.h>
#include <windows.h>

void splashScreen(void)
{
    system("color 02");
    FILE *file;
    char filelogo[] = "SplashLogo.txt";

    file = fopen(filelogo, "r");

    if (file != NULL)
    {
        char asciiCode;

        while ((asciiCode = fgetc(file)) != EOF)
        {
            putchar(asciiCode);
        }

        fclose(file);
    }
    else
    {
        printf("Error loading the software\n");
        exit(1);
    }

    sleep(5);
    system("cls");
}

