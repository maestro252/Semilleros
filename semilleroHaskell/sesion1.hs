
--esto es un commentario
fol :: Integer -> Integer
fol x = x + 1

doble, triple :: Integer -> Integer
triple x = x + x + x
doble x = x + x --x*2

--nunca termina
inf :: Integer
infinito = 1 + inf

cero x = 0

function :: ()
function = ()

retornar2 :: Integer -> (Integer, Integer)
retornar2 x = (x * 2, x `mod` 2)

retornar3 :: Integer -> (Integer, Integer, Integer)
retornar3 x = (x * 2, x `mod` 2, x)

get :: Int -> (Integer, Integer, Integer) -> Integer
get 1 (a,b,c) = a
get 2 (a,b,c) = b
get 3 (a,b,c) = c
get _ _	      = error "No hay patron valido"

longitud :: [Integer] -> Int
longitud [] = 0
longitud (x:xs) = 1 + longitud xs

sumarLista :: [Integer] -> Int
sumarLista [] = 0
sumarLista (x:xs) = x + sumarLista xs