#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

string getSummary(string filename) {
    ifstream in(filename);
    string summary;
    string line;
    while (getline(in, line)) {
        summary += line;
    }
    in.close();
    return summary;
}

set<string> getExcludes(string filename) {
    ifstream in(filename);
    set<string> excludes;
    string token;
    while (in >> token) {
        excludes.insert(token);
    }
    in.close();
    return excludes;
}

int main() {
    string summary = getSummary("summary.txt");
    vector<string> tokens;

    istringstream in(summary);
    string token;
    while (in >> token) {
        // eliminate the trailing punctuation
        if (!isalpha(token.back())) {
            token.pop_back();
        }

        // convert to lower case
        transform(
            token.begin(), token.end(),
            token.begin(), ::tolower);

        tokens.push_back(token);
    }

    set<string> excludes = getExcludes("excludes.txt");
    map<string, int> keywords;

    for (string token : tokens) {
        // not in excludes set
        if (excludes.find(token) == excludes.end()) {
            keywords[token]++;
        }
    }

    for (auto& p : keywords) {
        // print keywords that appear more than once
        if (p.second > 1) {
            cout << p.first << ": " << p.second << endl;
        }
    }

    return 0;
}