# Running Cmake
###### tags: `building tool`

## Building project
Unless otherwise noted, you should always make a build directory and build from there. You can technically do an in-source build, but you'll have to be careful not to overwrite files or add them to git, so just don't.

Here's the Classic CMake Build Procedure (TM):
```cmd=
~/package $ mkdir build
~/package $ cd build
~/package/build $ cmake ..
~/package/build $ make
```

You can replace the make line with `cmake --build .`.

If you are using a newer version of CMake (which you usually should be, except for checking compatibility with older CMake), you can instead do this:
```cmd=
~/package $ cmake -S . -B build
~/package $ cmake --build build
```


Any one of these commands will install:
```cmd=
# From the build directory (pick one)

~/package/build $ make install
~/package/build $ cmake --build . --target install
~/package/build $ cmake --install . # CMake 3.15+ only

# From the source directory (pick one)

~/package $ make -C build install
~/package $ cmake --build build --target install
~/package $ cmake --install build # CMake 3.15+ only
```


If you use `cmake --build` instead of directly calling the underlying build system, you can use `-v` for verbose builds (CMake 3.14+), `-j N` for parallel builds on N cores (CMake 3.12+), and `--target`(any version of CMake) or `-t` (CMake 3.15+) to pick a target.


## Picking a compiler
Selecting a compiler must be done on the first run in an empty directory. It's not CMake syntax per se, but you might not be familiar with it. To pick Clang:
```cmd=
~/package/build $ CC=clang CXX=clang++ cmake ..
```

## Picking a generator

You can build with a variety of tools; `make` is usually the default. To see all the tools CMake knows about on your system, run
```cmd=
~/package/build $ cmake --help
```
And you can pick a tool with `-G"My Tool"` (quotes only needed if spaces are in the tool name).

Feel free to have several build directories, like `build/` and `buildXcode`.

You can set the environment variable `CMAKE_GENERATOR` to control the default generator (CMake 3.15+).

## Setting options
You set options in CMake with `-D`.

You can see a list of options with `-L`, or a list with human-readable help with `-LH`.

## Verbose and partial builds
Although not all build tools support it, you can get verbose builds (pick one):
```cmd=
~/package $ cmake --build build --verbose # CMake 3.14+ only
~/package/build $ VERBOSE=1 make
```

## cached options
CMake has support for cached options. A Variable in CMake can be marked as "cached", which means it will be written to the cache (a file called `CMakeCache.txt` in the build directory) when it is encountered.

You can preset (or change) the value of a cached option on the command line with `-D`. When CMake looks for a cached variable, it will use the existing value and will not overwrite it.

## Standard options
- `-DCMAKE_BUILD_TYPE=` Pick from Release, RelWithDebInfo, Debug, or sometimes more.
- `-DCMAKE_INSTALL_PREFIX=` The location to install to. System install on UNIX would often be /usr/local (the default), user directories are often ~/.local, or you can pick a folder.
- `-DBUILD_SHARED_LIBS=` You can set this ON or OFF to control the default for shared libraries (the author can pick one vs. the other explicitly instead of using the default, though)
- `-DBUILD_TESTING=` This is a common name for enabling tests, not all packages use it, though, sometimes with good reason.

## Debugging your Cmake files
The `--trace` option will print every line of CMake that is run. Since this is very verbose, CMake 3.7 added `--trace-source="filename"`, which will print out every executed line of just the file you are interested in when it runs.

