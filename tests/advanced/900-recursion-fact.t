let recursion F = (\u -> u u) (\x -> F (\v -> x x v)) in
let fact = recursion
  (\fact n -> if n <= 0
               then 1
               else n * fact (n - 1)) in
fact 10
