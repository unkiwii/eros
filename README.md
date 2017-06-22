**_This is a work in progress_**

# eros

is a statically typed, general-purpose programming language. **eros** is being developed right now and must:
* Be easy to read and write
* Provide a fast and nice write-compile-run-debug cycle
* Be able to produce native code in any machine
* Have a small footprint (no runtime environment or virtual machine involved)

## Building

### *nix
It depends on ```libedit``` to be installed:

```
apt-get install libedit   # on debian
# TODO: add more distros here
```

To build just run:
```
make
```

### Windows

Just run:
```
nmake
```

The binary will be located at ```bin/eros```

## Testing

### *nix
```
make test
```

### Windows
```
nmake test
```

# Ideas to have in mind

1. Whitespace matters: `a := 123` is valid but `a:=123` or `a:= 123` are syntax errors.
2. One tool to rule them all (compile, interpret, package management).
3. Automagic package management (if a package is not available ask to download).
4. Inmutability by default, mutability as opt-in but difficult to write.
5. Compiled and interpreted, also a REPL.
6. Strong typing but with implicit types: `Number a := 123` must be the same as `a := 123`.
7. Observer builtin (or pub/sub or something like that).
8. Multiparadigm: Functional and OOP at least (like python and/or js).
9. Closures.
10. First Class everything: Numbers, Arrays, Functions, Types.
11. OOP Without inheritance, only composition (like golang, maybe?).
12. Parametrized types (like List<T> or something like that).
13. Metaprogramming: If a type is first class we can create and modify types at runtime.
