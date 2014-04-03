//user-defined sugar: assign@value@(\var -> expr)
//assigning `value` to `var` in `expr`
(\assign ->
  assign @5 @(\x ->
  assign @8 @(\y ->
  assign @(\s -> \t -> s^2 + t^2) @(\f ->
  f@(x + 1)@(y + 1) + 3))))
 @(\x -> \f -> f@x)
