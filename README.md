**_This is a work in progress, anything defined can be modified in the future_**

## Features of the language

#### Multiparadigm
At least Object-oriented, Functional and Structured (in that order of importance).

#### Strong typed
Types must be explicit, never implicit. (nothing like "auto" in C++ or ":*" in AS3)

#### Whitespace matters
Tabulation mark code blocks (like Python), use of 4 spaces for tabulation is required, tabs or other spacing are forbidden, extra empty lines between statements are forbidden also.

#### No exceptions
If a process fails for any reason it terminates the program with a human readable message.

#### All objects are first-class objects
Blocks of code (functions, methods, lambdas) and Type definitions (classes) are first-class objects and had methods of their own.

#### "Objects are discrete, self-contained, combinations of code and data"
All the data is private. Accesible only by code of the same object. All the code is public. Accesible by everyone.

#### Objects recieve messages like Smalltalk
```
object message.
object message: param.
```

#### Conditionals and loops
Are not part of the language, they are implemented like messages to objects (like Smalltalk)

```
boolean ifTrue: block.      # Branches (if)
boolean ifFalse: block.
```

```
block1 whileTrue: block2.   # Loops (while)
block1 whileFalse: block2.
```

```
1 to: 10 do: block.         # Range-loops (for)
begin to: end do: block.
```

#### Initialization is required. Always
```
Type v.                     # This is an error. Terminates the program.
Type v = value.             # This is ok.
Type v = object message.    # This is ok.
Type v = object message: v. # This is an error, v is not defined yet.
```

## Nice to have

* Automatic memory management, but without a garbage collector.
* No pointers.
* Unless "global" return values are returned not by copy, but by moving.
* Standard functions:
 * abort("str"): prints "str" and terminate the program.
 * assert(bool, "str"): if bool is false call abort(“str”).
* Standard objects:
 * StandardAllocator: manage memory like C.
 * DynamicPoolAllocator: manage memory like a dynamic growing pool.
 * FixedSizePoolAllocator: manage memory like a pool, but it have a fixed size pool.


## Structure of a source code file

```
import file         # "imports" are legal only at the beginning

statments           # statements are executed in order of appearance (structured)

functions           # blocks of code can be declared and invoked anywhere (functional)
    statements

types               # new types can be declared and used anywhere (oop)
    functions       # functions inside a type are methods
        statements
```


## Examples of code

**_TBD_**
