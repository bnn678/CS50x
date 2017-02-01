#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *name = GetString();
    
    char letter;
    int space_ascii = 32;
    int space_count = 0;
    
    for( int i = 0, n = strlen(name); i < n; i++ )
    {
        letter = (char)name[i];
        
        if( letter == space_ascii )
        {
            space_count++;
        }
    }
    
    char initials[space_count];
    initials[0] = toupper( name[0] );
    space_count = 0;
    
    for( int i = 0, n = strlen(name); i < n; i++ )
    {
        letter = (char)name[i];
        
        if( letter == space_ascii )
        {
            initials[space_count+1] = toupper( name[i+1] );
            space_count++;
        }
    }
    
    printf("%s\n", initials);

}