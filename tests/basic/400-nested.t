if (2 - (\x -> if x <= 2 then 3 <= 2 else 1)@3 - 1)
  then 8
  else
    (if 2^3 <= 4 <= 5
      then 1 - (\u -> u-1)@2
      else
        (if 2 <= 13
          then (\z -> 13)@6
          else (\x -> 514)@7))
