#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Give me a letter: ");
    int letter = GetChar();
    if( isalpha(letter) )
    {
        if( isupper(letter) )
        {
            letter -= 'A';
        }
        else if( islower(letter) )
        {
            letter -= 'a';
        }
        printf("%i\n", letter);
    }
}