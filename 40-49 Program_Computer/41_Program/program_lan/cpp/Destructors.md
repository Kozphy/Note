# Destructors
###### tags: `learn cpp`

![](https://i.imgur.com/LEiXW87.png)

![](https://i.imgur.com/ruwTHfy.png)


## Destructors syntax
```cpp=
class Dog
{
    public:
        Dog();
        Dog(string name_param, string breed_param, int age_param);
        ~Dog(); // Destructor declared
                // Can also declare and implement in here : syntax commented out below: 
        /*
        ~Dog()
        {
            delete dog_age;
            cout << "Dog destructor called for " << dog_name << endl;
        }
        */

   private:
    string dog_name;
    string dog_breed;
    int *dog_age;
};
```

