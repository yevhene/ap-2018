// Implements a dictionary's functionality
// uses trie data structure
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>

#include "dictionary.h"
const int ALPHABET_SIZE = 27;

int dictionary_size = 0;

FILE *file;

typedef struct node
{
    bool is_terminal;
    struct node *next[ALPHABET_SIZE];
} node;

node *root;

node* create_new_node()
{
    node* result = malloc(sizeof(node));
    result->is_terminal = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        result->next[i] = NULL;
    }
    return result;
}


 // Returns true if word is in dictionary else false
bool check(const char *word)
{
    return true;
}


 // Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // opening the file with the dictionary
    file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }
    // allocating the root
    root = create_new_node();
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        dictionary_size++;
        int word_length = strlen(word);
        node *current_node = root;
        for (int i = 0; i < word_length; ++i)
        {
            int index = ALPHABET_SIZE - 1;
            if (word[i] != '\'')
            {
                index = tolower(word[i]) - 'a';
            }


            if (current_node->next[index] == NULL)
            {
                current_node->next[index] = create_new_node();
            }
            current_node = current_node->next[index];
        }
        current_node->is_terminal = true;
    }
    return true;
}
 // Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictionary_size;
}


 // Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    return true;
}