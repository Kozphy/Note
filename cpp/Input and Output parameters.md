# Input and Output parameters
###### tags: `learn cpp`

![](https://i.imgur.com/paVpEfK.png)

```cpp=
void max_str(const std::string &input1, const std::string input2, std::string &output){
    if (input1 > input2){
        output = input1;
    }else {
        output = input2;
    }
}

void max_int( int input1, int input2, int &output){
    if(input1 > input2){
        output = input1;
    }else{
        output=input2;
    }
}

void max_double(double input1, double input2, double *output){
    if(input1 > input2){
        *output = input1;
    }else{
        *output = input2;
    }
}


int main() {
    std::string out_str;
    std::string string1("Alabama");
    std::string string2("Bellevue");
    max_str(string1, string2, out_str);

    std::cout << std::endl;
    std::cout << "max_str: " << out_str << std::endl;
    int out_int;
    int input1_int{4};
    int input2_int{10};
    max_int(input1_int, input2_int, out_int);
    std::cout << "max_int: " << out_int << std::endl;

    std::cout << std::endl;
    double out_doub;
    double input1_doub {123.03};
    double input2_doub {22.1};
    max_double(input1_doub, input2_doub, &out_doub);
    std::cout << "max_double: " << out_doub << std::endl;
    return 0;
}
```