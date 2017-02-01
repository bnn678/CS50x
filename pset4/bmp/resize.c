/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
*/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember given input
    char* n_string = argv[1];
    int n = atoi(n_string);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // set dimesions for outfile
    BITMAPFILEHEADER new_bf;
    BITMAPINFOHEADER new_bi;
    
    new_bf = bf;
    new_bi = bi;
    
    new_bi.biWidth = bi.biWidth * n;
    new_bi.biHeight = bi.biHeight * n;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (new_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //printf("old: width: %i height: %i padding: %lu n: %i\n", bi.biWidth, bi.biHeight,  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4, n);
    //printf("new: width: %i height: %i padding: %i n: %i\n",new_bi.biWidth, new_bi.biHeight, padding, n);
    
    new_bi.biSizeImage = ( abs(new_bi.biWidth) * abs(new_bi.biHeight) * 3 ) + ( new_padding * abs(new_bi.biHeight) );
    new_bf.bfSize = 14 + 40 + new_bi.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over outfile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // stretch height
        for( int a = 0; a < n; a++ )
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // stretch width
                for( int b = 0; b < n; b++ )
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
                
            // add padding
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }
            
            // if this is not the last loop
            if( a != n - 1 )
            {
                // move to the beginning of the scanline
                fseek(inptr, -abs(bi.biWidth) * sizeof(RGBTRIPLE), SEEK_CUR);
            }
            
        }
        
        // go to the end of scanline and skip over padding, if any
        fseek(inptr, abs(padding), SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
