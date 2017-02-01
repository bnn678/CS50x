/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open the card.\n");
        return 1;
    }
    
    FILE* img;
    char block[512];
    int counter = 0;
    char file_name[8] = "000.jpg";
    img = fopen(file_name, "w");
    if ( img == NULL)
    {
        printf("Could not open .jpg file.\n");
        return 1;
    }
    
    // fill block
    fread( block, 1, 512, card );
    
    // find first jpg signature
    while( !( block[0] == (char) 0xff && block[1] == (char) 0xd8 && block[2] == (char) 0xff ))
    {
        fread( block, 1, 512, card );
    }
    // write the block to current file
    fwrite( block, 1, 512, img );
    
    // reads through card.raw
    while( fread( block, 1, 512, card ) > 0 )
    {
        // check for jpg signature
        if ( block[0] == (char) 0xff && block[1] == (char) 0xd8 && block[2] == (char) 0xff)
        {
            //close current file
            fclose( img );
            
            // create the next file's name
            counter++;
            sprintf( file_name, "%.3i.jpg", counter );

            // open the next file
            img = fopen(file_name, "w");
            if ( img == NULL)
            {
                printf("Could not open .jpg file.\n");
                return 1;
            }
        }
        
        // write the block to current file
        fwrite( block, 1, 512, img );
    }
}