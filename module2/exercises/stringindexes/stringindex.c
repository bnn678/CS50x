#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    printf("String please: ");
    string s = GetString();
    
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        printf("The charater at index %d is %c\n", i, s[i]);
    }
}