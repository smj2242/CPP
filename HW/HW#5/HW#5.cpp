#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Line : public Shape {
public:
    void draw() override {
        cout << "선" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "원" << endl;
    }
};

class Rect : public Shape {
public:
    void draw() override {
        cout << "사각형" << endl;
    }
};
class GraphicEditor {
private:
    vector<Shape*> shapes;
public:
    ~GraphicEditor() {
        for (Shape* shape : shapes) {
            delete shape;
        }
    }

    void insertShape() {
        cout << "선택(1: 선, 2: 원, 3: 사각형): ";
        int choice;
        cin >> choice;

        Shape* shape = nullptr;
        switch (choice) {
        case 1: shape = new Line(); break;
        case 2: shape = new Circle(); break;
        case 3: shape = new Rect(); break;
        default:
            cout << "잘못된 선택입니다." << endl;
            return;
        }
        shapes.push_back(shape);
    }

    void deleteShape() {
        cout << "삭제할 도형의 인덱스: ";
        int index;
        cin >> index;

        if (index < 0 || index >= shapes.size()) {
            cout << "잘못된 인덱스입니다." << endl;
            return;
        }

        delete shapes[index];
        shapes.erase(shapes.begin() + index);
    }

    void showShapes() {
        for (int i = 0; i < shapes.size(); ++i) {
            cout << i << ": ";
            shapes[i]->draw();
        }
    }

    void run() {
        while (true) {
            cout << "삽입:1, 삭제:2, 모두 보기:3, 종료:4 >> ";
            int command;
            cin >> command;

            switch (command) {
            case 1: insertShape(); break;
            case 2: deleteShape(); break;
            case 3: showShapes(); break;
            case 4: return;
            default:
                cout << "잘못된 명령입니다." << endl;
            }
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.run();
    return 0;
}
