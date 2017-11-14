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

1. Whitespace matters: `a := 123` is valid, but `a:=123` or `a:= 123` are syntax errors.
2. One tool to rule them all (compile, interpret, package management).
3. Automagic package management (if a package is not available ask to download).
4. Inmutability by default, mutability as opt-in but difficult to write.
5. Compiled and interpreted, also a REPL.
6. Strong typing but with implicit types: `Number a := 123` must be the same as `a := 123`.
7. Observer builtin (or pub/sub or something like that).
8. Multiparadigm: Functional and OOP at least (like python and/or js).
9. Closures.
10. First Class everything: Numbers, Arrays, Functions, Types.
11. OOP without inheritance, only composition (like golang, maybe?).
12. OOP without classes. (see Self)
13. Parametrized types (like List<T> or something like that).
14. Metaprogramming: If a type is first class we can create and modify types at runtime.
15. No implicit 'operator' precedence allowed: 2 + 3 * 4 should be illegal, you must write (2 + 3) * 4 or 2 + (3 * 4). But 2 + 3 + 4 is allowed (becasuse they are the same operator) (see Self)
16. EASY TO READ AND WRITE: "Any fool can write code that a computer can understand. Good programmers write code that humans can understand." - Martin Fowler.
17. Hot Code Reload.

# Things to investigate

* Self: http://www.selflanguage.org/ (OOP without classes, with "real" objects)
* Crystal: https://crystal-lang.org/ (Ruby-like, Concurrent, created by Argentinians)
* Nim: https://nim-lang.org/ (System language that compiles to JavaScript and builds dependency-free binaries)
* Zig: http://andrewkelley.me/post/intro-to-zig.html (Implemented in C, with a complete C ABI)
* Lemon: https://github.com/lemon-lang/lemon (Implemented in C)
* Rust: https://www.rust-lang.org (Traits, Enums)

# LICENSE

```
Copyright (c) 2014-2017 Lucas Gabriel Sánchez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
