**_This is a work in progress, anything defined here can be modified in the future_**

## Features of the language

#### Multiparadigm
At least Object-oriented, Functional and Structured (in that order of importance).

#### Strong typed
Types must be explicit, never implicit. (nothing like "auto" in C++ or ":*" in AS3)

#### Whitespace matters
Tabulation mark code blocks (like Python), use of 4 spaces for tabulation is required, tabs or other spacing are forbidden, extra empty lines between statements are forbidden also.

#### Statement finalizers
In some languages each statement is finished by a character, in C-family they use a semicolon (';'), in Python the new line ('\n') is used, but in this language we will use a dot ('.') just like in the most spoken languajes (and Smalltalk).

#### No exceptions
If a process fails for any reason it terminates the program with a human readable message.

#### All objects are first-class objects
Blocks of code (functions, methods, lambdas) and Type definitions (classes) are first-class objects and had methods of their own.

#### "Objects are discrete, self-contained, combinations of code and data"
All the data is private, accesible only by code of the same object. All the code is public, accesible by everyone.

#### Objects recieve messages like Smalltalk
```
object message.
object message: param.
```

#### Conditionals and loops
Are not part of the language, they are implemented as messages to objects (like Smalltalk)

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
You can't define a variable, you must always declare it (give it a type and a value), i.e. in C you can write the following:
```C
int a;
a = 10;
```
or this:
```C
int aVeryLongVariableName;
int aVeriLongVariableName = func(aVeriLongVariableName);
```

Bacause pieces of code like those brought pain to me and are just to difficult to debug, a definition without an initialization will be illegal. For more details see **Variables** in the code examples below.

## Nice to have

* Every object must have an 'id', a unique number that represents that object in memory and can be used to check if two objects are the same.
* Iterating throught a collection make that collection 'selaed'. You can't change a collection while you are iterating throught it.
* Abstract classes and abstract methods. (complete and partial interfaces)
* Compilation must be "incremental". You pass 1 file to the compiler and only compile the files that are imported in the first file, then compile the ones that are imported in the imported files and so on. Never compile something that is not part of the objects and functions used by a probram, even the "standard" objects. If a Boolean is never used, it is never compiled.
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

## Naming requirements
The names of all types, variables and messages (funcionts names) must comply with the following rules:  
 1. The use of '_' is forbidden, only letters ('a' to 'z' and 'A' to 'Z') and digits (0 to 9) can be used.
 2. All types must start with uppercase letters and follow the `CamelCase` style.
```
GoodType.
badType.
OTHERBadType.
```
 3. All variables and messages must start with lowercase letters and follow the `camelCase` style.
```
aGoodName.
anotherGoodName.
BadVariableName.
a_bad_name.
REALLY_BAD_NAME.
```

## Code examples

#### Comments

```
# Line comments like Python.
# No multiline comments
```

#### Values (or primitives)

```
123                 # Integer Number
123,34              # Real Number, digits are separated with a comma.
'string'            # Strings are enclosed in single quotes
'こんにちは世界'    # Strings can hold any unicode char
```


#### Variables
Simple declarations:
```
Object anObject = anotherVariable.
Number aNumber = 123.
String aString = 'a string'.
```

Initialized with the return value of a block of code:
```
Object a = anObject message.
Object b = anObject message: param.
Object c = anObject message: param1 with: param2.
```

Any Type and any block of code are first-class objects, so they can be assigned to any variable:
```
Type aType = String.
Block aBlock = #TBD.
```

Declaration errors:
```
Object anObject.         # ERROR: A variable without a value is illegal...
Object anObject = null.  # ...but you can initialize it to null.

Object var = anObject message: var.    # ERROR: 'var' is not defined yet, can't be used.

Number aNumber = 123.    # Good.
Number aNumber = 456.    # ERROR: can't redefine a variable...
aNumber = 789.           # ...but you can change it's value.

Number aNumber = 123.    # Good.
String aNumber = 'str'.  # ERROR: can't redefine a variable even if you change it's type.

String aString = 123.                 # ERROR: assigning an incompatible type...
String aString = 123 asString.        # ...but you can get the correct type from a value...
String aString = aNumber asString.    # ...or from another variable.
```

## Standard Types

#### Number
At the moment I will use it just like a `long double` in C. This is the only numeric type and any litteral is an object, so code like this is valid:
```
Number two = 2.
Number four = 4.
Number eight = two times: four.

Number two = 2.
Number eight = two times: 4.

Number four = 4.
Number eight = 2 times: four.

Number eight = 2 times: 4.
```

Reals use the comma (',') as the decimal point:
```
Number pi = 3,1415.
Number twoPi = 3,1415 times: 2.
```

#### String
Only text type, there is no notion of 'char'. As with `Number` any litteral string is also of this type, so code like this is valid:
```
String aString = 'Hello World!'.

Number aLength = aString length.
Number anotherLength = 'Hello World!' length.
```

#### Block
A block of code. (function, method, lambda)
**_TBD_**

#### Boolean
There are only 2 instances of this type: `true` and `false`. Some operations return a `Boolean` and can be used as any other object:
```
String aString = 'Hello World!'.
Boolean hasWorld = aString contains: 'World'.
```

Some methods:
```
Block doSomething = #TBD.
Block doSomethingElse = #TBD.

Boolean isNew = true.
Boolean isOdd = 4 isOdd.

# Conditionals
isNew ifTrue: doSomething.
isNew ifFalse: doSomethingElse.
(isNew ifTrue: doSomething) ifFalse: doSomethingElse.

# Operators
Boolean newOrOdd = isNew or: isOdd.
Boolean newAndOdd = isNew and: isOdd.
Boolean newXorOdd = isNew xor: isOdd.
Boolean notNew = isNew not.
```

#### Interval
**_TBD_**

#### Tuple
**_TBD_**
