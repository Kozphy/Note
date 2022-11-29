# Struct
###### tags: `learn cpp`

![](https://i.imgur.com/ybdKXDR.png)

![](https://i.imgur.com/KDFGwDI.png)

![](https://i.imgur.com/uU85syF.png)


```cpp=
#include <iostream>
#include <string>

using namespace std;

class Dog{
    string m_name;
};

struct Cat
{
    string m_name;
};

struct Point
{
    double x;
    double y;
};

void print_point(const Point &point)
{
    cout << "Point.x " << point.x << endl;
    cout << "Point.y " << point.y << endl;
}

int main() {
    Dog dog1;
    Cat cat1;

    // compile error
    // dog1.m_name = "Fiwl";
    // cout << dog1.m_name << endl;

    cat1.m_name = "Wija";
    cout << cat1.m_name << endl;

    Point point1;
    point1.x = 10;
    point1.y = 55.5;
    print_point(point1);
    return 0;
}
```