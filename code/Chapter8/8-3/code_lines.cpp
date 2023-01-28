#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("code_lines.cpp");
    int line_count = 0;
    string line;
    while (getline(in, line)) {
        line_count++;
    }
    in.close();

    ofstream out("code_lines.txt");
    out << "File name: " << __FILE__ << endl;
    out << "Line count: " << line_count << endl;
    out.close();

    return 0;
}