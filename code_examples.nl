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


# block with no parameters
# Block<ReturnType>
Block<None> doSomething = [
    Console println: 9999 asString.
].

# calling a block with no parameters
doSomething value.

# error: "'Block doSomething' has no method 'value:', maybe you want to invoke 'value' instead."
doSomething value: 9999.

# lambda with no parameters (this is useless, a lambda must be invoked or stored in a variable or it's destroyed immediately)
[ Console println: 9999 asString. ].

# calling a lambda with no parameters
[ Console println: 9999 asString. ] value.

# error: "'lambda' has no method 'value:', maybe you want to invoke 'value' instead."
[ Console println: 9999 asString. ] value: 'hello'.

# block with one parameter
# Block<ReturnType, FirstParameter>
Block<None, Object> isNull: Object = [ anObject |
    return anObject is Null.
].

# calling a block with parameters.
isNull: anObject.

# error: "a parameter is expected after ':'"
isNull:.

# error: "'isNull' does not exists, maybe you want to call 'isNull: Object' instead".
isNull.


type BlackHole
    static BlackHole instance.  # 'instance' type variable > private

    static Block<BlackHole> instance = [    # 'instance' type method > public
        return instance.
    ].

    # '?...' means can receive anything from 0 to infinite parameters
    # (this is just a notation, in user's code this will be illegal)
    Block<?...> value = [ ]. # do nothing.


type Boolean
    using UnaryBlock as Block<Void, Block<Void>>.   # same as typedef in C++

    UnaryBlock ifTrue: = interface.     # same as 'virtual = 0' in C++

    UnaryBlock ifFalse: = interface.    # same as 'virtual = 0' in C++

    using DoubleBlock as Block<Void, Block<Void>, Block<Void>>. # same as typedef in C++

    DoubleBlock ifTrue: ifFalse: = interface.   # same as 'virtual = 0' in C++

    DoubleBlock ifFalse: ifTrue: = interface.   # same as 'virtual = 0' in C++

    using BooleanBlock as Block<Void, Block<Boolean>>.

    BooleanBlock or: = interface.

    BooleanBlock and: = interface.


type True extends Boolean
    UnaryBlock ifTrue: = [ aBlock | aBlock value. ].    # invoke aBlock

    UnaryBlock ifFalse: = BlackHole instance.   # do nothing and no matter how you call it it will not throw any error.

    DoubleBlock ifTrue: ifFalse: = [ trueBlock falseBlock |
        trueBlock value.    # invoke the trueBlock (because this is True)
    ].

    DoubleBlock ifFalse: ifTrue: = [ falseBlock trueBlock |
        trueBlock value.    # invoke the trueBlock (because this is True)
    ].

    BooleanBlock or: = [ aBlock |
        return self.    # answer self since the receiver is True
    ].

    BooleanBlock and: = [ aBlock |
        return (aBlock value).  # answer the evaluated value of aBlock
    ].


type False extends Boolean
    UnaryBlock ifTrue: = BlackHole instance.    # do nothing and no matter how you call it it will not throw any error.

    UnaryBlock ifFalse: = [ aBlock | aBlock value. ].   # do nothing

    DoubleBlock ifTrue: ifFalse: = [ trueBlock falseBlock |
        falseBlock value.    # invoke the falseBlock (because this is True)
    ].

    DoubleBlock ifFalse: ifTrue: = [ falseBlock trueBlock |
        falseBlock value.    # invoke the falseBlock (because this is True)
    ].

    BooleanBlock or: = [ aBlock |
        return (aBlock value).  # answer the evaluated value of aBlock
    ].

    BooleanBlock and: = [ aBlock |
        return self.    # answer self since the receiver is False
    ].


type Block<ReturnType, ArgumentsType...> = primitive.   # the whole Block type is implemented primitively


# OOP while

## definition
type Block<Boolean>     # you can define specific methods for a 'templated' type
    Block<Void, Block<Void>> whileTrue: = [ aBlock |
        (self value) ifTrue: [
            aBlock value.
            self whileTrue: aBlock.     # recursive call
        ].
    ].

## invocation
[condition] whileTrue: [do].


# Functional while

## definition
Block<Void, Block<Boolean>, Block<Void>> while: isTrue: = [ aCondition aBlock |
    (aCondition value) ifTrue: [
        aBlock value.
        while: aCondition isTrue: aBlock.   # recursive call
    ].
].

## invocation
while: [condition] isTrue: [do].


# block with multiple parameters
# the signature is: 'from: Number to: Number do: Block'

# option 1
Block from: Number to: Number do: Block = [ start end aBlock |
    while: [start < end] isTrue: [
        aBlock value: start.
        start add: 1.
    ].
].

# option 2
Block from: Number start to: Number end do: Block aBlock = [
    [start < end] whileTrue: [
        aBlock value: start.
        start add: 1.
    ].
].

# option 3
Block<Void, Number, Number, Block<Void, Number>> from: start to: end do: aBlock = [
    [start < end] whileTrue: [
        aBlock value: start.
        start add: 1.
    ].
].

# calling a block with multiple parameters
from: 9999 to: 9999 do: [ index |
    Console println: index.
].






type Object
    Boolean is: anObject
        return (self id) equals (anObject id)       

type String
    ...

# a way to define a new type
type Number # primitive
    Boolean equals aNumber
        return (self value) == (aNumber value)

# another way to define a new type
Type new:	Boolean.
	  	hola

Boolean method: 'ifTrue' code: [
    
].
