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
        printf("Координаты точки (%d; %d)\n",x , y);
    }

    Point(const Point& p) {
        x = p.x;
        y = p.y;
        printf("Запустился конструктор копирования у класса Point\n");
    }

    void move(int mx, int my) { // Реализация метода в определении класса
        x += mx;
        y += my;
        printf("Запустился метод move у класса Point\n");
    }

    void reset();

    ~Point() {
        printf("\nЗапустился деструктор у класса Point\n");
        printf("%d, %d\n", x, y);
    }
};

void Point::reset() {
    x = 0;
    y = 0;
    printf("Запустился метод move у класса Point\n");
}

class Line {
public:
    Point* p1;
    Point* p2;

    Line() {
        p1 = new Point();
        p2 = new Point();
        printf("Запустился конструктор по умолчанию у класса Line\n");
    }

    Line(int x1, int y1, int x2, int y2) {
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
        printf("Запустился конструктор c параметрами у класса Line\n");
    }

    Line(const Line& l) {
        p1 = new Point(*(l.p1));
        p2 = new Point(*(l.p2));
        printf("Запустился конструктор копирования у класса Line\n");
    }

    void lenght_line() { // Метод для определния длины линии
        int a, b;
        double lenght;
        a = (p1->x) - (p2->x);
        b = (p1->y) - (p2->y);
        lenght = sqrt(a * a + b * b);
        printf("Длина линии = %.2f ", lenght);

    }
    ~Line() {
        printf("\nЗапустился деструктор у класса Line\n");
        printf("1 точка у линии: %d, %d\n", p1->x, p1->y);
        printf("2 точка у линии: %d, %d\n", p2->x, p2->y);
        delete p1;
        delete p2;
    }
};

int main() {
    setlocale(0, "");

    printf(" Взаимодействие с классом Point \n");
    printf("'Point tochka;'\n'tochka.move(8, 5);'\n");
    Point tochka;
    tochka.move(8, 5);

    printf("\n'Point tochka1(2, 5);'\n");
    Point tochka1(2, 5);

    printf("\n'Point tochka2(tochka1);'\n");
    Point tochka2(tochka1);

    printf("\n'Point *tochka = new Point();'\n");
    Point* tochka01 = new Point();

    printf("\n'Point* tochka = new Point(3, 6);'\n");
    Point* tochka02 = new Point(3, 6);

    printf("\n'Point tochka2(tochka1);'\n");
    Point* tochka03 = new Point(*tochka02);
    printf("==========================================================\n");

    printf(" Взаимодействие с классом Line \n");

    printf("\n'Line line1(1, 4, 6, 4);'\n");
    Line line1(1, 4, 6, 4);
    line1.lenght_line();




    /*delete tochka01;
    delete tochka02;
    delete tochka03;*/

}
