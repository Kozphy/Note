# class across multiple file
###### tags: `learn cpp`


![](https://i.imgur.com/MJiDnYc.png)

## main.cpp
```cpp=
#include <iostream>
#include "cylinder.h"

using namespace std;

int main() {
    Cylinder cylinder1(10,10);
    cout << "volume: "  << cylinder1.volume() << endl;
    
    return 0;
}
```
## constants.h
```cpp=
#ifndef CONSTANTS_H
#define CONSTANTS_H

double PI = 3.14;

#endif
```

## cylinder.h
```cpp=
#ifndef CYLINDER_H
#define CYLINDER_H


class Cylinder {
    private:
        double base_radius = 1;
        double height = 1;
    public:
        Cylinder() = default;
        Cylinder(double radius_param, double height_param);
        //Functions (methods)
        double volume();
        // Getter
        double get_radius();
        double get_height();
        // Setter
        void set_radius(double radius);
        void set_height(double height_param);
};

#endif
```
## cylinder.cpp
```cpp=
#include "cylinder.h"
#include "constants.h"

Cylinder::Cylinder(double radius_param, double height_param){
    base_radius = radius_param;
    height = height_param;
}

double Cylinder::volume()
{
    return PI * base_radius * base_radius * height;
}

double Cylinder::get_radius()
{
    return base_radius;
}

double Cylinder::get_height()
{
    return height;
}

void Cylinder::set_radius(double radius){
    base_radius = radius;
}


void Cylinder::set_height(double height_param){
    height = height_param;
}
```

