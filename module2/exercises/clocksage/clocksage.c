#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Give me the hour peasant: ");
    int hour = GetInt();
    
    printf("HOw far into the future shall I cast mine eye (in hours): ");
    int future = GetInt();
    
    printf("My omniscience has told me: 5 hours hence, the clock shall strike %i!\n", (hour+future)%12);
}