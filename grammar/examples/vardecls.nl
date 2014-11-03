# string (value)
SomeType anIdentifier := "some string"

# number (value)
SomeType anIdentifier := 123
SomeType anIdentifier := 3.1415

# boolean (value)
SomeType anIdentifier := true
SomeType anIdentifier := false

# identifier (value)
SomeType snIdentifier := anotherIdentifier
SomeType anIdentifier := SomeType

# blocks (blockValue)
SomeType anIdentifier := eval
SomeType anIdentifier := [ eval ]
SomeType anIdentifier := [ Boolean | eval ]
SomeType anIdentifier := [ Boolean value | eval ]
SomeType anIdentifier := [ Boolean value: String v | eval ]
SomeType anIdentifier := [ Boolean value: String v fork: Boolean fuck | eval ]
