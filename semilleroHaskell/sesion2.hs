--funcion valor absoluto. Sirve de ejemplo de definicion por casos de una funcion como se hace
--en la matematica.
absoluto :: Integer -> Integer
absoluto x 
	| x > 0 = x
	| x == 0 = 0
	| x < 0 = -x

--otra manera de definir la funcion
--otherwise es siempre verdadero, asi que si llega alli entrara.
absoluto' :: Integer -> Integer
absoluto' x
	| x > 0 = x
	| x == 0 = 0
	| otherwise = -x

--definicion por casos del factorial.

factorial :: Integer -> Integer
factorial n 
	| n < 0 = error "Entre numeros positivos"
	| n == 0 = 1
	| n == 1 = 1
	| otherwise = n * factorial (n - 1)

factorial' :: Integer -> Integer
factorial' 0 = 1
factorial' 1 = 1
factorial' n = n * factorial (n - 1)

factorial3 :: Integer -> Integer
factorial3 n = case n of
	0 -> 1
	1 -> 1
	n -> n * factorial3 (n - 1)

factorial4 :: Integer -> Integer
factorial4 n = if n == 1 then 1 else n * factorial4 (n - 1)

--el tipo de dato que devuelve en el then y en el else debe ser el mismo
--de lo contrario saca error.
{--
raices :: Float -> Float -> Float -> (Float, Float)
raices a b c 
	| d >= 0 				= ((-b + ra) / denom , (-b - ra) / denom)
	| otherwise 			= error "Raices complejas"
	where d = b^2 - 4*a*c
	      ra = sqrt d
		  denom = 2 * a
--}
--funciones lambda
aplicarID :: Int -> Int
aplicarID x = (\y -> y) x

funcion :: Int -> Int -> Int
funcion x y = if x < y
				then x
				else y

pruebaFuncion1 :: Integer -> Integer
pruebaFuncion1 x = x * h 7
	where h z = x + 5 + z^2

pruebaFuncion1' :: Integer -> Integer
pruebaFuncion1' x = let h z = x + 5 + z^2
					in x * h 7
--let es el "sea" de la matematica, permite definir funciones localmente, tanto como variables.

incr :: Integer -> Integer
incr x = x + 1

incr' :: Integer -> Integer
incr' = \x -> x + 1

--Estas ultimas dos funciones hacen exactamente lo mismo, pero haskell lleva una funcion realmente
--a calculo lambda, la funcion incr se traduce internamente a incr'.

sumarCuadrados :: Integer -> (Integer -> Integer)
sumarCuadrados = \x -> (\y -> x * x + y * y)

-- una aplicacion parcial de una funcion, o CURRIFICACION, es mandar menos parametros de los que se
--piden y asi se devuelve una funcion. 

multiploDe :: Integer -> Integer -> Bool
multiploDe p n = n `mod` p == 0

esPar :: Integer -> Bool
esPar = multiploDe 2

-- un claro ejemplo de currificacion, se aplica incompletamenta la funcion para que retorne una 
--funcion.

multiploDe' :: (Integer, Integer) -> Bool
multiploDe' (p,n) = n `mod` p == 0


