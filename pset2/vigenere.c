#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check for proper input
    if( argc == 1 || argc > 2 )
    {
        printf("%i",1);
        return 1;
    }
    
    string keyword = argv[1];
    int key_len = strlen(keyword);
    int key[key_len];

    // Check for valid keyword and define change key
    for( int i = 0; i < key_len; i++)
    {
        // If alpha character, convert to key value
        if( keyword[i] >= 'a' && keyword[i] <= 'z')
        {
            key[i] = keyword[i] - 'a';
        }
        else if( keyword[i] >= 'A' && keyword[i] <= 'Z')
        {
            key[i] = keyword[i] - 'A';
        }
        // If non alpha character, quit
        else
        {
            printf("%i",1); return 1;
        }
    }
    
    string phrase = GetString();
    int phrase_len = strlen(phrase);

    int letter;
    int new_letter;
    
    int i = 0; int count = 0;
    
    // Encryption sequence
    while( i < phrase_len )
    {
        letter = phrase[i];
        
        // Encrypts non alpha characters
        if( ( letter >= 'A' && letter <= 'Z' ) || ( letter >= 'a' && letter <= 'z' ) )
        {
            new_letter = letter + key[count % key_len];
            // Wraps character if necessary
            if( new_letter > 'z' || (new_letter > 'Z' && letter < 'a') )
            {
                new_letter -= 26;
            }

            // Displays encrypted character
            printf("%c", new_letter);
            count++;
        }
        // Does not encrypt non alpha characters
        else
        {
            printf("%c", letter);
        }
        
        i++;
    }
    printf("\n");
    
    return 0;
}