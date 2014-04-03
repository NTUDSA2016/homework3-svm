//scoping: the two 'x's are independent
(\x -> x + (\x -> x*3)@3 * x)@5
