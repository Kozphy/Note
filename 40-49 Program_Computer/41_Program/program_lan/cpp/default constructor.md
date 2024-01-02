# default constructor
###### tags: `learn cpp`

```cpp=
const double PI {3.14};

// class Constructors
class Cylinder {
    public:
        double base_radius{1.0};
        double height{1.0};
    public:
        //Constructors
        Cylinder() = default;
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