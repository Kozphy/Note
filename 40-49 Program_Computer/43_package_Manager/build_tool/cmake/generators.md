# generators
###### tags: `building tool`

## build with plain gcc compiler generators
Conan install with `-g compiler_args` to specify the generator in cmd-line.
```cmake
$ conan install . -g compiler_args

# check conanbuildinfo.args
$ g++ timer.cpp @conanbuildinfo.args -o timer -std=c++11
$ ./timer
```

## Generators
![](https://i.imgur.com/VDCqTib.png)

## cmake_find_package
### conanfile.txt
```txt=
[requires]
boost/1.72.0
poco/1.9.4

[generators]
cmake_find_package

[options]
boost:shared=False
poco:shared=False
```

### CMakeLists.txt
```txt
cmake_minimum_required(VERSION 3.0)
project(timer)
add_comiple_options(-std=c++11)

# Using the "cmake_find_package" generator, files are in the BIN dir
set(CMAKE_MODUOLE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

find_package(Boost REQUIRED)
find_package(Poco REQUIRED)

add_executable(timer timer.cpp)
target_link_libraries(timer Poco::Poco Boost::Boost)
```

### build
```cmd=
$ mkdir build && cd build
conan install ..
# check the generated Findxxxx.cmake
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake --build . # or make
```