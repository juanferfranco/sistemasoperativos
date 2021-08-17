#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[NAMESIZE];
    printf("What is your name? ");
    if (fgets(name, NAMESIZE, stdin) != NULL)
    {
        name[strlen(name) -1 ] = 0;
        printf("Hello %s!\n", name);
    }
}
