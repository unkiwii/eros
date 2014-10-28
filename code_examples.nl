# importing a file in same folder
import aFile.nl
import aLib.nlib

# importing a file in a subfolder
import foo/aFile.nl
import foo/bar/aLib.nlib

# importing a file in a parent folder
import ../aFile.nl
import ../../aLib.nlib
import ../foo/aFile.nl
import ../foo/bar/aLib.nlib

# anonymous block with no parameters
# it's not evaluated nor had a name so it's useless and illegal.
[ Console println: 9999. ].

# evaluating an anonymous block with no parameters
[ Console println: 9999. ] value.
# it would have the same result to had written:
[ value | Console println: 9999. ] value.
# every block with no parameters had a 'value' method so you can evaluate it

# ERROR: "block has no method 'value:', maybe you want to evaluate 'value' instead."
[ Console println: 9999. ] value: "hello".

# evaluating a block with a parameter
# the name of the block is 'print:'
# the signature of the block is '[ print: String ]'
[ print: String aString | Console println: aString ] print: "hello".

# that block had a name 'print:' so you can call it later
print: "hello".

# the ':' in the name of a block is not required, but useful
# you can write a block of code just like this
[ print String aString | Console println: aString ].

# that block had a name 'print' so you can call it later
print "hello".

# evaluating a block with more than one parameter
# the name of the block is 'print:and:'
# the signature of the block is '[ print: String, and: Number ]'
[ print: String aString, and: Number aNumber | Console println: aString + aNumber ] print: "hello" and: 1234.

# that block had a name 'print:and:' so you can call it later
print: "hello" and: 1234.

# ERROR: "block 'print: Number, and: String' does not exists, maybe you want to
# evaluate 'print: String, and: Number' instead
print: 1234 and: "hello".

# ERROR: "block 'print: String, and: Number' was evaluated with 'and: Number',
# maybe you want to evaluate 'print: String and: Number' instead."
[ print: String aString, and: Number aNumber | Console println: aString + aNumber ] and: 123.

# named block with no parameters and no return type
# just assign the block to a variable of type 'Block<>'
Block<> doSomething := [ Console println: 9999. ].

# evaluating a named block with no parameters
# remember: a block with no parameters has a method called 'value' to evaluate it.
doSomething value.

# ERROR: "'Block doSomething' has no method 'value:', maybe you want to evaluate 'value' instead."
doSomething value: 9999.

# named block with parameters
Block<with: String> doSomething := [ with: String aString | Console println: aString. ].

# evaluating a named block with parameters
doSomething with: "hello".

# ERROR: "'Block doSomething' has no method 'value', maybe you want to evaluate 'with:' instead."
doSomething value.

# a block with a return type
# this Block returns a Boolean
[ Boolean isNull: Object anObject |
  return (anObject is null).
].

# evaluating a block that return something (useless because we do not use the result)
isNull: anObject

# using the result of a returning block
(isNull: anObject) ifTrue: [
  # this is the way to write an "if" in this language
].

# ERROR: "'isNull' doesn't exist, maybe you want to evaluate 'isNull: Object' instead"
isNull.

# named block with parameters and return type
# Block<ReturnType param1: Type, param2: Type, ....>
Block<String with: Object> doSomething := [ String with: Object anObject |
  String name := anObject name.
  Console println: name.
  return name.
].

# evaluating a named block with parameters that returns something
String result := doSomething with: anObject.


# define a new type (or class)
type TestObject
  # define an instance variable:
  #   it must be initialized ALWAYS
  #   this is always private, never public
  #   every instance has it's own copy of this
  Number power := 9001.

  # define a "class" (static) variable:
  #   this is always private, never public
  #   every instance has access to the SAME copy of this
  #   and there are only one copy of this
  static String name := "TestObject".

  # define "setter" and "getter" for instance variables:
  #   this are just common instance methods that just access private variables
  #   getter name: 'power', returns the 'Number power' instance variable
  [ Number power |
    return power.
  ].
  #   setter name: 'power', returns the Number power
  [ power: Number aNumber |
    power := aNumber.
  ].

  # define an instance method:
  #   this is always public, never private
  #   doesn't receive anything and returns nothing
  [ printPower | Console println: power. ].

  # define another instance method
  #   this is always public, never private
  #   receives a Number and returns a Number
  #   the result of the last statement is the returned object.
  #   in this case: 'Number power'
  [ Number add: Number aNumber |
    power := power + aNumber.
  ].

  # define a "class" method
  #   this is always public, never private
  #   just add static in front of the block
  #   this is a getter for the 'static String name' object
  static [ String name |
    return name.
  ].


## using the new type

# accessing static members:
#   this calls the method 'static name' not the static variable
#   variables are always private, methods are always public
TestObject name.

# creating a new instance:
#   every object has a 'new' method for creating instances of it
#   'new' is a static method
TestObject test := TestObject new.

# using the created instance:
#   this gets the 'Number power' object by evaluating it's "getter"
#   this method signature is 'TestObject [ (Number) power ]'
#   is a method of type TestObject that returns a Number but receives nothing
#   the returned power is the Number '9001'
test power.
#   this sets the 'Number power' object to a new power by evaluating it's "setter"
#   this method signature is 'TestObject [ power: Number ]'
#   is a method of type TestObject that returns nothing but receives a Number
#   now power is '123'
test power: 123.

#   this adds 5 to the last value of power
#   this method signature is 'TestObject [ (Number) add: Number ]'
#   is a method of type TestObject that returns a Number and receives a Number
#   now power is '128'
#   the result value is not used
test add: 5.

#   the result value is used here, in another call
#   and it's stored in a new object of type Number
#   this object is the same as the 'power' inside 'test'
#   the return value is not copied, it's just referenced by 'thePower'
Number thePower := test add: 2.

#   this changes the value to 'thePower' from '130' to '8888'
thePower := 8888.

#   so this will also return the Number '8888'
#   because 'power' and 'thePower' references the same Number object
test power.

#   if you want to copy the returned value just copy it like this:
type TestObject
  [ Number add: Number aNumber |
    power := power + aNumber.
    # this last sentence will copy the object and return the new copy
    # by default objects are not copied, just referenced with another name
    return power copy.
  ].


# there is an "Object" that is a superclass of all objects in the language
# if you do not subclass a specific object then you are subclassing this type
# it will hold methods like 'new' and 'copy' that are implemented natively
type Object
  # every object in the language has an id
  Number id := 0.

  # a read-only getter for the id (never a setter or a getter that gives you the reference)
  [ Number id |
    return id copy.
  ].

  # every object knows it's type
  Type ownType := Object.

  # a read-only getter for the type (never a setter or a getter that gives you the reference)
  [ Type ownType |
    return ownType copy.
  ].

  # Object comparison using 'is'
  [ Boolean is Object anObject |
    return (self id = anObject id).
  ].

  # here, 'primitive' says it's implemented by the compiler
  # but can be overriden by any child
  primitive static [ Object new ].

  # same here, the compiler will write the body of this method
  primitive [ Object copy ].


type TestObject # extends Object (this is implicit, you can make it explicit)
  # override the 'new' method
  static [ Object new |
    # in other languages you can call the 'super' method like: 'super new.'
    # and then write your own code, or before, or in the middle, but not here,
    # the 'super' doesn't exist. when you override a method, you are just
    # adding code to the end of the 'super' method
  ].


# here is an example of an abstract type
type Boolean
  # in C++ you can define a 'pure virtual' function
  # here, you declare just their interfaces, not their bodies

  # Boolean has a method 'ifTrue:' that receives a Block and returns nothing
  # the '[ aBlock ]' type means a block of code that receives nothing and returns nothing
  # it's name is 'aBlock'
  abstract [ ifTrue: Block<> aBlock ].

  # Boolean has another method 'ifFalse:'
  # but this are interfaces, so parameters names are not required
  abstract [ ifFalse: Block<> ].

  # here is another interface with more parameters
  # again, this is an interface, so parameters with no names are fine
  abstract [ ifTrue: Block<>, ifFalse: Block<> ].

  # here is another interface
  # note that 'ifTrue:ifFalse' is not the same that 'ifFalse:ifTrue'
  abstract [ ifFalse: Block<>, ifTrue: Block<> ].

  # here is an interface that receives a block that returns something
  # 'or:' is a method that returns a Boolean and receives another block of code
  # that is evaluated if this object is True, so the block that receives must
  # return 'Boolean'
  abstract [ Boolean or: Block<Boolean> ].

  # the same with and:
  abstract [ Boolean and: Block<Boolean> ].


# here is an example of extending another type (subclassing)
# we can have simple inheritance only, never multiple inheritance
type True extends Boolean
  # here, every parameter needs a name because this is a concrete method, not abstract
  # and with that name it can be used inside the body of the method
  [ ifTrue: Block<> aBlock |
    # evaluate 'aBlock' since the receiver is True.
    aBlock value.
  ].

  # this is just an empty method, it receives a block but does nothing
  # it will be replaced not by a call to a method, but by a 'noop'
  [ ifFalse: Block<> aBlock ].

  [ ifTrue: Block<> trueBlock, ifFalse: Block<> falseBlock |
    # evaluate 'trueBlock' since the receiver is True.
    trueBlock value.
  ].

  [ ifFalse: Block<> falseBlock, ifTrue: Block<> trueBlock |
    # evaluate 'trueBlock' since the receiver is True.
    trueBlock value.
  ].

  [ Boolean or: Block<Boolean> alternativeBlock ].
    # answer self since the receiver is True.
    return self.
  ].

  [ Boolean and: Block<Boolean> alternativeBlock ].
    # answer the result of evaluating alternativeBlock since the receiver is True.
    return alternativeBlock value.
  ].


# we defined True, now we will define False
type False extends Boolean
  # this is just an empty method, it receives a block but does nothing
  # it will be replaced not by a call to a method, but by a 'noop'
  [ ifTrue: Block<> aBlock ].

  [ ifFalse: Block<> aBlock |
    # evaluate 'aBlock' since the receiver is False.
    aBlock value.
  ].

  [ ifTrue: Block<> trueBlock, ifFalse: Block<> falseBlock |
    # evaluate 'falseBlock' since the receiver is False.
    falseBlock value.
  ].

  [ ifFalse: Block<> falseBlock, ifTrue: Block<> trueBlock |
    # evaluate 'falseBlock' since the receiver is False.
    falseBlock value.
  ].

  [ Boolean or: Block<Boolean> alternativeBlock ].
    # answer the result of evaluating alternativeBlock since the receiver is False.
    return alternativeBlock value.
  ].

  [ Boolean and: Block<Boolean> alternativeBlock ].
    # answer self since the receiver is False.
    return self.
  ].


# NOTE: there are 2 "global variables" in the environment: 'true' and 'false', both are instances of types 'True' and 'False'
# future calls to 'True new.' and 'False new.' will return the same objects, they will never return a new Boolean.
# also 'true' and 'false' are keywords, they cannot be used as a name to nothing else
Boolean true := True new.
Boolean false := False new.


# as you can see the Boolean objects are not part of the language, they are just 2 more types in the standard library
# here are some examples of conditionals (also not part of the language)
Boolean state := true.

state ifTrue: [
  # do something here
].

state ifFalse: [
  # this will never be called because 'state' is 'true'
].

# operators can exist in this language, for example with type Number
type Number
  # the name of the next method is just '<' as the less-than operator in many languages
  # it receive a number, compare it with 'self' and return 'true' if this Number is
  # less than the Number received by parameter.
  # is implemented primitively
  primitive [ Boolean < Number ].

  # the name of the next method is just '=' as the equals operator in many languages
  # it's the same operator that '==' in C or JavaScript for Numbers
  # it receive a number, compare it with 'self' and return 'true' if this Number is
  # equals than the Number received by parameter.
  primitive [ Boolean = Number ].

  # same for other operators as '>', '>=' and '<='
  # ...

  # for basic arithmetic we will have the '+', '-', '*', and '/' operators
  primitive [ Number + Number ].
  primitive [ Number - Number ].
  primitive [ Number * Number ].
  primitive [ Number / Number ].


# back to Booleans
Number age := someObject someMethod.

(age < 18) ifTrue: [
  # code to be executed when age is less than 18
] ifFalse: [
  # code to be executed when age is NOT less than 18
].

# those were the conditionals of our language, but here are the loops:

# range-loop (for)
1 to: 10 do: [ Number step |
  # this will print every number from 1 to 10 (inclusive) in a new line
  Console println: step.
].

# [ to: Number, do: Block<value: Number> ] is defined in the type Number
# and it use a loop (while) to perform it's job
type Number
  [ to: Number end, do: Block<value: Number> aBlock |
    Number step := self.
    [ Boolean | return step <= end. ] whileTrue: [
      aBlock value: step.
      step add: 1.
    ].
  ].

# [ whileTrue: Block<> ] is defined in the type Block
type Block
  [ whileTrue: Block<> aBlock |
    (self value) ifTrue: [
      aBlock value.
      self whileTrue: aBlock.
    ].
  ].

# parametrizized types!
# as in C++ and C# you can have templates (or Generics)
# here is a list (this is like a C array, a contiguous piece of memory)
List<String> aListOfStrings := List<String> new: 40.

# here is a map
Map<String, Object> aDictionary := Dictionary<String, Object> new.

# here is a definition of List<T>
type List<ValueType>
  Number size := 0.

  # new is implemented primitively
  primitive static [ List<ValueType> new: Number size ].

  # accesors like [] in C to get and set values at different indices
  primitive [ ValueType at: Number index ].

  primitive [ at: Number index, set: ValueType value ].

  # for each...
  [ forEach: Block<value: ValueType> do |
    0 to: size do: [ value: Number step |
      do value: (self at: step).
    ].
  ].

  [ forEach: Block<value: ValueType, index: Number> do |
    0 to: size do: [ value: Number step |
      do value: (self at: step) index: step.
    ].
  ].

  [ forEach: Block<value: ValueType> do, while: Block<Boolean> condition |
    Number step := 0.
    [ Boolean | return (step <= size) and: condition. ] whileTrue: [
      do value: (self at: step).
      step += 1.
    ].
  ].

  [ forEach: Block<value: ValueType, index: Number> do, while: Block<Boolean> condition |
    Number step := 0.
    [ Boolean | return (step <= size) and: condition. ] whileTrue: [
      do value: (self at: step) index: step.
      step += 1.
    ].
  ].

# here is a definition of map (not very optimal, but one at least)
type Map<KeyType, ValueType>
  List<KeyType> keys.
  List<ValueType> values.

  # new is implemented primitively
  primitive static [ Map<KeyType, ValueType> new ].

  [ Number indexFor: KeyType key |
    Number index := -1.
    keys forEach: [ value: KeyType otherKey, index: Number currentIndex |
      (aKey = otherKey) ifTrue: [
        index := currentIndex.
      ].
    ] while: [
      return index != -1.
    ].
    return index.
  ].

  [ ValueType at: KeyType aKey |
    return values at: (self indexFor: aKey).
  ].

  [ at: KeyType key, set: ValueType newValue |
    values at: (self indexFor: aKey) set: newValue.
  ].

# with just that methods and types you have bifurcation and repetition, essential to any
# programming language, or as many of us were presented:
#
#   Conditionals (if, if else, if elseif)
#   Range Loops (for)
#   Loops (while, do while)

# MORE IS COMING!

# vim: tabstop=2:shiftwidth=2:softtabstop=2:filetype=nl
