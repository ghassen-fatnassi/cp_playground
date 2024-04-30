// ###############################################################################################
// class Shape {
// public:
//     virtual void draw() = 0; // Pure virtual function
//     virtual double area() = 0; // Another pure virtual function
// };

// class Circle : public Shape {
// private:
//     double radius;
// public:
//     Circle(double r) : {
// 			radius = r;
// 		}

//     void draw() {
//         cout << "Drawing a circle." << endl;
//     }

//     double area() {
//         return 3.14 * radius * radius;
//     }
// };

// class Rectangle : public Shape {
// private:
//     double width;
//     double height;
// public:
//     Rectangle(double w, double h) {
// 			width = w;
// 			height = h;
// 		}

//     void draw() const override {
//         cout << "Drawing a rectangle." << endl;
//     }

//     double area() const override {
//         return width * height;
//     }
// };

// int main() {
//     Circle circle(5.0);
//     Rectangle rectangle(4.0, 6.0);

//     Shape* shape1 = &circle;
//     Shape* shape2 = &rectangle;

//     shape1->draw(); // Calls Circle::draw()
//     cout << "Area of circle: " << shape1->area() << endl;

//     shape2->draw(); // Calls Rectangle::draw()
//     cout << "Area of rectangle: " << shape2->area() << endl;

//     return 0;
// }
// ###############################################################################################

//     // This is automatically called
//     // when '+' is used with between
//     // two Complex objects
//     Complex operator+(Complex const& obj)
//     {
//         Complex res;
//         res.real = real + obj.real;
//         res.imag = imag + obj.imag;
//         return res;
//     }

// ###########################################################################################
// class Base {
// public:
//     virtual void foo() {
//         cout << "Base::foo()" << endl;
//     }

// 		void display() {
// 			cout << "Base::foo()" << endl;
// 		}
// };

// class Derived : public Base {
// public:
//     void foo() {
//         cout << "Derived::foo()" << endl;
//     }
// 		void display() {
// 			cout << "Derived::foo()" << endl;
// 		}
// };

// int main() {
// 	Derived d;
// 	Base *ptr = &d;
// 	ptr->foo(); // Expected output: Derived::foo()
// 	ptr->display(); // Expected output: Base::foo()
// 	return 0;
// }
// ##########################################################################################
// class Vehicle {
// private:
//     int fuel;
//     int seatingCapacity;
//     bool brakesApplied;

// public:
//     // Constructor
//     Vehicle(int fuelAmount, int capacity) : fuel(fuelAmount), seatingCapacity(capacity), brakesApplied(false) {}

// class Bus : public Vehicle {
// public:
//     // Constructor
//     Bus(int fuelAmount, int capacity) : Vehicle(fuelAmount, capacity) {
//     }
// };

// class Car : public Vehicle {
// public:
//     // Constructor
//     Car(int fuelAmount, int capacity) : Vehicle(fuelAmount, capacity) {
//     }
// };

// class Truck : public Vehicle {
// public:
//     // Constructor
//     Truck(int fuelAmount, int capacity) : Vehicle(fuelAmount, capacity) {
//     }
// };

// #############################################################################
//  class MyClass {
//  private:
//      int secretValue;

// public:
//     MyClass(int value) : secretValue(value) {}

//     // Declaring the friend function
//     friend void showSecretValue(const MyClass& obj);
// };

// // Definition of the friend function
// void showSecretValue(const MyClass& obj) {
//     std::cout << "The secret value is: " << obj.secretValue << std::endl;
// }
// ###############################################################################
// class MyClass {
// public:
//     static int count; // Declaration of a static member variable
// };

// int MyClass::count = 0; // Definition of the static member variable
