#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Enter the first float: ");
    float n1 = GetFloat();
    printf("Enter the second float: ");
    float n2 = GetFloat();
    printf("The ratio of n1 to n2 is %.2f percent \n",(n1/n2)*100);
}