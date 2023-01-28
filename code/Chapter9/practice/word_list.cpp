#include "word_list.h"

Word *create_word(const std::string word) {
    Word *w = new Word;
    w->word = word;
    w->count = 1;
    return w;
}

WordList *create_word_list() {
    WordList *word_list = new WordList;
    word_list->words = nullptr;
    word_list->word_count = 0;
    return word_list;
}

void add_word(WordList *word_list, const std::string word) {
    for (int i = 0; i < word_list->word_count; i++) {
        if (word_list->words[i]->word == word) {
            word_list->words[i]->count++;
            return;
        }
    }

    if (word_list->words == nullptr) {
        word_list->words = new Word *[1];
        word_list->words[0] = create_word(word);
        word_list->word_count++;
        return;
    }

    Word **temp = new Word *[word_list->word_count + 1];
    for (int i = 0; i < word_list->word_count; i++) {
        temp[i] = word_list->words[i];
    }
    delete[] word_list->words;
    word_list->words = temp;

    word_list->words[word_list->word_count] = create_word(word);
    word_list->word_count++;
}

void destroy_word_list(WordList *word_list) {
    for (int i = 0; i < word_list->word_count; i++) {
        delete word_list->words[i];
    }
    delete[] word_list->words;
    delete word_list;
}