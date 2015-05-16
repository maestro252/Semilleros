divisores :: Int -> [Int]
divisores a = [x | x <- [1..a], a `mod` x == 0]

primos :: Int -> Bool
primos n =  if length(divisores(n)) == 2 
            then True
            else False
