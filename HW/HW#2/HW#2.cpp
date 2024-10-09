#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>

using namespace std;

class Player {
public:
    string name;

    Player(string n) : name(n) {}

    bool takeTurn() {
        cout << name << "님의 턴입니다. Enter 키를 입력해주세요.";
        cin.ignore();

        int num1 = rand() % 3;
        int num2 = rand() % 3;
        int num3 = rand() % 3;

        cout << "생성 번호: " << num1 << " " << num2 << " " << num3 << "       ";

        if (num1 == num2 && num2 == num3) {
            cout << name << "님 승리!" << endl;
            return true;
        }
        else {
            cout << "아쉽군요!" << endl;
        }
        return false;
    }
};

class GamblingGame {
private:
    Player* players[2];  

public:

    GamblingGame(string name1, string name2) {
        players[0] = new Player(name1);
        players[1] = new Player(name2);
    }

    void play() {
        int turn = 0;

        while (true) {
            if (players[turn]->takeTurn()) {
                break;
            }

            turn = (turn + 1) % 2;
        }
    }

    ~GamblingGame() {
        delete players[0];
        delete players[1];
    }
};

int main() {
    srand((unsigned int)time(0));

    string name1, name2;
    cout << "첫번째 선수 이름>> ";
    getline(cin, name1);
    cout << "두번째 선수 이름>>";
    getline(cin, name2);

    GamblingGame game(name1, name2);
    game.play();

    return 0;
}
