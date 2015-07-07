# this are just tests to check if the syntax can support pattern matching

# factorial:Number -> Number

# base case
{ factorial: 0 | 1 }

# general case
{ factorial: Number n |
  n * (factorial: (n - 1))
}


# drop:Number from:List -> List

# base case 1 (drop nothing, return the same list)
{ drop: 0 from: [] list | list }

# general case
{ drop: Number n from: [] list |
  [item for item, index in list when index > n]
}


# take:Number from:List -> List

# base case (take nothing from a list, return empty list)
{ take: 0 from: [] _ | [] }

# general case
{ take: Number n from: [] list |
  [item for item, index in list when index < n]
}


# another example
# map:List using:Block -> List

# base case (map the empty list, return the empty list)
{ map: [] list using: {} _ | [] }

# general case
{ map: [] list using: {value:_} block |
  [(block value: item) for item in list]
}
