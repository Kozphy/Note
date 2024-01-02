# build conan with cmake
###### tags: `building tool`

## create conanfile.txt and CmakeList.txt in root dir
### create conanfile.txt
```cmd=
[requires]
boost/1.72.0
poco/1.9.4

[generators]
cmake

[options]
boost:shared=False
poco:shared=False
```

### create CmakeLists.txt
```cmake=
cmake_minimum_required(VERSION 2.8.12)
project(timer)
add_compile_options(-std=c++11)

# Using the "cmake" generator
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(timer timer.cpp)
target_link_libraries(timer    
                        CONAN_PKG::poco
                        CONAN_PKG::boost
)
```

## build with conan and cmake
### not in debug mode
```cmd=
$ mkdir build && cd build
$ conan install ..
# check the generated conanbuildinfo.cmake
$ vimconanbuildifno.cmake
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```

### in debug mode
```cmd=
$ conan install .. -s build_type=Debug
# note that new packages are installed
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
$ cmake --build .
```


