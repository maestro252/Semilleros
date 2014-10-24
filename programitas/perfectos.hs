divisores :: Integer -> [Integer]
divisores n = [x | x <- [1 .. (n - 1)], n `mod` x == 0]

perfectos :: Integer -> [Integer] --lo que recibe es el limite.
perfectos n = [x | x <- [1 .. n], sum(divisores x) == x]

