#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("What is your favorite book? ");
    string book = GetString();
    printf("I love %s!\n", book);
    printf("HA! Except NOT!\n");
}