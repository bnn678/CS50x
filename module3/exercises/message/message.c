#include <stdio.h>
#include <cs50.h>
#include <string.h>

/**
 * Prints a personalized message to the console.
 */
int printMessage( char*sender, char*recipient, char*message );
 
int main(void)
{
  printf("Name of sender: ");
  string sender = GetString();

  printf("Name of recipient: ");
  string recipient = GetString();

  printf("Message: ");
  string message = GetString();

  printMessage(sender, recipient, message);
}

// TODO create a function called printMessage
int printMessage( char*sender, char*recipient, char*message )
{
    printf("\n\nDear %s, \n\n", recipient);
    printf("%s \n\n", message );
    printf("Sincerely,\n%s\n", sender );
    return 0;
}