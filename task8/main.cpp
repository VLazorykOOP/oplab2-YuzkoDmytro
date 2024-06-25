#include <iostream>
#include <vector>

// Константи для розміру області симуляції та швидкості руху
const int WIDTH = 100;
const int HEIGHT = 100;
const int V = 5;

// Клас для представлення автомобілів
class Car {
public:
    int x, y; // Положення автомобіля

    Car(int startX, int startY) : x(startX), y(startY) {}

    void move() {
        x += V;
        if (x > WIDTH) x = 0; // Повертаємося на початок, якщо вийшли за межі області
    }

    void display() const {
        std::cout << "Car at (" << x << ", " << y << ")\n";
    }
};

// Клас для представлення мотоциклів
class Motorcycle {
public:
    int x, y; // Положення мотоцикла

    Motorcycle(int startX, int startY) : x(startX), y(startY) {}

    void move() {
        y += V;
        if (y > HEIGHT) y = 0; // Повертаємося на початок, якщо вийшли за межі області
    }

    void display() const {
        std::cout << "Motorcycle at (" << x << ", " << y << ")\n";
    }
};

int main() {
    // Створюємо вектор автомобілів і мотоциклів
    std::vector<Car> cars = { Car(0, 10), Car(20, 10), Car(40, 10) };
    std::vector<Motorcycle> motorcycles = { Motorcycle(10, 0), Motorcycle(10, 20), Motorcycle(10, 40) };

    // Симулюємо декілька кроків
    for (int step = 0; step < 10; ++step) {
        std::cout << "Step " << step << ":\n";
        
        // Рухаємо автомобілі
        for (auto& car : cars) {
            car.move();
            car.display();
        }

        // Рухаємо мотоцикли
        for (auto& motorcycle : motorcycles) {
            motorcycle.move();
            motorcycle.display();
        }

        std::cout << "-----------------\n";
    }

    return 0;
}
