#ifndef _WORD_LIST_H_
#define _WORD_LIST_H_

#include <iostream>
#include <string>

typedef struct {
    std::string word;
    int count;
} Word;

typedef struct {
    Word **words;
    int word_count;
} WordList;

Word *create_word(const std::string word);

WordList *create_word_list();

void add_word(WordList *word_list, const std::string word);

void destroy_word_list(WordList *word_list);

#endif