#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount)
        : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {}

    virtual ~Printer() {}

    virtual void print(int pages) = 0;

    virtual void showStatus() const {
        cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";
    }
};

class InkjetPrinter : public Printer {
private:
    int availableInk;

public:
    InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void print(int pages) override {
        if (availableCount < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else if (availableInk < pages) {
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            availableCount -= pages;
            availableInk -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void showStatus() const override {
        Printer::showStatus();
        cout << ", 남은 잉크 " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
private:
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void print(int pages) override {
        if (availableCount < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else if (availableToner < pages) {
            cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            availableCount -= pages;
            availableToner -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void showStatus() const override {
        Printer::showStatus();
        cout << ", 남은 토너 " << availableToner << endl;
    }
};

int main() {
    InkjetPrinter* inkjet = new InkjetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter* laser = new LaserPrinter("SCX-6x45", "Samsung", 3, 20);

    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
    inkjet->showStatus();
    laser->showStatus();

    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        int inkjetPages, laserPages;
        cout << "\n잉크젯 프린터 매수와 레이저 프린터 매수 입력>>> ";
        cin >> inkjetPages >> laserPages;

        cout << "잉크젯 프린터: ";
        inkjet->print(inkjetPages);
        cout << "레이저 프린터: ";
        laser->print(laserPages);

        inkjet->showStatus();
        laser->showStatus();

        cout << "계속 프린트 하시겠습니까?(y/n) >> ";
        cin >> cont;
    }

    delete inkjet;
    delete laser;
    return 0;
}
