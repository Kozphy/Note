# The this Pointer
###### tags: `learn cpp`

![](https://i.imgur.com/qnQYEh4.png)

## Conflicting name
![](https://i.imgur.com/9rl0cZP.png)

## Chained calls using pointers
![](https://i.imgur.com/7iiexYy.png)

![](https://i.imgur.com/OMNQ3L3.png)

### dog.h
```cpp=
Dog *set_name(const string &dog_name);
Dog *set_dog_breed(const string &breed);
Dog *set_dog_age(int age);
```

### dog.cpp
```cpp=
// Chained calls with pointers:
Dog *Dog::set_name(const string &dog_name)
{
    this -> dog_name = dog_name;
    return this; // For use in chained calls
}

Dog *Dog::set_dog_breed(const string &breed)
{
    this -> dog_breed = breed;
    return this;
}

Dog *Dog::set_dog_age(const int age)
{
    if(this -> dog_age)
    {
        *(this -> dog_age) = age;
    }
    return this;
}
```

### main.cpp
```cpp=
// Chained calls using pointers
cout << endl;
cout << "Chained calls using pointers" << endl;
Dog *p_dog1 = new Dog("Millow", "Shephardl", 3);
p_dog1 -> print_info();
cout << endl;
cout << "after chained call: " << endl;

// Pointer version
p_dog1 -> set_name("Mirrow") -> set_dog_breed("Siwk") -> set_dog_age(10);
p_dog1 -> print_info();
delete p_dog1;
```

## Chained calls using references
![](https://i.imgur.com/xRlWAXH.png)

![](https://i.imgur.com/rUJ3sp5.png)

### dog.h
```cpp=
Dog &set_name(const string &dog_name);
Dog &set_dog_breed(const string &breed);
Dog &set_dog_age(int age);
```

### dog.cpp
```cpp=
Dog &Dog::set_name(const string &dog_name)
{
    this -> dog_name = dog_name;
    return *this; // dereference
}

Dog &Dog::set_dog_breed(const string &breed)
{
    this -> dog_breed = breed;
    return *this;
}

Dog &Dog::set_dog_age(const int age)
{
    if(this -> dog_age)
    {
        *(this -> dog_age) = age;
    }
    return *this;
}
```

### main.cpp
```cpp=
cout << "chained calls using refersence" << endl;
Dog *p_dog2 = new Dog("Milou", "shepherd", 10);
p_dog2 -> print_info();
cout << endl;
cout << "after chained call: " << endl;

// Reference version
p_dog2 -> set_name("Diow").set_dog_breed("Wire Fox Terrier").set_dog_age(20);
p_dog2 -> print_info();
delete p_dog2;
```

