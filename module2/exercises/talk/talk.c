#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("How has your day been: ");
    string input = GetString();
    
    int stringLength = strlen(input);
    
    if( stringLength < 20 )
    {
        printf("YOU!!!!! ARE THE WORST!\n");
    }
    else if( stringLength > 50 )
    {
        printf("So I tuned out after the 50th character. Sorry.\n");
    }
    else
    {
        printf("You're an amazing talker!\n");
    }
}