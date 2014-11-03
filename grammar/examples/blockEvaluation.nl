# evaluating a block by it's name
printMessage

# evaluating with value (same as above)
printMessage value

# calls with just 1 parameter
print: "string"
print: 123.45
print: false
print: someVariable
print: SomeType

# more parameters
print: "string" in: 123
print: "string" in: 123 with: moreThanOneArg
print: "string" in: 123 with: moreThanOneArg and: Type

# evaluating "lambdas"
[ Boolean | boolValue ]
[ Boolean | boolValue ] value
[ Boolean print: String msg | msg length ] print: "something"
[ Boolean do: String aString, i: SomeType anObject | boolValue ] do: "as" i: please
[ Boolean do: String aString, i: SomeType anObject, with: Type aType | boolValue ] do: "as" i: please with: Type

# evaluating identifiers (Block anIdentifier := [...])
anIdentifier value
anIdentifier print: "something"
anIdentifier do: "as" i: please
anIdentifier do: "as" i: please with: Type

# evaluating types (static methods)
SomeType value
SomeType print: "something"
SomeType do: "as" i: please
SomeType do: "as" i: please with: Type

# evaluating using self
self value
self print: "something"
self do: "as" i: please
self do: "as" i: please with: Type
