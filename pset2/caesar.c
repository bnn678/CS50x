#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if( argc == 1 || argc > 2 )
    {
        printf("%i",1);
        return 1;
    }
    
    char *phrase = GetString();
    char encrypted[strlen(phrase)];
    int letter;
    int new_letter;
    
    int key = atoi( argv[1] );
    key %= 26;
    
    for(int i = 0, n = strlen(phrase); i < n; i++)
    {
        letter = phrase[i];
        
        if( ( letter >= 'A' && letter <= 'Z' ) || ( letter >= 'a' && letter <= 'z' ) )
        {
            new_letter = letter + key;
    
            if( new_letter > 'z')
            {
                new_letter -= 26;
            }
    
            if( new_letter > 'Z' && letter < 'a')
            {
                new_letter -= 26;
            }
            
            encrypted[i] = new_letter;
        }
        else
        {
            encrypted[i] = letter;
        }
    }
    printf("%s\n", encrypted);
    
    return 0;
}