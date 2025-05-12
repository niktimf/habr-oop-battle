// Approach: OOP
// Language: C++
// Author: Kahelman
//
// Референс: C++ / ООП реализация (v1)
//
// Вкачестве точки отсчёта — наш базовый вариант.
// Структурное ООП, без усложнений. Всё в одном файле.
//

#include <iostream>
#include <string>
#include <vector>

class Shape {
public:
    virtual void draw() const = 0;
    virtual std::string name() const = 0;
    virtual ~Shape() {}
};

class Point : public Shape {
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}
    void draw() const override {
        std::cout << "Drawing Point at (" << x << ", " << y << ")\n";
    }
    std::string name() const override { return "Point"; }
};

class Circle : public Shape {
    int x, y, r;
public:
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}
    void draw() const override {
        std::cout << "Drawing Circle at (" << x << ", " << y << "), r = " << r << "\n";
    }
    std::string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
    int x, y, w, h;
public:
    Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    void draw() const override {
        std::cout << "Drawing Rectangle at (" << x << ", " << y
                  << "), " << w << "x" << h << "\n";
    }
    std::string name() const override { return "Rectangle"; }
};

class Canvas {
    std::vector<Shape*> shapes;
public:
    void add(Shape* s) { shapes.push_back(s); }
    void render() const {
        for (auto s : shapes) s->draw();
    }
    ~Canvas() {
        for (auto s : shapes) delete s;
    }
};

int main() {
    Canvas canvas;
    canvas.add(new Point(1, 1));
    canvas.add(new Circle(5, 5, 3));
    canvas.add(new Rectangle(0, 0, 6, 3));

    canvas.render();
    return 0;
}

