# Conan Info and Search
###### tags: `building tool`

## search installed package
```cmd=
$ conan search
$ conan search zlib/1.2.11@
```

conan only search local repository by default.

## show accessible remote
```cmd=
conan remote list
```

## search remote repository and store result to file.html
```cmd=
conan search zlib/1.2.11@ --table=file.html -r=conancenter
```

## visualize dependency tree and store result to file.html
```cmd=
conan info .. --graph=file.html
```