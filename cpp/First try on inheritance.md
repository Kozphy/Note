# First try on inheritance
###### tags: `learn cpp`

![](https://i.imgur.com/IBJhFzL.png)

![](https://i.imgur.com/NbGzV1N.png)

![](https://i.imgur.com/O86ikar.png)

![](https://i.imgur.com/rBnwohf.png)

[C++ const in getter](https://stackoverflow.com/questions/21478342/c-const-in-getter)

## main.cpp
```cpp!
#include <iostream>
#include "player.h"



int main() {
    Player p1("Basketball");
    cout << "player: " << p1 << endl;
    return 0;
}
```
## person.h
```cpp=
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person{
    friend ostream &operator<<(ostream &out, const Person &person);
    public:
        Person();
        Person(string &first_name_param, string &last_name_param);
        ~Person();

        string get_first_name() const{
            return first_name;
        };
        string get_last_name() const{
            return last_name;
        };
    private:
        string last_name{"Mysterious"};
        string first_name{"Person"};
};

#endif
```
## person.cpp
```cpp=
#include "person.h"

Person::Person(){}

Person::Person(string &first_name_param, string &last_name_param) 
:first_name(first_name_param), last_name(last_name_param){}

ostream &operator<<(ostream &out, const Person &person){
    out << "Person [" << person.first_name << " " << person.last_name << "]";
    return out;
}

Person::~Person(){}
```


## player.h
```cpp=
#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"
#include <string_view>


class Player: public Person
{
    friend ostream &operator<<(ostream &out, const Player &player);
    public:
        Player() = default;
        Player(string_view game_param);
        ~Player();

    private:
        string m_game{"None"};
};

#endif
```

## player.cpp
```cpp=
#include "player.h"


Player::Player(string_view game_param)
: m_game(game_param){}

ostream &operator<<(ostream &out, const Player &player){
    out << "Player : [ game : " << player.m_game
        << " names : " << player.get_first_name()
        << " " << player.get_last_name() << "]";
    return out;
}

Player::~Player(){}
```