# modules (files)

## [Source](https://docs.python.org/3/tutorial/modules.html#importing-from-a-package)

## intro

If you quit from the Python interpreter and enter it again, the definitions you have made (functions and variables) are lost. **This is known as creating a script**.

As your program gets longer, you may `want to split it into several files for easier maintenance`.

To support this, Python has a way to put definitions in a file and use them in a script or in an interactive instance of the interpreter.

Such a file is called a **module**; definitions from a module **can be imported into other modules** or **into the main module**.

A module is a file containing Python definitions and statements. The file name is the module name with the suffix `.py` appended.

Within a module, the module’s name (as a string) is available as the value of the global variable `__name__`.

For ex:
`fibo.py`

```python
# Fibonacci numbers module

def fib(n):    # write Fibonacci series up to n
    a, b = 0, 1
    while a < n:
        print(a, end=' ')
        a, b = b, a+b
    print()

def fib2(n):   # return Fibonacci series up to n
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result
```

And import and use

```python
import fibo

>>> fibo.fib(1000)
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
>>> fibo.fib2(100)
[0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
>>> fibo.__name__
'fibo'
```

if you intend to use a function often you can assign it to local name:

```python
>>> fib = fibo.fib
>>> fib(500)
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
```

## More on Modules

A module can contain **executable statements** as well as **function definitions**. These statements are intended to initialize the module.

They are executed **only the first time** the module name is encountered **in an import statement**.

Each module has its **own private namespace**, which **is used as the global namespace** by all functions defined in the module. (To avoid module name collisions)

The imported module names, if **placed at the top level of a module** (outside any functions or classes), **are added to the module’s global namespace**.

In following code, This does `not introduce the module name from which the imports are taken in the local namespace` (`fibo` not defined).

There is even a variant to import all names that a module defines except **names** beginning with **underscore(_)**:

```python
>>> from fibo import *
>>> fib(500)
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
```

## Executing modules as scripts

When you run a Python module with

```cmd
python fibo.py <arguments>
```

the code in the module will be executed, just as if you imported it, but with the ****name****set to "****main****".

Adding following code to end of module:

```python
if __name__ == "__main__":
    import sys
    fib(int(sys.argv[1]))
```

When add above code to end of module, which only runs if the module is executed as the **"main"** file:

```python
>>> python fibo.py 50
0 1 1 2 3 5 8 13 21 34
```

If the above module is imported, the code is not run:

```python
>>> import fibo
```

## The Module Search Path (important)

When a module named `spam` is imported, the interpreter first searches for a **built-in module** with that name. These module names are listed in `sys.builtin_module_names`.

If not found, it then searches for a file named `spam.py` in a list of directories given by the variable `sys.path`.

`sys.path` is initialized from these locations

- The directory containing the input script (or the current directory when no file is specified).
- **PYTHONPATH** (a list of directory names, with the same syntax as the shell variable PATH).
- The installation-dependent default (by convention including a `site-packages` directory, `handled by` the **site** module).

After initialization, Python programs can modify `sys.path`.

## "Compiled" Python files

**To speed up loading modules**, Python caches the compiled version of each module in the **`__pycache__`** directory under the name `module.version.pyc`, where the version encodes the format of the compiled file.

For example, in CPython release 3.3 the compiled version of spam.py would be cached as `__pycache__/spam.cpython-33.pyc`.

## Standard Modules

Python comes with a library of **standard modules**, described in a separate document, the Python Library Reference ("Library Reference" hereafter).

Some modules are built into the interpreter; these provide access to operations that are not part of the core of the language but are nevertheless built in, either **for efficiency** or to **provide access to operating system primitives** such as system calls.

The set of such modules is a configuration option which also **depends on the underlying platform**.

The `sys` is built into every Python interpreter. The variables `sys.ps1` and `sys.ps2` define the strings used as primary and secondary prompts:

```python
import sys
sys.ps1
'>>> '
sys.ps2
'... '
sys.ps1 = 'C> '
C> print('Yuck!')
Yuck!
C>
```

These two variables are **only defined** if the interpreter is in **interactive mode**.

The variable `sys.path` is a list of strings that **determines** the **interpreter’s search path** for modules.

It is initialized to a default path taken from the **environment variable** `PYTHONPATH`, or from a **built-in default** if `PYTHONPATH` is not set.

```python
>>> import sys
>>> sys.path.append('/ufs/guido/lib/python)
```

## dir() function

The built-in function `dir()` is used to find out **which names a module defines**. It returns a sorted list of strings:

```python
import fibo, sys
dir(fibo)
```

```python
>>> a = [1, 2, 3, 4, 5]
>>> import fibo
>>> fib = fibo.fib
>>> dir()
>>> ['__builtins__', '__name__', 'a', 'fib', 'fibo', 'sys']
```

Without arguments, dir() **lists the names you have defined currently**:
It lists all **types of names, variables, modules, functions**, etc.

```python
>>> a = [1, 2, 3, 4, 5]
>>> import fibo
>>> fib = fibo.fib
>>> dir()
```

`dir()` does not list the **names of built-in functions and variables**. If you want a list of those, they are defined in the standard module **builtins**:

```python
>>> import builtins
>>> dir(builtins)
```

## Packages

Packages are a way of **structuring Python’s module namespace** by using `“dotted module names”`.

For ex, `A.B` designates a submodule named `B` in a package named `A`. (This let modules without having to worry about name collisions)

```python
sound/                          Top-level package
      __init__.py               Initialize the sound package
      formats/                  Subpackage for file format conversions
              __init__.py
              wavread.py
              wavwrite.py
              aiffread.py
              aiffwrite.py
              auread.py
              auwrite.py
              ...
      effects/                  Subpackage for sound effects
              __init__.py
              echo.py
              surround.py
              reverse.py
              ...
      filters/                  Subpackage for filters
              __init__.py
              equalizer.py
              vocoder.py
              karaoke.py
              ...
```

When importing the package, Python **searches through the directories on sys.path** looking for the package subdirectory.

The `__init__.py` files are required to make Python **treat directories containing the file as packages**.

This prevents directories with a common name, such as string, unintentionally **hiding valid modules that occur later on the module search path**.

The following imports variants are available.

```python
import sound.effects.echo
```

```python
from sound.effects.echo import echo
```

```python
from sound.effects.echo import echofilter
```

Note that when using `from package import item`, the **item** can be `either` a **submodule (or subpackage) of the package**, or some **other name defined in the package**, like a **function**, **class or variable**.

The **import statement first tests** whether the item is defined in the package; if not, it assumes it is a module and attempts to load it. if it fails to find it, an `ImportError` exception is raised.

Contrarily, when using syntax like `import item.subitem.subsubitem`, each item **except for the last** must be a `package`; the **last item** can be a **module** or a **package** but can’t be a class or function or variable defined in the previous item.

## Importing * From a Package

Now what happens when the user writes `from sound.effects import *`? Ideally, one would hope that this somehow goes out to the filesystem, finds which submodules are present in the package, and imports them all. (This will take a long time)

### Solution

The only **solution** is for the package author to provide an **explicit index of the package**.

The import statement uses the following convention: if a package’s **`__init__.py`** code defines a list named **`__all__`**, **it is taken to be the list of module names that should be imported when from package import * is encountered**.

Ex: the file `sound/effects/__init__.py` could contain following code:

```python
__all__ = ["echo", "surround", "reverse"]
```

### if `__all__` not defined

The statement `from sound.effects import *` does **not import all submodules** from the package `sound.effects` **into the current namespace**; it only ensures that the package `sound.effects` has been imported (possibly running any initialization code in **`__init__`**.py) and then imports whatever names are defined in the package.

## Packages in Multiple Directories

Packages support one more special attribute, **`__path__`**. This is initialized to be a list containing the name of the directory holding the package’s **`__init__.py`** before the code in that file is executed.
