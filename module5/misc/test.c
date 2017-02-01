#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int n;
    struct node* next;
    struct node* prev;
}
node;

void CountTo(int limit, node* head, node* tail);
void ReadList(node* head);
void ReadListBackwards(node* tail);

int main(void)
{
    node* head = malloc(sizeof(node*));
    node* tail = malloc(sizeof(node*));
    
    CountTo(10, head, tail);
    
    ReadList(head);
    ReadListBackwards(tail);
}

void CountTo(int limit, node* head, node* tail)
{
    node* current = head;
    node* prev = current;
        
    for( int i = 0; i < limit; i++ )
    {
        current->n = i;
        
        if( i == limit-1 )
        {
            current = tail;
            current->next = NULL;
            current->n = i;
        }
        else
        {
            node* newNode = malloc(sizeof(node));
            current->next = newNode;
        }
        
        if( i == 0 )
        {
            current->prev = NULL;
        }
        else
        {
            current->prev = prev;
            prev = current;
        }
        
        current = current->next;
    }
}

void ReadList(node* head)
{
    node* current = head;

    while( current != NULL )
    {
        printf("%i\n", current->n);
        
        current = current->next;
    }
}

void ReadListBackwards(node* tail)
{
    node* current = tail;
    
    while( current != NULL )
    {
        printf("%i\n", current->n);
        
        current = current->prev;
    }
}