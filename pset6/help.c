#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strcspn_example();
int strchr_example();
int strrchr_example();

int main ()
{
  // For method
  //strcspn_example();

  // For request-target
  //strchr_example();

  // For HTTP Version
  strrchr_example();
}

// For method
int strcspn_example()
{
  char str[] = "GET www.google.com HTTP-1.1\r\n";
  //char keys[] = " ";
  
  int i;
  i = strcspn (str," ");
  printf ("%s\nThe first space in str is at position %d.\n",str,i);
  
  char* word = malloc( sizeof(char) * (i+1) );
  for( int j=0; j!=i; j++ )
  {
      word[j] = str[j];
  }
  word[i+1] = '\0';
  
  printf("The string is %s\n and %c\n", word, word[i]);
  
  for( int j=0; j<i; j++ )
  {
      printf("%c\n", word[j]);
  }
  
  return 0;
}

// For request target
int strchr_example()
{
  char str[] = "GET www.google.com HTTP-1.1";
  char* pch;
  int beginning; int end;
  
  printf ("Looking for the ' ' character in \"%s\"...\n",str);
  pch=strchr(str,' ');
  beginning = pch-str+2;

  pch=strchr(pch+1,' ');
  end = pch-str+1;
  
  char* request = malloc( sizeof(char) * (end-beginning+1) );
  for( int i = 0; i < end-beginning; i++ )
  {
    request[i] = str[i+beginning-1];
  }
  request[end-beginning] = '\0';
  
  printf("%s\n", request);
  
  free(request);
  
  return 0;
}

// For HTTP Version
int strrchr_example()
{
  char line[] = "GET /favicon.ico HTTP/1.1";
  char* pch;
  
    pch=strrchr(line,'/');
    char* version = malloc( sizeof(char) * 5);
    for( int i = 0; i < 4; i++ )
    {
        version[i] = pch[i+1];
    }
    version[4] = '\0';
    if( strcmp(version, "1.1") != 0 )
    {
        //error(505);
        //return false;
        printf("Failed\n");
    }
    else
    {
      printf("Success!\n");
    }
    
  printf("%s\n", version);
    
  free(version);
  
  return 0;
}