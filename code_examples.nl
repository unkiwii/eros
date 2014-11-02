# IMPORTANT: All code in this file is valid, compilable code. All compiler errors will be inside a comment. You can use
# this file as a quick reference for the language.

# if you want to view this file with a highlighted syntax you can do one (or both) of this things:
#
#   1. Download 'vim/syntax/nl.vim', open this file with vim and use that syntax file to highlight correctly.
#
#   2. Go to http://unkiwii.github.io/newlang/code_examples.html and see this file rendered as an html (but the .html
#      can be older than this file)


########## comments ##########

# any line starting with a '#' character is a comment, there are no multi-line comments


########## importing code from other files and libraries ##########

# importing a file in same folder

import aFile

# importing a file in a subfolder

import foo/aFile
import foo/bar/aLib

# importing a file in a parent folder

import ../aFile
import ../../aLib
import ../foo/aFile
import ../foo/bar/aLib


########## literals ##########

# this language has only 2 literals: Numbers and Strings
#
# Numbers:
#   123       # an integer
#   0.123     # a real
#
# Strings:
#   "Hello World!"  # inside double quotes
#
# in C, for example, a literal value is a legal statement, but not here, you can't just write a number or a string alone
# in a line of code and expect it to work.


########## variable declarations ##########

# the way to declare a variable is:

Type name := "value"

# where:
#   Type    is the type (or class) of the variable, any type must start with a upper case character and be followed by
#           any upper or lower case character, as in: Type, Object, HTTPServer, etc.
#
#   name    is the name of the variable, any name must start with a lower case character and be followed by any upper or
#           lower case character: aName, someVariable, thisNumber, etc.
#
#   :=      is the assignation operator, unlike other languages the ':=' is used instead of the usual '=' for
#           assignation, because the '=' can be used to compare if two values are the same.
#
#   value   is the value assigned to the variable, this can be a literal, another identifier (name of another variable)
#           or any block evaluation that returns a value.
#
# NOTE: a variable can't be declared without an initialization, i.e. in C you can have a 'int a;' declared but not
# initialized, in this language that is illegal.

# you can declare a variable anywhere, it's scope is defined by the place of it's declaration, if you declare it here,
# it will be global (accessible by the whole code of the program)

Number aGlobalNumber := 123
String aGlobalString := "Hello World"

# if you declare them inside a block of code it will local to that block of code and invisible from anywhere else; same
# with a type.


########## types declarations ##########

# this is a multi paradigm language, and one of the paradigms that supports is object oriented programming, for that you
# must be allowed to write your own objects, to accomplish this you must declare a new type, as a blueprint for objects
# to be created from that blueprint, like a 'class' in Java or C++

type NewType
  # member declaration: every instance of 'NewType' will have it's own 'data'
  String data := "some data"

  # static member declaration: only one instance of this object for all the instances of 'NewType'
  static Number id := 123

  # method declaration: this block of code will be associated with every new instance of 'NewType', it must be evaluated
  # by passing the message 'someCode' to an object of type 'NewType':
  #
  #   anObject someCode
  #
  [ String someCode |
    # ...
    return data
  ]

  # static method declaration: this block of code is associated with the type 'NewType' and it must be evaluated by
  # passing the message 'doSomething' to the 'NewType' type:
  #
  #   NewType doSomething
  #
  static [ doSomething |
    # ...
  ]

  # in this language there are no constants, for that reason if you want to have a constant value just use a method that
  # returns a literal value
  [ Number pi |
    return 3.1415
  ]

# maybe you noticed that no 'public' or 'private' was used, that's because here there are not access modifiers, you can
# only send messages to an object, never access it's internal representation:
#
#   EVERY MEMBER OF AN OBJECT IS PRIVATE TO THAT OBJECT.
#
#   EVERY METHOD OF AN OBJECT IS PUBLIC VISIBLE TO EVERY OTHER OBJECT.
#
# you can only evaluate code of an object, never access it's data directly.


########## blocks of code ##########

# there are 3 types of blocks:
#
#   global    these work just like any global function from C, they are available from any part of the program and can
#             be evaluated from anywhere, they had a name for that.

#   methods   these are blocks of code associated with a particular type and in run time with a particular object.
#
#   lambdas   anonymous blocks of code that are used right in place or passed to other blocks of code as a parameter to
#             be executed later.
#
# all of them are declared in the same way and are always enclosed in square brackets '[' and ']', a block is declared
# as follows:

[ ReturnType blockName |
  # block code
]

# where:
#   [             marks the start of a block.
#
#   ReturnType    is the type of the result returned by the block of code. If the block doesn't return anything a
#                 special keyword: 'void' is used to denote this fact.
#
#   blockName     is the name of the block, as with a variable, any name must start with a lower case character and be
#                 followed by any upper or lower case character: aName, someVariable, thisNumber, etc.
#
#   |             the vertical bar character ('|'), marks the end of the header of the block and the beginning of the
#                 body of the block that has the code.
#
#   ]             marks the end of a block.
#
# blocks have two important parts, the header and the body, they are separated with a vertical bar '|' character:
#
#   [ header | body ]
#
# in the header we define the return type, the name of the block, the type and name of the parameters.
# in the body we define the executable code of the block itself.
#
# in some programming languages, the name and parameters of a block of code are separated, for example we will write a
# function (and it's call) in C that receives 2 integer numbers and returns (as an integer) it's sum:
#
#   int add(int a, int b) {
#     return a + b;
#   }
#
#   add(4, 5);
#
# the name of that function is 'add', it's signature is 'int add(int, int), and has 2 parameters: 'a' and 'b' both
# integers, in this language the same function is written like this:

[ Number add: Number a and: Number b |
  return a + b
]

add: 4 and: 5

# the name of the block is 'add:and:' and it's signature is 'add: Number and: Number', and has 2 parameters: 'a' and 'b'
# both Numbers. In this example maybe it's better the C code, but see the next example:
#
#   void iterate(int from, int to, void (do*)(int)) {
#     ...
#   }
#
#   iterate(1, 10, &func);
#
# and the language code:

# the declaration is a bit more verbose
[ from: Number start to: Number end do: [ value: Number ] aBlock |
  # code
]

# but the evaluation is just as simple as it can get:
from: 1 to: 10 do: [
  # code
]

# even more, as the literals '1' and '10' are of type Number we can add that block as a method of Number type:
type Number
  [ to: Number stop do: [ value: Number ] aBlock |
    # code
  ]

# and evaluate the above method as:
1 to: 10 do: [
  # code
]

# note that we are not chaining a call, that is just a call to a single block of code, things that in C-like languages
# you must write as 'name(param1, param2)' you must write it here as 'name: param1 name2: param2' it may sound silly,
# but wait a little and you should see the power behind this structure.

# here are multiple examples of various types of blocks that return and receive objects.

### no return, no parameters
# declare
[ name |
  # code
]
# evaluate
name

### return, no parameters
# declare
[ Number name |
  # code
  return 0
]
# evaluate
Number result := name

### multiple returns (yes, you can return more than one object from a block of code), no parameters
# declare
[ (Number, String) name |
  # code
  return (0, "Hello")
]
# evaluate
Number a, String b := name

### no return, 1 parameter
# declare
[ name: String param |
  # code
]
# evaluate
name: "Hello"

### return, 1 parameter
# declare
[ Number name: Number param |
  return param + 123
]
# evaluate
Number result := name: 12

### multiple returns, 1 parameter
# declare
[ (Number, String) name: Number param |
  return (param + 123, param asString)
]
# evaluate
Number a, String b := name: 123

### no return, more than 1 parameter
# declare
[ name: Number param and: String param2 |
  # code
]
# evaluate
name: 123 and: "Hello"

### return, more than 1 parameter
# declare
[ Number name: Number param and: Number param2 |
  return param + param2
]
# evaluate
Number result := name: 123 and: 345

### multiple retuns, more than 1 parameter
# declare
[ (Number, Number) sqrt: Number a pow: Number b to: Number c |
  return (a sqrt, b pow: c)
]
# evaluate
Number s, Number p := sqrt: 25 pow: 3 to: 4

# in resume, the header has the following structure:
[ ReturnType name1: Type1 param1 name2: Type2 param2 name3: Type3 param3 |
  # code
]

# where:
#
#   ReturnType    can be any type or nothing when no returning
#
#   name1         is the name of the first part of the name of the block, if no parameters are passed this will be the
#                 name of the block, but if a parameter is passed then a ':' is needed at the end of the name with one
#                 exception: for methods with only 1 parameter you can skip the ':' character to declare a binary
#                 operator like '+', '/' or '&'.
#
#   Type1         is the type of the first parameter, it could be any type but never 'void'.
#
#   param1        is the name of the first parameter, this is the name used in the code of the block to refer to the
#                 first parameter, it could be any identifier valid name.
#
# the rest of names, types and params are the ones for the rest of the parameters in the block, you can pass any number
# of parameter to a block and the name is formed by: 'name1:name2:name3:...' and so on

# IMPORTANT: there is an exception to all this rules, read this piece:

[ Number pi |
  return 3.14
]

# and this one:

Number index := 0
Number size := 10
[ Boolean test |
  return index < size
]

# that is a block that has only one return statement and doesn't receive anything, in this case and ONLY IN THIS CASE
# you can skip the header completely:

[ 3.14 ] # this block returns a Number (type inference)

[ index < size ] # this block returns a Boolean (type inference)

# those may seems useless but just keep this in mind, we will use this constructs


########## assertions ##########

# this language implementes an 'assert' just like in C, with some differences:
#
#   void assert (int expression);
#
# that function (in C) checks the value of the expression parameter and if it's evaluate to 0 then it halts the program,
# that function is implemented like this:
[ assert: Boolean test onFalse: String message |
  test ifFalse: [
    # this prints the message and halts the program, just like 'void exit(int status);' in C.
    abort message
  ]
]
# and call it like this:
assert: (instance = null) onFalse: "The instance is not null"

# but that's not all, you can define other asserts to help with other tests like these:
assert: instance onNull: "The instance is null"
assert: instance onNotNull: "The instance is not null"
assert: (a > 4) onTrue: "a is greater than 4"

# the implementation of those methods
[ assert: Object anObject onNull: String message |
  (anObject = null) ifTrue: [
    abort message
  ]
]

[ assert: Object anObject onNotNull: String message |
  (anObject = null) ifFalse: [
    abort message
  ]
]

[ assert: Boolean test onTrue: String message |
  test ifTrue: [
    abort message
  ]
]

# you can define your own assertions as you define any other block of code


########## more types ##########

# here is an example of an abstract type, if a type has at least 1 abstract method, then the whole type is abstract,
# because you can't create a type that has a method without an implementation, an interface (like the ones in Java) is
# implemented using a pure abstract type, a type that has not even one method implemented and no data associated with
# it.
type Boolean
  # in C++ you can define a 'virtual = 0' function, but here you declare just their interfaces, not their bodies and
  # mark the method as 'abstract'
  abstract [ ifTrue: [ value ] ]
  # in that last method called 'ifTrue:' it just returns nothing and receives a parameter (here the name is missing
  # because this is just an interface, not the real method) and that parameter is a block of code that doesn't return
  # anything and doesn't receive anything, the block declaration is '[ void value ]' because it must be evaluated like
  # this (asuming that the block's name is 'aBlock':
  #
  #   aBlock value.
  #
  # so you can define a block and pass it to 'ifTrue:' like this:
  #
  # Boolean aBool := true.
  #
  # aBool ifTrue: [ void value |
  #   ...
  # ].

  # Boolean has another method 'ifFalse:'
  # but this are interfaces, so parameters names are not required
  abstract [ ifFalse: [ value ] ]

  # here is another interface with more parameters
  # again, this is an interface, so parameters with no names are fine
  abstract [ ifTrue: [ value ], ifFalse: [ value ] ]

  # here is another interface
  # note that 'ifTrue:ifFalse' is not the same that 'ifFalse:ifTrue'
  abstract [ ifFalse: [ value ], ifTrue: [ value ] ]

  # here is an interface that receives a block that returns something
  # 'or:' is a method that returns a Boolean and receives another block of code
  # that is evaluated if this object is True, so the block that receives must
  # return 'Boolean'
  abstract [ Boolean or [ Boolean value ] ]

  # the same with and:
  abstract [ Boolean and [ Boolean value ] ]

# now, all those methods are just too verbose, for all the '[ value ]' the compiler can assume the 'value': every block
# of code can be evaluated, so it must have a name, a way to call it, so if any block has no header a 'value' is
# inserted to be able to evaluate it so '[ value ]' can be written just as '[]', here is a smaller declaration of
# Boolean (without the comments):

type Boolean
  abstract [ ifTrue: [] ]
  abstract [ ifFalse: [] ]
  abstract [ ifTrue: [] ifFalse: [] ]
  abstract [ ifFalse: [] ifTrue: [] ]
  abstract [ Boolean or [ Boolean ] ]
  abstract [ Boolean and [ Boolean ] ]

# and the calls to those methods:
Boolean aBool := true

# declaring a method that doesn't return anything and has a 'value' name
aBool ifTrue: [ void value |
  # code...
]

# is the same to write just this (a method with a body but without a header)
aBool ifTrue: [
  # code...
]

# or if without a explicit Boolean variable: (note the use of parenthesis)
(age < 18) ifTrue: [
  # code when age is less than 18
] ifFalse: [
  # code when age is equals or greater than 18
]

# NOTE: maybe you are wondering why 'or' and 'and' both receive a block that returns a Boolean and not a Boolean itself,
# that's to be able to perform lazy evaluation:
Driver aDriver := Driver age: 15 license: false
(aDriver age > 18) and: [ aDriver hasLicense ] ifTrue: [
  # code when a driver can drive a vehicle
]
# in the above code, if age is less than 18, then the block '[ aDriver hasLicense ]' is never executed, but if 'and:'
# would receive a Boolean instead, first that block is evaluated to get the retunr value and then that value (true or
# false) is passed to 'and:' method.

# now an inheritance example, we can have simple inheritance only, never multiple inheritance
type True extends Boolean
  # by stating that a type 'extends' another type we are defining inheritance, as you can see there is a 'True' type
  # (also we will have a 'False' type) and with this is that all the boolean methods are implemented, please note that
  # as this is a concrete type, not an abstract one, the parameters in every method need a name to be evaluated inside
  # the method code and a vertical bar '|' is used to separate the header of the method from it's body:
  [ ifTrue: [] aBlock |
    # evaluate 'aBlock' since the receiver is true.
    aBlock value
  ]

  [ ifFalse: [] aBlock |
    # do nothing since the receiver is true, this method will be replaced by nothing in the final compiled code
  ]

  [ ifTrue: [] trueBlock ifFalse: [] falseBlock |
    # evaluate 'trueBlock' since the receiver is true.
    trueBlock value
  ]

  [ ifFalse: [] falseBlock ifTrue: [] trueBlock |
    # evaluate 'trueBlock' since the receiver is true.
    trueBlock value
  ]

  [ Boolean or [ Boolean ] aBlock |
    # answer self since the receiver is true, here you can see the lazy evaluation: 'aBlock' is never evaluated when the
    # receiver of 'or' method is the true object.
    return self
  ]

  [ Boolean and [ Boolean ] aBlock |
    # answer the result of evaluating aBlock since the receiver is true, again the lazy evaluation: 'aBlock' is
    # evaluated here because the left part of the and is the true object, so the block must be evaluated to see if the
    # whole method 'and' is true or false.
    return aBlock value
  ]


# here is the False declaration
type False extends Boolean
  [ ifTrue: [] aBlock |
    # do nothing since the receiver is false, this method will be replaced by nothing in the final compiled code
  ]

  [ ifFalse: [] aBlock |
    # evaluate 'aBlock' since the receiver is false.
    aBlock value
  ]

  [ ifTrue: [] trueBlock ifFalse: [] falseBlock |
    # evaluate 'falseBlock' since the receiver is false.
    falseBlock value
  ]

  [ ifFalse: [] falseBlock ifTrue: [] trueBlock |
    # evaluate 'falseBlock' since the receiver is false.
    falseBlock value
  ]

  [ Boolean or [ Boolean ] aBlock |
    # answer the result of evaluating aBlock since the receiver is false.
    return aBlock value
  ]

  [ Boolean and [ Boolean ] aBlock |
    # answer self since the receiver is false.
    return self
  ]


# NOTE: there are two global variables in the environment: 'true' and 'false', both are instances of types 'True' and
# 'False', this special variables can't be overridden, the compiler will see that as an error.
type Boolean
  # any type can be initialized to 'null' or with the value of other method or literal.
  Boolean instance := Boolean new

  # a method to retrieve the only instance of this type
  static [ Boolean instance |
    return instance
  ]

  # an abstract method that defines how a Boolean is created, this can be overridden by the types that extends this one:
  # True and False respectively.
  abstract static [ Boolean new ]

type True extends Boolean
  # here is the 'new' method that returns a new instance of a type
  static [ Boolean new |
    assert: instance onNotNull: "true was already created, use 'True instance' or just 'true' instead".
    # here is a special call: it tells the 'system' to allocate (and return) a new object of type 'True'
    return System alloc: True
  ]

# same for False
type False extends Boolean
  static [ Boolean new |
    assert: instance onNotNull: "false was already created, use 'False instance' or just 'false' instead".
    return System alloc: False
  ]

# maybe you noticed that severtal times a write a type with just one method and then we write the same type again with
# other method, well that is legal code, you can write a partial type and in the future add a new method to it.


########## operators ##########
# a few languages has something called operators, they are some constructs in the language that allow to call a block of
# code in a different way, for example, in C++ and Java you call blocks of code using the identifier of an object and
# then (separated with a dot '.') the name of the method to call:
#
#   anObject.aMethod();
#
# so, in that languajes to perform tasks as this:
#
#   4 + 5;
#
# you need to define a new way to call a function, here operators are introduced, but to make things simple, in this
# language you don't have to write a different thing, if you see again the statement above you'll se the next structure:
#
#   Number + Number
#
# and even so:
#
#   object message object
#
# that's valid code for this language, so here is the Number type with some operators:
type Number
  [ Number + Number a |
    # code to add self and 'a'.
  ]

  [ Number - Number a |
    # code to substract 'a' from self.
  ]

  # this also works with comparison operators:
  [ Boolean < Number a |
    # code to check if self is less than 'a'.
  ]

  [ Boolean = Number a |
    # code to check if self is equals to 'a'.
  ]

# you can define all the operators (existing or not) in your own types, the '+' is not part of the language as is in C,
# C++ or Java, the '+' is just another method name that can be used as you will use 'add' or 'sum' or any other name you
# want to use.

# but with numbers there is a special case, this methods: add, substract, multiply, etc. are a lot better if they are
# performed by the CPU directly, so this methods (in the real code) will be defined as 'primitive' methods:
type Number
  primitive [ Number + Number ]
  primitive [ Number - Number ]
  primitive [ Boolean < Number ]
  primitive [ Boolean = Number ]
# the 'primitive' keyword states that those methods are not written in this language, they are written directly in
# machine code by the compiler, later we will be able to write our own primitive methods to extend the language.


########## control structures ##########

# as a student we learned that any program can be written with just 3 structures:
#
# when you read the next diagrams just have in mind that:
#
#     linear:              branch:              loop:
# perform a task      select wich task      perform a task
#  after another         to perform          several times
#
#        O                    O                   O
#        |                    |                   |
#       [ ]                --/ /--               [ ]<--
#        |                 |     |                |   |
#       [ ]               [ ]   [ ]              / /---
#        |                 |     |                |
#        X                 -------                X
#                             |
#                             X
#
# how to read those diagrams
#   O   marks the start of the program
#   [ ] marks the execution of some task
#   / / marks a decision
#   X   marks the end of the program
#   |   just connects one statement with another
#
# the linear execution is just a statement of the language after another, most languages has this (with few exceptions)
# but the branch and the loop are implemented in very different ways depending on the language, in C-like family
# languages, they use some constructs that are hard coded in the compiler:
#
#   branches: if, if else, if elseif, and switch
#
#   loops: for, while, do while
#
# but in this language those constructs are not present, there is no such thing as a 'while' keyword or 'if' statement,
# instead ther are messages passed to objects of type Boolean that perform the same tasks, we already see this in the
# Boolean type definition, every boolean object (remember, there are two boolean objects: 'true' and 'false') has a
# collection of methods to evaluate a block or not, this collection of methods are use to implemente the branches:
type Boolean
  abstract [ ifTrue: [] ]
  abstract [ ifFalse: [] ]
  abstract [ ifTrue: [] ifFalse: [] ]
  abstract [ ifFalse: [] ifTrue: [] ]

# the loops are implemented in the Block type we saw before a 'whileTrue' method, here is again without all the 'void'
# declarations
type Block
  # this method works just like a 'while (bool) {}' in C
  [ whileTrue: [] aBlock |
    (self value) ifTrue: [
      aBlock value
      self whileTrue: aBlock # recursive call
    ]
  ]

  # this method works just like a 'do {} while(bool)' in C
  [ whileTrue |
    (self value) ifTrue: [
      self whileTrue
    ]
  ]

# and a range loop is implemented in the Number type, note that this uses the 'whileTrue: []' from Block
type Number
  # this method works just like a 'for (...) {}' in C
  [ to: Number end by: Number step do: [] aBlock |
    Number index := self
    [ current < end ] whileTrue: [
      aBlock value
      index := index + step
    ]
  ]

# of course we can have other methods like 'whileFalse' in Block but as you can see you can define those methods
# yourself with no problem.


# TODO:
#
# Data structures:
#   * list, vector or array (a list of objects)
#   * map, dictionarie, hashtable (a table of objects associated with other objects)
#
# Parametrizized types?
#   maybe with templates like C++ or just with a type as it's argument

########## OLD THINGS (will be changed) ###########
# as in C++ and C# you can have templates (or Generics)
# here is a list (this is like a C array, a contiguous piece of memory)
# List<String> aListOfStrings := List<String> new: 40.
# 
# here is a map
# Map<String, Object> aDictionary := Dictionary<String, Object> new.
# 
# here is a definition of List<T>
# type List<ValueType>
#   Number size := 0.
# 
#   # new is implemented primitively
#   primitive static [ List<ValueType> new: Number size ].
# 
#   # accesors like [] in C to get and set values at different indices
#   primitive [ ValueType at: Number index ].
# 
#   primitive [ at: Number index, set: ValueType value ].
# 
#   # for each...
#   [ forEach: Block<value: ValueType> do |
#     0 to: size do: [ value: Number step |
#       do value: (self at: step).
#     ].
#   ].
# 
#   [ forEach: Block<value: ValueType, index: Number> do |
#     0 to: size do: [ value: Number step |
#       do value: (self at: step) index: step.
#     ].
#   ].
# 
#   [ forEach: Block<value: ValueType> do, while: Block<Boolean> condition |
#     Number step := 0.
#     [ Boolean | return (step <= size) and: condition. ] whileTrue: [
#       do value: (self at: step).
#       step += 1.
#     ].
#   ].
# 
#   [ forEach: Block<value: ValueType, index: Number> do, while: Block<Boolean> condition |
#     Number step := 0.
#     [ Boolean | return (step <= size) and: condition. ] whileTrue: [
#       do value: (self at: step) index: step.
#       step += 1.
#     ].
#   ].
# 
# here is a definition of map (not very optimal, but one at least)
# type Map<KeyType, ValueType>
#   List<KeyType> keys.
#   List<ValueType> values.
# 
#   # new is implemented primitively
#   primitive static [ Map<KeyType, ValueType> new ].
# 
#   [ Number indexFor: KeyType key |
#     Number index := -1.
#     keys forEach: [ value: KeyType otherKey, index: Number currentIndex |
#       (aKey = otherKey) ifTrue: [
#         index := currentIndex.
#       ].
#     ] while: [
#       return index != -1.
#     ].
#     return index.
#   ].
# 
#   [ ValueType at: KeyType aKey |
#     return values at: (self indexFor: aKey).
#   ].
# 
#   [ at: KeyType key, set: ValueType newValue |
#     values at: (self indexFor: aKey) set: newValue.
#   ].

# vim: tabstop=2:shiftwidth=2:softtabstop=2:filetype=nl
