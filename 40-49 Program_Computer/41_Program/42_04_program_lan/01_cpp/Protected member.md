# Protected member
###### tags: `learn cpp`
## what is protected
protected member can only be used in derived class.


## main.cpp
```cpp=
#include <iostream>
#include "player.h"



int main() {
    Player p1("Basketball");
    p1.set_first_name("John");
    p1.set_last_name("Lows");
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

        // Getter
        string get_first_name() const{
            return first_name;
        };
        string get_last_name() const{
            return last_name;
        };

        // Setter
        void set_first_name(string_view fn){
            first_name = fn;
        }

        void set_last_name(string_view ln){
            last_name = ln;
        }


    private:
        string last_name{"Mysterious"};
        string first_name{"Person"};
    
    protected:
        string other{"kioaw"};
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
: m_game(game_param){
    other = "wjisoa";
}

ostream &operator<<(ostream &out, const Player &player){
    out << "Player : [ game : " << player.m_game
        << " names : " << player.get_first_name()
        << " " << player.get_last_name() << ", other: " << player.other << "]";
    return out;
}

Player::~Player(){}
```

