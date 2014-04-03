let x = 3 in
let f =
  let x = 5 in
  \z -> z + x
in f x
