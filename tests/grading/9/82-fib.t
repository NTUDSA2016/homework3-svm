(\u -> u @ u) @ (\x___ -> \n -> if n <= 1 then n else x___ @ x___ @ (n - 1) - x___ @ x___ @ (n - 2)) @ 25