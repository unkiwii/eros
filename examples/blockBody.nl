# one line, no return type, no parameters
[ printMessage | Console println: "Hello World!". ].

# same as above, but in multiple lines
[ printMessage |
  Console println: "Hello World!".
].

# one line, with return type but no parameters
[ String name | name. ].
[ String name | self name. ].
[ String name | print: "hola". ].
[ String name | self print: "hola". ].

# same blocks than above, but in multiple lines
[ String name |
  name.
].

[ String name |
  self name.
].

[ String name |
  print: "hola".
].

[ String name |
  self print: "hola".
].

# 2 parameters, one line
[ Boolean compare: Object anObject, with: Object anotherObject | anObject is anotherObject. ].

# 2 parameters, multi line
[ Boolean compare: Object anObject, with: Object anotherObject |
  anObject is anotherObject.
].

# 2 parameters, multi line, "operators"
[ Boolean compare: Number a, with: Number b |
  a > b.
  a < b.
  a <= b.
  a >= b.
  a = b.
  a + b.
  a * b.
  a - b.
  a / b.
].

# operator-like declaration (inside type Number)
[ Number + Number a |
  self plus: a.
].

# same as above, multiple lines
# [ Boolean isChristmas |
#   Type fuck.
#   Date christmas := Date day: 25 month: 12 year: Date year.
#   christmas equals: (Date today).
# ].
