#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Give me a phrase: ");
    char *phrase = GetString();
    
    printf("How many times should I say it? ");
    int repeat = GetInt();
    
    for( int i = 0; i < repeat; i++)
    {
        printf("%s\n", phrase);
    }
}