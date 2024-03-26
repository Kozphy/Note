# Intro class
###### tags: `learn cpp`

![](https://i.imgur.com/MpKZyWs.png)

```cpp=
const double PI {3.14};


class Cylinder {
    public: 
        // member variables can't be references
        double base_radius{1.0};
        double height {1.0};
    private: 
        double base_radius2{1};
        double height2{1};
    public: 
        double volume(){
            return PI * base_radius * base_radius * height;
        };

};

int main() {
    Cylinder cylinder1;
    std::cout << "volume c1: " << cylinder1.volume() << std::endl;

    cylinder1.base_radius = 3.0;
    cylinder1.height = 2;

    Cylinder cylinder2;
    std::cout << "volume c2: " << cylinder2.volume() << std::endl;

    return 0;
}
```