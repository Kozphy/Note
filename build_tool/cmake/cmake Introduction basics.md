# cmake Introduction basics
###### tags: `building tool`

## Setting a project
```cmake=
project(MyProject VERSION 1.0
                  DESCRIPTION "Very nice project"
                  LANGUAGES CXX)
```

## Making an executable
```cmake=
add_executable(one two.cpp three.h)
```
`one` is both the name of the executable file generated, and the name of the CMake target created.

The source file list comes next.

The headers will be, for most intents and purposes, ignored; the only reason to list them is to get them to show up in IDEs. 

## Making a library
```cmake=
add_library(one STATIC two.cpp three.h)
```

You get to pick a type of library, `STATIC, SHARED, or MODULE`. If you leave this choice off, the value of `BUILD_SHARED_LIBS` will be used to pick between `STATIC` and `SHARED`.


## Targets are your friend
```cmake=
target_include_directories(one PUBLIC include)
```
`target_include_directories` adds an include directory to a target. PUBLIC doesn't mean much for an executable; for a library it lets CMake know that any targets that link to this target must also need that include directory.

Other options are `PRIVATE`(only affect the current target, not dependencies), and `INTERFACE` (only needed for dependencies).

```cmake=
add_library(another STATIC another.cpp another.h)
target_link_libraries(another PUBLIC one)
```

`target_link_libraries` is probably the most useful and confusing command in CMake. It takes a target (`another`) and adds a dependency if a target is given. If no target of that name (one) exists, then it adds a link to a library called one on your path (hence the name of the command).


Targets can have include directories, linked libraries (or linked targets), compile options, compile definitions, compile features (see the C++11 chapter), and more.

