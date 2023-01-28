#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    FILE *fp = fopen("data1.txt", "r");
    if (!fp) {
        cerr << "File open failed." << endl;
        exit(1);
    }

    char id[8];
    double score;
    double sum = 0;
    int n = 0;

    while (fscanf(fp, "ID=%s\tScore=%lf\n", id, &score) != EOF) {
        sum += score;
        n++;
    }
    cout << "Average = "
         << fixed << setprecision(2) << sum / n << endl;

    fclose(fp);
    return 0;
}