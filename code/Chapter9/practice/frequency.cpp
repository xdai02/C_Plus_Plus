#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include "word_list.h"

using namespace std;

string to_lower(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

string strip(string str, const string chars) {
    str.erase(0, str.find_first_not_of(chars));
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

int main() {
    const string PUNCTUATIONS = ",.?!:;\'\"";

    ifstream in("text.txt");
    if (!in) {
        cerr << "File open failed." << endl;
        exit(1);
    }

    WordList *word_list = create_word_list();

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        while (ss >> token) {
            token = to_lower(token);
            token = strip(token, PUNCTUATIONS);

            if (token.length() > 0) {
                cout << "start: " << token << endl;
                add_word(word_list, token);
                cout << "end: " << token << endl;
                cout << endl;
            }
        }
    }

    in.close();

    ofstream out("frequency.csv");
    for (int i = 0; i < word_list->word_count; i++) {
        out << word_list->words[i]->word << "," << word_list->words[i]->count << endl;
    }
    out.close();

    destroy_word_list(word_list);

    return 0;
}