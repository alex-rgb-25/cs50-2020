// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 1000
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// Hash table
node *table[HASHTABLE_SIZE];
bool is_loaded = false;
unsigned int num_words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for( int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    int index = hash(check_word);
    if(table[index] != NULL){
        for(node* nodeptr = table[index]; nodeptr != NULL; nodeptr = nodeptr->next){
            if(strcmp(nodeptr->word, check_word)==0){
                return true;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hash = 0;
    int h = 0;
    int n;
    for(int i = 0; word[i]!= '\0'; i++){  // iterate over the word parameter
        if(isalpha(word[i])){
            n = word[i] - 'a' + 1;
        } else{
            n = 27;
        }
        hash = ((hash << 3) +n) % HASHTABLE_SIZE;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // open dict. read strings one line at a time/one word
    //fopen check if null return false else go on: read from file
     FILE* file = fopen(dictionary, "r");
    if(file == NULL){
        return false;
    }

    for(int i = 0; i < HASHTABLE_SIZE; i++){
        table[i] = NULL;
    }
    char word[LENGTH+1];
    node *new_node;
      //fscanf(file, "%s", word)   will return EOF at end of file
    while(fscanf(file, "%s", word) != EOF){
        num_words++;
        do{
            new_node = malloc(sizeof(node));
            if(new_node == NULL){
                free(new_node);
            }
        }while(new_node == NULL);
        strcpy(new_node->word, word);
        int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;
    }
    fclose(file);

    is_loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(!is_loaded){
        return 0;
    }
    return num_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if(!is_loaded){
        return false;
    }

    for(int i = 0; i < HASHTABLE_SIZE; i++){
        if(table[i] != NULL)
        {
            node* ptr = table[i];
            while(ptr != NULL){
                node* predptr = ptr;
                ptr = ptr->next;
                free(predptr);
            }
        }
    }
    return true;
}
