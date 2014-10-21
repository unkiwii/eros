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
Block<Void> doSomething
    [ Console println: 9999 asString. ].

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

# calling a lambda with a parameter
[ String aString | Console println: aString ] value: 'hello'.

# calling a lambda with more than one parameter
[ String aString, Number aNumber | Console println: aString + (aNumber asString) ] value: 'hello' value: 1234.

# error: "'lambda' has no method 'value: Number', maybe you want to invoke 'value: String value: Number' instead."
[ String aString, Number aNumber | Console println: aString + (aNumber asString) ] value: 123.

# block with one parameter
# Block<ReturnType, FirstParameter>
Block<Void, Object> isNull:
    [ Object anObject |
        anObject is Null.
    ].

# calling a block with parameters.
isNull: anObject.

# error: "a parameter is expected after ':'"
isNull:.

# error: "'isNull' does not exists, maybe you want to call 'isNull: Object' instead".
isNull.


type BlackHole
    static BlackHole instance.  # 'instance' type variable > private

    static Block<BlackHole> instance    # 'instance' type method > public
    [ instance. ].

    # '?...' means can receive anything from 0 to infinite parameters
    # (this is just a notation, in user's code this will be illegal)
    Block<?...> value = [ ]. # do nothing.


type Boolean
    using VoidBlock as Block<Void>.     # same as typedef in C++, is visible in all this scope (and childs of this scope)

    using ReceiveVoidBlock as Block<Void, VoidBlock>.   # same as typedef in C++

    ReceiveVoidBlock ifTrue: = interface.     # same as 'virtual = 0' in C++

    ReceiveVoidBlock ifFalse: = interface.    # same as 'virtual = 0' in C++

    using ReceiveVoidBlockVoidBlock as Block<Void, VoidBlock, VoidBlock>. # same as typedef in C++

    ReceiveVoidBlockVoidBlock ifTrue: ifFalse: = interface.   # same as 'virtual = 0' in C++

    ReceiveVoidBlockVoidBlock ifFalse: ifTrue: = interface.   # same as 'virtual = 0' in C++

    using BooleanBlock as Block<Boolean>.

    using ReceiveBooleanBlock as Block<Void, BooleanBlock>.

    ReceiveBooleanBlock or: = interface.

    ReceiveBooleanBlock and: = interface.

    BooleanBlock | as or:.  # synonim for or: block
    BooleanBlock or as or:. # synonim for or: block

    BooleanBlock & as and:.     # synonim for and: block
    BooleanBlock and as and:.   # synonim for and: block


type True extends Boolean   # simple inheritance
    ReceiveVoidBlock ifTrue:    # 'ReceiveBlock' and 'VoidBlock' are visible because this type inherits it's parent scope
    [ VoidBlock aBlock |
        # evaluate aBlock since the receiver is True.
        aBlock value.
    ].

    ReceiveVoidBlock ifFalse: = BlackHole instance.   # do nothing and no matter how you call it it will not throw any error.

    ReceiveVoidBlockVoidBlock ifTrue: ifFalse: = [ VoidBlock trueBlock, VoidBlock falseBlock |
        # evaluate trueBlock since the receiver is True.
        trueBlock value.
    ].

    ReceiveVoidBlockVoidBlock ifFalse: ifTrue: = [ VoidBlock falseBlock, VoidBlock trueBlock |
        # evaluate trueBlock since the receiver is True.
        trueBlock value.
    ].

    BooleanBlock or: = [ BooleanBlock aBlock |
        # answer self since the receiver is True.
        self.
    ].

    BooleanBlock and: = [ BooleanBlock aBlock |
        # answer the result of evaluating aBlock since the receiver is True.
        aBlock value.
    ].


type False extends Boolean   # simple inheritance
    ReceiveVoidBlock ifTrue: = BlackHole instance.    # do nothing and no matter how you call it it will not throw any error.

    ReceiveVoidBlock ifFalse: = [ VoidBlock aBlock |
        # evaluate aBlock since the receiver is False.
        aBlock value.
    ].

    ReceiveVoidBlockVoidBlock ifTrue: ifFalse: = [ VoidBlock trueBlock, VoidBlock falseBlock |
        # evaluate falseBlock since the receiver is False.
        falseBlock value.
    ].

    ReceiveVoidBlockVoidBlock ifFalse: ifTrue: = [ VoidBlock falseBlock, VoidBlock trueBlock |
        # evaluate falseBlock since the receiver is False.
        falseBlock value.
    ].

    BooleanBlock or: = [ VoidBlock aBlock |
        # answer the result of evaluating aBlock since the receiver is False.
        aBlock value.  # without the parenteshis it will return aBlock
    ].

    BooleanBlock and: = [ VoidBlock aBlock |
        # answer self since the receiver is False.
        self.
    ].


type Block<ReturnType, ArgumentsType...> = primitive.   # the whole Block type is implemented primitively


type Block<ReturnType, ArgumentsType...>
    Block<Void> doSomething: = primitive.   # the 'doSomething' method is implemented primitively


# OOP while

## definition
type Block<Boolean>     # you can define a type as a specification of a 'template' type. this is not inheritance, is specification
    # specific methods for Block<Boolean> an no other type of Block<>

type BooleanBlock as Block<Boolean>     # you can also define a new type as a synonym of another type (its the same type with another name)
    Block<Void, Block<Void>> whileTrue: =
        [ Block<Void> aBlock |
            (self value) ifTrue: [
                aBlock value.
                self whileTrue: aBlock.     # recursive call
            ].
        ].

## invocation
[aBoolean] whileTrue: [doSomething].


# Functional while

## definition
Block<Void, Block<Boolean>, Block<Void>> while: isTrue: =
    [ Block<Boolean> aCondition, Block<Void> aBlock |
        (aCondition value) ifTrue: [
            aBlock value.
            while: aCondition isTrue: aBlock.   # recursive call
        ].
    ].

## invocation
while: [aBoolean] isTrue: [doSomething].


# block with multiple parameters
# the signature is: 'from: Number to: Number do: Block'

# with functional 'while'
Block<Void, Number, Number, Block<Void, Number>> from: to: do: =
    [ Number start, Number end, Block<Void, Number> aBlock |
        while: [start < end] isTrue: [
            aBlock value: start.
            start add: 1.
        ].
    ].

# with OOP 'while'
Block<Void, Number, Number, Block<Void, Number>> from: to: do: =
    [ Number start, Number end, Block<Void, Number> aBlock |
        [start < end] whileTrue: [
            aBlock value: start.
            start add: 1.
        ].
    ].

# calling a block with multiple parameters
from: 1 to: 10 do: [ Number index |
    Console println: index.
].
