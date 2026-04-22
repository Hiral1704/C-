#include <iostream>
using namespace std;
//Que 3
class Vehicle {
public:
    virtual void calculateTime(double distance, double speed) = 0;
};

class Car : public Vehicle {
public:
    void calculateTime(double distance, double speed) override {
        double time = distance / speed;
        cout << "Car travel time: " << time << " hours" << endl;
    }
};

class Bike : public Vehicle {
public:
    void calculateTime(double distance, double speed) override {
        double time = distance / speed;
        cout << "Bike travel time: " << time << " hours" << endl;
    }
};

int main() {
    Vehicle* v;

    Car car;
    Bike bike;

    v = &car;
    v->calculateTime(100, 60);  

    v = &bike;
    v->calculateTime(100, 40);  

    return 0;
}

#include <iostream>
using namespace std;
//Question 4

class Vehicle {
public:
    virtual void calculateTime(double distance, double speed) = 0;
    virtual void displayDetails() = 0;  
};


class Car : public Vehicle {
public:
    void calculateTime(double distance, double speed) override {
        double time = distance / speed;
        cout << "Car travel time: " << time << " hours" << endl;
    }

    void displayDetails() {
        cout << "This is a Car." << endl;
    }
};


class Bike : public Vehicle {
public:
    void calculateTime(double distance, double speed) override {
        double time = distance / speed;
        cout << "Bike travel time: " << time << " hours" << endl;
    }

    void displayDetails() {
        cout << "This is a Bike." << endl;
    }
};

int main() {

    Vehicle* v[2];

    Car car;
    Bike bike;

    v[0] = &car;
    v[1] = &bike;


    for (int i = 0; i < 2; i++) {
        v[i]->displayDetails();
        v[i]->calculateTime(100,60);
    }

    return 0;
}

#include <iostream>
using namespace std;
//Question 5
class Shape {
public:
    virtual void calculateArea() = 0;
    
};
class Circle : public Shape {
    double radius;
public:
    Circle(double r) {
        radius = r;
    }

    void calculateArea() {
        double area = 3.14 * radius * radius;
        cout << "Circle Area: " << area << endl;
    }
};


class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    void calculateArea() {
        double area = length * width;
        cout << "Rectangle Area: " << area << endl;
    }
};

int main() {
    Shape* shapes[2];
    
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->calculateArea();
    }
    return 0;
}
