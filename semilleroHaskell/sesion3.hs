aplicarUnaVez :: (Integer -> Integer) -> Integer -> Integer
aplicarUnaVez f x = f x
-- es equivalente a haberlo puesto asi: aplicarUnaVez f = f
-- esta funcion lo que hace es aplicar una vez la funcion de entero a entero con el parametro entero 
-- que se le pase.

aplicarDosVeces :: (Integer -> Integer) -> Integer -> Integer
aplicarDosVeces f x = f (f x)
--aplicarDosVeces f = \x -> f  (f x)
--esta funcion aplica dos veces la funcion que se le mande con el parametro que se le mande.

derivada :: (Float -> Float) -> Float -> Float
derivada f x = (f (x + h) - f x) / h
	where h = 0.000000000000000001
-- definicion matematica de la derivada.

logEnBase :: Float -> (Float -> Float)
logEnBase b = \x -> log x / log b

factorial5 :: Integer -> Integer
factorial5 1 = 1
factorial5 n = ( * ) n (factorial5 (n - 1))

sumatoria :: Integer -> Integer
sumatoria 0 = 0
sumatoria n = ( + ) n (sumatoria (n - 1))

-- las dos funciones anteriores siguen un mismo patron, por lo que se pueden parametrizar de la 
-- siguiente manera.

iter :: (Integer -> Integer -> Integer) -> Integer -> Integer -> Integer
iter op e 0 = e
iter op e n = op n (iter op e (n - 1))

factorial5' :: Integer -> Integer
factorial5' = iter (*) 1

sumatoria' :: Integer -> Integer
sumatoria' = iter ( + ) 0

potencia :: Integer -> Integer -> Integer
potencia b 0 = 1
potencia b n = b * potencia b (n - 1)
-- reescribir esta funcion usando lo funcion de iteracion.

potencia' :: Integer -> (Integer -> Integer)
potencia' b = iter (op) 1
	where op _ r = b * r

potencia'' :: Integer -> Integer -> Integer
potencia'' b = iter (\_ y -> b * y) 1

idInteger :: Integer -> Integer
idInteger x = x

idChar :: Char -> Char
idChar x = x

-- en las dos anteriores funciones hay un patron que se repite por lo que podemos mejorar esta 
-- situacion.

identidad :: a -> a
identidad x = x

aplicarUnaVez' :: (a -> b) -> a -> b
aplicarUnaVez' f x = f x 

-- las dos ultimas funciones son independientes del tipo, la variable a significa que puede recibir
-- cualquier tipo.
aplicarDosVeces' :: (a -> a) -> a -> a
aplicarDosVeces' f x = f ( f x )

aplicarDosVeces'' :: (a -> a) -> a -> a
aplicarDosVeces'' f x = (f . f) x
-- con etha reduccion seria aplicarDosVeces'' f = f . f a lo cual se le llama programacion sin args.
-- el punto es la composicion de funciones. FoG(x)
-- generalicemos la funcion iter.

iter' :: (Integer -> a -> a) -> a -> Integer -> a 
iter' op e 0 = e
iter' op e n = op n (iter' op e (n - 1))

veces :: (a -> a) -> Integer -> a -> a
veces g 1 = g
veces g n = g . (veces g (n - 1))

veces' :: (a -> a) -> Integer -> a -> a
veces' f n = iter' op f (n - 1)
	where op _ r = (f.r)

veces'' :: (a -> a) -> Integer -> a -> a
veces'' f n = iter' (\_ r -> f.r) f (n - 1)

--veces sirve para aplicar una misma funcion sobre el resultado de la aplicacion anterior n veces.

--asi se declaran operadores, en este caso estamos definiendo uno para que la composicion se pueda
-- hacer en el orden inverso.
(#) :: (a -> b) -> (b -> c) -> a -> c
f # g = g . f