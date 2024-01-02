# Python IO module
###### tags: `python module`

## Overview
The io module provides Python’s main facilities for dealing with various types of I/O. There are three main types of I/O: text I/O, binary I/O and raw I/O.

A concrete object belonging to any of these categories is called a file object.

All streams are careful about the type of data you give to them. For example giving a **str** object to the **write()** method of a binary stream will raise a **TypeError**. So will giving a **bytes** object to the **write()** method of a text stream.

## Text I/O
Text I/O expects and produces str objects.

The easiest way to create a text stream is with `open()`, optionally specifying an encoding:
```python=
f = open('myfile.txt', 'r', encoding='utf-8')
```

In-memory text streams also available as **StringIO** objects:
```python=
f = io.StringIO('some initial text data')
```

The text stream API is described in detail in the documentation of [TextIOBase](The text stream API is described in detail in the documentation of TextIOBase.).

## Binary I/O
Binary I/O (also called buffered I/O) expects bytes-like objects and produces bytes objects.

This category of streams can be used for all kinds of non-text data, and also when manual control over the handling of text data is desired.
