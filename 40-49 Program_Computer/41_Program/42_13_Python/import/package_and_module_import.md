# import system

## [Source](https://docs.python.org/3/reference/import.html)

## module (files)

An **object** that serves as an **organizational unit of Python code**. Modules have a namespace containing arbitrary Python objects. Modules are **loaded into** Python **by the process of importing**.

## package (directories)

A Python module which can contain submodules or recursively, subpackages. Technically, a package is a Python module with a **`__path__`** attribute.

> keep in mind
> **all packages are modules**, but not all modules are packages, Any module that contains a `__path__` attribute is considered a package.

## Regular packages

A `traditional package`, such as a directory containing an `__init__.py` file.

A `regular package` is typically implemented as a directory containing an `__init.py__` file. When a regular package is imported, this `__init__`.py file **is implicitly executed**, and the objects it defines are **bound to names in the package’s namespace**.

For example, the following file system layout defines a top level parent package with three subpackages:

```python
parent/
    __init__.py
    one/
        __init__.py
    two/
        __init__.py
    three/
        __init__.py
```

Importing `parent.one` will implicitly execute `parent/__init__.py` and `parent/one/__init__.py`. Subsequent imports of `parent.two` or `parent.three` will execute `parent/two/__init__.py` and `parent/three/__init__.py` respectively.

## Namespace packages

A namespace package is a composite of various `portions`, where each portion contributes a subpackage to the parent package.

Portions may reside in different locations on the file system. Portions may also be found in zip files, on the network, or anywhere else that Python searches during import.

Namespace packages do not use an ordinary list for their `__path__` attribute.

### portion

A set of files in a single directory (possibly stored in a zip file) that contribute to a namespace package, as defined in PEP 420.
