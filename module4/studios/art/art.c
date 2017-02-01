#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int* hashLocations;
    int length;
} csvLine;

csvLine extractNumbers(char* line);

int main(void)
{
    //You need to do the following:

    //Prompt the user for an input file
    printf("What is the name of the file I should read from? ");
    char* readfile_name = GetString();
    
    //Open the file to read from
    FILE* readfile = fopen(readfile_name, "r");
    if( readfile == NULL )
    {
        printf("Read file open did not return NULL\n");
        return 1;
    }

    //Prompt the user for an output file
    printf("What is the name of the file I should writeto? ");
    char* writefile_name = GetString();

    //Open the file you're writing to
    FILE* writefile = fopen(writefile_name, "w");
    if( writefile == NULL )
    {
        printf("Write file open did not return NULL\n");
        return 1;
    }

    char line[256];
    csvLine result;
    int count = 0;
    //For each line being read in from the input file:
    for( int i = 1; fgets(line, sizeof(line), readfile) != NULL; i++ )
    {
        //Pass the line into the given extractNumbers function
        result = extractNumbers( line );

        //For each value in the int array returned by extractNumbers:
        for( int j = 0; j < result.length; j++ )
        {
            //put spaces in the file until the value is reached
            while( count != result.hashLocations[j] )
            {
                fputc(32, writefile);
                count++;
            }

            //put a hash in the file
            fputc(35, writefile);
        }
        
        fputc(10, writefile);
        count = 0;
    }

    //Close both files
    fclose(readfile);
    fclose(writefile);

    //Insert the name of the output file in the print statement below
    printf("Done! If you open up <output file name> you should now see a cool image!\n");
}

csvLine extractNumbers(char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            count++;
        }
    }

    char* token;
    int* hV = malloc(sizeof(int) * (count+1));
    int i = 0;
    token = strtok(line, ",");
    hV[i] = atoi(token);
    i++;
    while ((token = strtok(NULL, ",")) != NULL)
    {
        hV[i] = atoi(token);
        i++;
    }
    csvLine result;
    result.hashLocations = hV;
    result.length = count + 1;
    return result;
}