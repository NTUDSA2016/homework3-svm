//function composition
// (f o g)(t) = t^2 + 1,
// (g o f)(t) = (t + 1)^2
(\comp ->

  (\f ->
   \g ->
   (comp@f@g)@2 - (comp@g@f)@3) // = (2^2 + 1) - (3 + 1)^2
   @(\x -> x + 1) //where f(x) = x+1
   @(\y -> y^2))  //where g(y) = y^2

 @(\f -> \g -> \x -> f@(g@x))
