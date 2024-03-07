# Pass by Pointer
###### tags: `learn cpp`

```cpp=
void say_age(int *age);

int main() {
    int age {23};

    std::cout << "age - before: " << age << " &age " << &age << std::endl;
    say_age(&age);

    std::cout << "age - after: " << age << " &age " << &age << std::endl;
    return 0;
}

void say_age(int *age){
    ++(*age);
    std::cout << "Hello! You are " << *age << " years old. &age " << age << std::endl;
}
```