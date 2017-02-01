#include <stdio.h>
#include <cs50.h>

int main(void)
{
  string menuItems[] = {"Water", "Soda", "Cheeseburger", "Fries"};

  // Display menu:
  printf("Welcome to Good Burger! Can I take your order?\n");
  printf("MENU:\n");
  for (int i = 0; i < 4; i++)
  {
    printf("Item %i: %s\n", i, menuItems[i]);
  }
  printf("\nHow many items?\n");

  int numItems = GetInt();

  FILE* ptr = fopen("order.txt", "w");

  // if it is NULL, then quit the program (return 1) instead of continuing
  if( ptr == NULL )
  {
      printf("File open returned NULL\n");
      return 1;
  }

  int order_num;
  for (int i = 0; i < numItems; i++)
  {
    printf("Which menu item would you like?\n");
    // PUT YOUR CODE HERE: Take the order number, translate it into an item, and write the item to the file
    order_num = GetInt();
    if( order_num == 0 )
    {
        fwrite("Water", sizeof(char), 5, ptr);
    }
    else if( order_num == 1 )
    {
        fwrite("Soda", sizeof(char), 4, ptr);
    }
    else if( order_num == 2 )
    {
        fwrite("Cheeseburger", sizeof(char), 12, ptr);
    }
    else if( order_num == 3 )
    {
        fwrite("Fries", sizeof(char), 5, ptr);
    }

    // PUT YOUR CODE HERE: Write a new line ("\n") to the file 
    fwrite("\n", sizeof(char), 2, ptr);
  }

  fclose(ptr);

}