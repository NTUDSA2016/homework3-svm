// (1 + 2 + ... + 1000000)%13131
let mod x y = x - y*(x/y) in
(\u -> u u) (\x ->
(\sum_iter acc n ->
  if n <= 0
    then acc
    else sum_iter (mod (n + acc) 13131) (n - 1))
(\v -> x x v))
0
3000000
