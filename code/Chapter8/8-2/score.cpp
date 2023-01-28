#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    FILE *fp = fopen("data1.txt", "w");
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    char id[8];
    double score;
    for (int i = 0; i < n; i++) {
        cout << "Enter student " << i + 1 << "'s ID: ";
        cin >> id;
        cout << "Enter student " << i + 1 << "'s score: ";
        cin >> score;
        fprintf(fp, "ID=%s\tScore=%.2f\n", id, score);
    }

    fclose(fp);
    return 0;
}