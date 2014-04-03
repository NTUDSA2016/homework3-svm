let recursion F = (\u -> u u) (\x -> F (\v -> x x v)) in
let fib = recursion
  (\fib n -> if n <= 1
              then 1
              else fib(n-1) + fib(n-2)) in
fib 6
