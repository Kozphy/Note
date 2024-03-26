# Arrow pointer call notation
###### tags: `learn cpp`

```cpp=
#include <iostream>
#include "cylinder.h"

using namespace std;

int main() {
    // Stack object: . notation
    Cylinder cylinder1(10,10);
    cout << "volume: "  << cylinder1.volume() << endl;

    // Heap object: . dereference and . notation
    //              . -> notation
    Cylinder *c2 = new Cylinder(11, 20); // Create object on heap
    cout << "volume c2: " << (*c2).volume() << endl; // derference and use dot notation
    cout << "volume c2: " << c2 -> volume() << endl; // -> is pointer access notation

    delete c2; // Remember to release memory from heap.
    
    return 0;
}
```