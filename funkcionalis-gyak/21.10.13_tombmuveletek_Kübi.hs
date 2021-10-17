module Gyak6 where

import Data.Char
import Prelude hiding((^), drop, take, insert)
-- Állítsuk elő egy lista összes lehetséges végződését! (A Data.List modulban már definiált.)
tails :: [a] -> [[a]]
tails [] = []
tails l@(x:xs) = l : tails xs

-- Állítsuk elő egy lista összes prefixét! (A Data.List modulban már definiált.)
inits :: [a] -> [[a]]
inits [] = [[]]
inits (x:xs) = [] : [x:i | i <- inits xs]

-- Egy elem törlése az összes lehetséges módon.
deletions :: [a] -> [[a]]
deletions [] = [[]]
deletions (x:xs) = xs : [x:d | d <- deletions (xs)]

-- Permutációk (http://lambda.inf.elte.hu/Recursion.xml#feladat-permut%C3%A1ci%C3%B3k)
-- Az összes lehetséges módon beszúr egy elemet
insertions :: a -> [a] -> [[a]]
insertions e [] = [[e]]
insertions e l@(x:xs) = (e:l) : [x:i | i <- insertions e xs]


permutations :: [a] -> [[a]]
permutatios [] = [[]]
permutations (x:xs) = concat [insertions x p | p <- permutations xs]

-- Őrfeltételek, esetszétválasztás (http://lambda.inf.elte.hu/Guards.xml)
-- otherwise == True
-- Esetszétválasztás (szükséges Data.Char (isUpper, isLower, toUpper, toLower))
upperLower :: Char -> Char
upperLower c
    | isLower c = toUpper c
    | isUpper c = toLower c
    | otherwise = c

sqr :: Num a => a -> a
sqr x = x*x

-- Gyorshatványozás
(^) :: Num a => a -> Integer -> a
x ^ 0 = 1
x ^ n
    | odd n = x * x ^ (n-1)
    | otherwise = sqr (x ^ (n `div` 2))

-- tizes -> kettes számrendszer
toBin :: Integer -> [Int]
toBin 0 = []
toBin n
    | even n = 0 : toBin (n `div` 2)
    | otherwise = 1 : toBin (n `div` 2)

-- Mintaillesztéses esetszétválasztás: Prelude.drop
drop :: Int -> [a] -> [a]
drop n xs | n<=0 = xs
drop _ [] = []
drop n (x:xs) = drop (n-1) xs    

-- Mintaillesztéses esetszétválasztás: Prelude.take
take :: Int -> [a] -> [a]
take n xs | n<=0 = []
take _ [] = []
take n (x:xs) = x : take (n-1) xs

-- Mintaillesztéses esetszétválasztás: Data.List.insert
insert :: Ord a => a -> [a] -> [a]
insert e [] = [e]
insert e (x:xs) 
    | e <= x = e : xs
    | otherwise = x : insert e xs

-- Kombinációk (ismétlés nélküli)
combinations :: Int -> [a] -> [[a]]
combinations 0 _ = [[]] 
combinations n _ | n < 0 = []
combinations n [] = []
combinations n (x:xs) = [x:c | c <- combinations (n-1) xs] ++ combinations n xs