# Using Dependencies
###### tags: `building tool`

## Intro
Projects will frequently depend on other projects, assets, and artifacts.

The primary methods of bringing dependencies into the build are the `find_package()` command and the `FetchContent` module. 

The `FindPkgConfig` module is also sometimes used, although it lacks some of the integration of the other two and is not discussed any further in this guide.

## Using Pre-built Packages with find_package()
A package needed by the project may already be built and available at some location on the user's system. That package might have also been built by CMake, or it could have used a different build system entirely.

CMake provides the `find_package()` command for these scenarios.

It searches well-known locations, along with additional hints and paths provided by the project or user. It also supports package components and packages being optional.

In most cases, projects should generally use the Basic Signature. Most of the time, this will involve just the package name, maybe a version constraint, and the `REQUIRED` keyword if the dependency is not optional.

### Examples of find_package() basic signature
```cmake=
find_package(Catch2)
find_package(GTest REQUIRED)
find_package(Boost 1.79 COMPONENTS date_time)
```

The `find_package()` command supports two main methods for carrying out the search:
- Config mode
    - With this method, the command looks for files that are typically provided by the package itself. This is the more reliable method of the two, since the package details should always be in sync with the package.
- Module mode
    - Not all packages are CMake-aware. Many don't provide the files needed to support config mode. For such cases, a Find module file can be provided separately, either by the project or by CMake. 
    - A Find module is typically a heuristic implementation which knows what the package normally provides and how to present that package to the project. Since Find modules are usually distributed separately from the package, they are not as reliable. They are typically maintained separately, and they are likely to follow different release schedules, so they can easily become out-of-date.

Depending on the arguments used, `find_package()` may use one or both of the above methods.

## Config-file packages
The preferred way for a third party to provide executables, libraries, headers, and other files for use with CMake is to provide config files.

These are text files shipped with the package, which define CMake targets, variables, commands, and so on. The config file is an ordinary CMake script, which is read in by the `find_package()` command.

The config files can usually be found in a directory whose name matches the pattern `lib/cmake/<PackageName>`, although they may be in other locations instead (see Config Mode Search Procedure).