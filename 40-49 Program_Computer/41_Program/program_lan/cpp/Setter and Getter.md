# Setter and Getter
###### tags: `learn cpp`

![](https://i.imgur.com/dEPvMiB.png)
## define class
```cpp=
#include <iostream>

const double PI {3.14};

// class Constructors
class Cylinder {
    public:
        double base_radius{};
        double height{};
    public:
        // Constructors
        // if we have parameters constructor, don't have default constructor or empty constructor.
        // Compiler will not generate empty constructor.
        Cylinder() = default;
        Cylinder(double radius_param, double height_param) {
            base_radius = radius_param;
            height = height_param;
        }
        double volume() {
            return PI * base_radius * base_radius * height;
        }
        // Getter
        double get_base_radius(){
            return base_radius;
        }
        double get_height(){
            return height;
        }
        // Setters
        void set_base_radius(double radius_param) {
            base_radius = radius_param;
        }
        void set_height(double height_param){
            height = height_param;
        }
};
```

## check setter and getter function
```cpp=
int main() {
    Cylinder cylinder1;
    std::cout << "volume c1: " << cylinder1.volume() << std::endl;
    std::cout << "get cylinder1 radius: " << cylinder1.get_base_radius() << std::endl;
    std::cout << "get cylinder1 height: " << cylinder1.get_height() << std::endl;
    cylinder1.set_base_radius(100);
    std::cout << "get cylinder1 radius after setter value: " << cylinder1.get_base_radius() << std::endl;

    Cylinder cylinder2{10, 20};
    std::cout << "volume c2: " << cylinder2.volume() << std::endl;

    return 0;
}
```