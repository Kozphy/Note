# Constructor
###### tags: `learn cpp`

![](https://i.imgur.com/PHtSRnR.png)

## class constructor
```cpp
const double PI {3.14};

// class Constructors
class Cylinder {
    // Properties
    private: 
        // when default constructor isn't assign value or is empty constructor,
        // priate variable will be used.
        double base_radius{1.0};
        double height{1.0};
    // Behaviors
    public: 
        // called by compiler to initialize your class object
        // default constructor
        Cylinder(){
            base_radius = 2.0;
            height = 2.0;
        };
        // paramerter constructor
        Cylinder(double radius_param, double height_param) {
            base_radius = radius_param;
            height = height_param;
        }
        double volume() {
            return PI * base_radius * base_radius * height;
        }
};

int main() {
    Cylinder cylinder1;
    std::cout << "volume c1: " << cylinder1.volume() << std::endl;
    Cylinder cylinder2{10, 20};
    std::cout << "volume c2: " << cylinder2.volume() << std::endl;


    return 0;
}
```