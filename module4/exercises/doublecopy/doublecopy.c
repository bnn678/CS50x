#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Whaddaya say, kid? ");
    char* s = GetString();
    
    char* t = malloc( (strlen(s)*2 + 1) * sizeof(char) );
    
    for( int i = 0, n = strlen(t); i < n*2; i++ )
    {
        t[i] = s[i%n];
        printf("%c", s[i%n]);
    }
    
    printf("%s\n", s);
    printf("%s\n", t);
}