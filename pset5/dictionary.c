/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

typedef struct node
{
    int words;
    bool is_word;
    struct node* children[28];
}
node;

node* root = NULL;
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = calloc(1, sizeof(node));
    int index = 0, words = 0;
    char word[LENGTH+1];

    FILE* dict = fopen(dictionary, "r");
    
    // spell-check each word in text
    for (int c = fgetc(dict); c != EOF; c = fgetc(dict))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // append character to word
            word[index] = c;
            index++;

            // ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // consume remainder of alphabetical string
                while ((c = fgetc(dict)) != EOF && isalpha(c));

                // prepare for new word
                index = 0;
            }
        }

        // ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // consume remainder of alphanumeric string
            while ((c = fgetc(dict)) != EOF && isalnum(c));

            // prepare for new word
            index = 0;
        }

        // we must have found a whole word
        else if (index > 0)
        {
            // terminate current word
            word[index] = '\0';
            //printf("%s\n", word);

            // update counter
            words++;
            
            index = 0;
            char c = word[index];
            node* current = root;
            current->words = words;
            while( c != '\0')
            {
                c = toupper(c);
                //printf("%c, %i\n", c, c%'A' );
                
                if( isalpha(c) )
                {
                    if( current->children[c%'A'] == NULL )
                    {
                        current->children[c%'A'] = calloc(1, sizeof(node));
                        current->children[c%'A']->is_word = false;
                        current = current->children[c%'A'];
                    }
                    else
                    {
                        current = current->children[c%'A'];
                    }
                }
                else
                {
                    if( current->children[26] == NULL )
                    {
                        current->children[26] = calloc(1, sizeof(node));
                        current->children[26]->is_word = false;
                        current = current->children[26];
                    }
                    else
                    {
                        current = current->children[26];
                    }
                }
                index++;
                c = word[index];
            }
            current->is_word = true;

            // prepare for next word
            index = 0;
        }
    }
    //printf("\n");
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //printf("%s\n", word);
    char c = word[0]; int index = 0;
    node* current = calloc(1, sizeof(node));
    current = root;
    while( c != '\0')
    {
        c = toupper(c);
        //printf("%c, %i\n", c, c%'A');

        if( isalpha(c) )
        {
            if( current->children[c % 'A'] != NULL )
            {
                current = current->children[c % 'A'];
            }
            else
            {
                return false;
            }
        }
        else
        {
            if( current->children[26] != NULL )
            {
                current = current->children[26];
            }
            else
            {
                return false;
            }
        }
        
        index++;
        c = word[index];
    }
    if( current->is_word == true )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return root->words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return true;
}

void freeLeaves(struct node* node)
{
    int i;
    
    for ( i=0; i<28; i++ )
    {
        if(node->children[i] != NULL)
        {
            freeLeaves(node->children[i]);
        }
    }
    
    free(node);
}