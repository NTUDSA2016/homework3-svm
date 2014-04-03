//logical "operators" `and`, `or`, `not`
(\and ->
 \or  ->
 \not ->
    (\n -> 
      not @(and @(1 <= n) @(n <= 10)))
     @8)
 @(\x -> \y -> if x then y else 0)
 @(\x -> \y -> if x then 1 else y)
 @(\x -> if x then 0 else 1)
