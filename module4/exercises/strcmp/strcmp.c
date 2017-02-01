#include <stdio.h>
#include <cs50.h>
#include <string.h>

int customstrcmp(char* string1, char* string2);

int main(void){
    printf("\nString 1?: ");
    char* string1 = GetString();
    printf("\nString 2?: ");
    char* string2 = GetString();

    int areEqual = customstrcmp(string1, string2);

    if (areEqual == 0){
        printf("\nBingo! The strings are equal!\n");
    } else {
        printf("\nThe strings are not equal!\n");
    }
}

int customstrcmp( char* string1, char* string2 )
{
    int len = strlen( string1 );
    
    if( len == strlen(string2) )
    {
        int i = 0;
        while( true )
        {
            if( string1[i] != string2[i] )
            {
                return 1;
            }
            if( i == len - 1 )
            {
                return 0;
            }
            
            i++;
        }
    }
    
    return 1;
}