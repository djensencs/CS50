#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

node *root;

int main(void)
{

}