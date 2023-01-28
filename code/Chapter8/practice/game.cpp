#include <iostream>
#include <fstream>
#include "tic_tac_toe.h"

using namespace std;

int main() {
    init_board();
    print_board();

    while (winner() == IN_PROGRESS) {
        if (get_current_player() == PLAYER) {
            int pos;
            cout << "Your turn. Enter a position: ";
            cin >> pos;
            if (!place(pos)) {
                cerr << "Invalid position." << endl;
                continue;
            }
        } else {
            cout << "Computer's turn." << endl;
            computer_action();
        }

        print_board();
        switch_player();
    }

    ifstream in("game.txt");
    int round = 0;
    string buf;
    while (getline(in, buf)) {
        round++;
    }
    round++;
    in.close();

    ofstream out("game.txt", ios::app);

    switch (winner()) {
    case PLAYER:
        cout << "Player wins!" << endl;
        out << "Round " << round << ": Win" << endl;
        break;
    case COMPUTER:
        cout << "Computer wins!" << endl;
        out << "Round " << round << ": Lost" << endl;
        break;
    case DRAW:
        cout << "Draw!" << endl;
        out << "Round " << round << ": Draw" << endl;
        break;
    }

    out.close();

    return 0;
}