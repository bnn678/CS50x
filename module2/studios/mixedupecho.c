#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argv, string argc[])
{
    if( argv != 2)
    {
        return 1;
    }
    
    string string1 = argc[0];
    string string2 = argc[1];
    
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    
    if( length1 > length2 )
    {
        for( int i = 0; i < length1; i++ )
        {
            printf("%c", string1[i] );
            printf("%c", string2[i % length2] );
        }
    }
    if( length2 > length1 )
    {
        for( int i = 0; i < length2; i++ )
        {
            printf("%c", string1[i % length1] );
            printf("%c", string2[i] );
        }
    }
    printf("\n");
}