# Installing C++ Compilers on Linux
###### tags: `learn cpp`

# install compiler and check
```cmd
sudo apt-get install gcc-10
sudo apt-get install g++-10
sudo apt-get install gdb
gcc-10 --version
g++-10 --version
gdb --version

sudo apt-get install clang-12

## install homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install gcc
```

# change vscode task.json
```json=
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "Build with GCC 11.2.0",
			"command": "/home/linuxbrew/.linuxbrew/bin/g++-11",
			"args": [
				"-g",
				"-std=c++20",
				"${workspaceFolder}/*.cpp",
				"-o",
				"${fileDirname}/rooster"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: /home/linuxbrew/.linuxbrew/bin/g++-11"
		},
		{
			"type": "cppbuild",
			"label": "Build with clang 12.0.0",
			"command": "/usr/bin/clang++-12",
			"args": [
				"-g",
				"-std=c++20",
				"${workspaceFolder}/*.cpp",
				"-o",
				"${fileDirname}/rooster"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: /usr/bin/clang++-12"
		}
	]
}
```
# change c_pp_properties.json
```cmd
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/home/linuxbrew/.linuxbrew/bin/gcc-11",
            "cStandard": "gnu17",
            "cppStandard": "c++20",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```