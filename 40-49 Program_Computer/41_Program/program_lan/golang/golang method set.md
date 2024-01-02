# golang method set
###### tags: `golang learn log`
## Stack overflow
https://stackoverflow.com/questions/33587227/method-sets-pointer-vs-value-receiver
```text
Values          Methods Receivers
-----------------------------------------------
T               (t T)
*T              (t T) and (t *T)

Methods Receivers    Values
-----------------------------------------------
(t T)                 T and *T
(t *T)                *T
```
## method set revisit
A type may have a _method set_ associated with it. 

The method set of an [interface type](https://golang.org/ref/spec#Interface_types) is its interface. 

The method set of any other type `T` consists of all [methods](https://golang.org/ref/spec#Method_declarations) declared with receiver type `T`. 

The method set of the corresponding [pointer type](https://golang.org/ref/spec#Pointer_types) `*T` is the set of all methods declared with receiver `*T` or `T` (that is, it also contains the method set of `T`).

Further rules apply to structs containing embedded fields, as described in the section on [struct types](https://golang.org/ref/spec#Struct_types).

Any other type has an empty method set. In a method set, each method must have a [unique](https://golang.org/ref/spec#Uniqueness_of_identifiers) non-[blank](https://golang.org/ref/spec#Blank_identifier) [method name](https://golang.org/ref/spec#MethodName).

The method set of a type determines the interfaces that the type [implements](https://golang.org/ref/spec#Interface_types) and the methods that can be [called](https://golang.org/ref/spec#Calls) using a receiver of that type.
### non interface Example
[A Tour of Go (golang.org)](https://tour.golang.org/methods/6)
[A Tour of Go (golang.org)](https://tour.golang.org/methods/7)
### have interface Example
[non pointer receiver](https://play.golang.org/p/CpGzcYh2yHR)
[pinter receiver](https://play.golang.org/p/fV9XIHP7NU0)

## 總結
1. 無 interface
    - 如果 value 是可尋址(addressable)的 
        value | receiver
        --------|-----
        *T | *T and T
        T | *T and T
    - 如果 value 是不可尋址的
        value | receiver
        -----|-------
        T    |    T
    

3. 有 interface
    interface implement receiver | value
    --|--
    *T | *T
    T | *T and T
