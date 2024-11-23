#include <iostream>
#include <vector>
#include "Circle.h"
#include "Line.h"
#include "Rect.h"

using namespace std;

int main() {
    vector<Shape*> shapes; 
    int choice;

    cout << "그래픽 에디터입니다." << endl;

    while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> choice;

        if (choice == 1) { 
            int type;
            cout << "삽입하려는 도형의 종류 (1: 선, 2: 원, 3:사각형 ): ";
            cin >> type;
            if (type == 1) {
                shapes.push_back(new Line());
            }
            else if (type == 2) {
                shapes.push_back(new Circle());
            }
            else if (type == 3) {
                shapes.push_back(new Rect());
            }
        }
        else if (choice == 2) { 
            int index;
            cout << "삭제하고자 하는 도형의 인덱스: ";
            cin >> index;
            if (index >= 0 && index < shapes.size()) {
                delete shapes[index];
                shapes.erase(shapes.begin() + index);
            }
            else {
                cout << "해당 인덱스에 도형이 없습니다." << endl;
            }
        }
        else if (choice == 3) { 
            for (size_t i = 0; i < shapes.size(); i++) {
                cout << i << ": ";
                shapes[i]->paint();
            }
        }
        else if (choice == 4) { 
            for (Shape* shape : shapes) {
                delete shape;
            }
            shapes.clear();
            break;
        }
    }

    return 0;
}
