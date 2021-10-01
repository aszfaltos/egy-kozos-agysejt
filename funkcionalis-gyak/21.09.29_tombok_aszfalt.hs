module Gyak4 where

import Prelude hiding (head, tail, length, sum)

-- Listagenerátorok (http://lambda.inf.elte.hu/Comprehensions.xml)
-- Matematikai jelölésnek megfelelően
-- Generátorok, feltételek
-- Több generátor használata

-- Néhány listákkal kapcsolatos hasznos függvény:
-- zip, take, drop, concat, words, unwords, elem

-- Mintaillesztés listákra

isEmpty :: [a] -> Bool
isEmpty [] = True
isEmpty _ = False

isSmall :: [a] -> Bool
isSmall [] = True
isSmall [_] = True
isSmall [_, _] = True
isSmall [_, _, _] = True
isSmall _ = False

isSmall' (_:_:_:_:_) = False
isSmall' _ = True

-- Ez a legfontosabb minta!!! (x:xs)
head :: [a] -> a
head (x:xs) = x

tail :: [a] -> [a]
tail (x:xs) = xs

-- Mire illeszkednek az alábbi minták?
-- []
-- [x]
-- (x:xs)
-- (xs:x)
-- (_:_)
-- [xs:x]
-- ([]:[])
-- (zs:b:z)      
-- ((x:y):xs)
-- ([x,_])
-- [(x,_)]
-- (x:y:[])
-- ((,) x y:_)
-- (xs:ys:zs)
-- ([xs:ys:_])
-- [_,_:xs]
-- [a,(x,y),_a]
-- (c:cs:[(x,xs)])
-- ([d]:[ds])


-- Rekurzió (http://lambda.inf.elte.hu/Recursion.xml)
fact :: Integer -> Integer
fact 0 = 1
fact x = x * (fact (x-1))

-- fact 3 
-- 3 * (fact 2)
-- 3 * (2 * (fact 1))
-- 3 * (2 * (1 * (fact 0)))
-- 3 * (2 * (1 * (1)))
-- 3 * (2 * 1)
-- 3 * 2
-- 6

fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib x = fib (x - 1) + fib (x - 2)


-- Hatékonyabban is lehet (extra anyag):
-- fib2 :: Integer -> Integer
-- fib2 n = fib' 0 1 n
--  where 
--    fib' a b 0 = a
--    fib' a b n = fib' (a+b) a (n-1)


-- * Gyakorlás: hatványozás (szorzást használva)
--pow :: Int -> Int -> Int

-- Rekurzió listákon
length :: [a] -> Int
length [] = 0
length (x:xs) = length xs+1

sum :: Num a => [a] -> a
sum [] = 0
sum (x:xs) = x + sum(xs)

-- * Gyakorlás
-- product :: Num a => [a] -> a

-- last :: [a]{-nemüres-} -> a
-- init :: [a]{-nemüres-} -> [a]

-- minimum :: Ord a => [a]{-véges, nemüres-} -> a
-- * Gyakorlás:
-- maximum :: Ord a => [a]{-véges, nemüres-} -> a


-- concat :: [[a]] -> [a]
-- (++) :: [a] -> [a] -> [a]


-- Elemek váltogatva
-- merge :: [a] -> [a] -> [a]

-- * Gyakorlás:
-- zip :: [a] -> [b] -> [(a,b)]

-- Prímek előállítása listagenerátorral, rekurzív segédfüggvénnyel
-- Módszer: Eratoszthenész szitája (https://hu.wikipedia.org/wiki/Eratoszthen%C3%A9sz_szit%C3%A1ja)
-- primes :: [Integer]