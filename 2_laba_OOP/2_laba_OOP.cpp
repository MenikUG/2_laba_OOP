#include <iostream>
#include "conio.h"

using namespace std;

class Point {
public:
    int x, y;

    Point() {
        x = 0;
        y = 0;
        printf("Запустился конструктор по умолчанию у класса Point\n");
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
        printf("Запустился конструктор c параметрами у класса Point\n");
    }

    Point(const Point& p) {
        x = p.x;
        y = p.y;
        printf("Запустился конструктор копирования у класса Point\n");
    }

    ~Point() {
        printf("Запустился деструктор у класса Point\n");
    }
};





int main() {
    setlocale(0, "");

    printf("Point tochka;\n");
    Point tochka;

    printf("\nPoint tochka1(2, 5);\n");
    Point tochka1(2, 5);

    printf("\nPoint* tochka2 = new Point();\n");
    Point* tochka2 = new Point();





}