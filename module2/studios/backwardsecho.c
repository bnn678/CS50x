#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argv, string argc[])
{
    int length;
    for( int i = 0; i < argv; i++ )
    {
        length = strlen(argc[i]);

        for( int j = length; j > -1; j--)
        {
            printf("%c", argc[i][j]);
        }
        
        printf(" ");
    }
    printf("\n");
}