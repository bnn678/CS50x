/**
 * Opines on the user's age
 */

// FIXME there's a bug somewhere...

#include <stdio.h>
#include <cs50.h>

int main(void)
{
  printf("How old are you? ");
  int age = GetInt();
  
  if (age == 10)
  {
    printf("The big 1 0. You're getting old.\n");
  }
  else if (age < 10)
  {
      printf("You're still a young'un to me kiddo.\n");
  }
  else 
  {
    printf("You gotcher whole life aheddaya.\n");
  }
}