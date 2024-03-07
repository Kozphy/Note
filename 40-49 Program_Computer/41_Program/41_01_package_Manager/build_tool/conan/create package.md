# create package
###### tags: `building tool`

```cmd=
$ cd ../create
$ conan new hello/0.1 # just a template
# check the conanfile.py
$ conan create . user/testing
$ conan search hello/0.1@user/testing
$ conan create . user/testing -s build_type=Debug
$ conan search hello/0.1@user/testing
```