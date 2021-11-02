module Gyak5 where

import Prelude hiding (last, init, minimum,
maximum, concat, (++))

last :: [a]{-nemüres-} -> a
last [x] = x
last (x:xs) = last xs

init :: [a]{-nemüres-} -> [a]
init[x] = []
init (x:xs) = x: init xs

minimum :: Ord a =>[a] {-véges, nemüres-} -> a
minimum [x] = x
minimum (x:xs) = min x (minimum xs)

maximum :: Ord a =>[a] {-véges, nemüres-} -> a
maximum [x] = x
maximum (x:xs) = max x (maximum xs)

concat :: [[a]] -> [a]
concat [] = []
concat (x:xs) = x ++ concat xs

(++) :: [a] -> [a] -> [a]
[] ++ ys = ys
(x:xs) ++ ys = x : (xs ++ ys)

merge :: [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = x : y : merge xs ys

zip :: [a] -> [b] -> [(a,b)]
--zip [] _ = []
--zip _ [] = []
zip (x:xs) (y:ys) = (x,y) : zip xs ys
zip _ _ = []

isPrefixOf :: Eq a => [a] -> [a] -> Bool
isPrefixOf [] _ = True
isPrefixOf _ [] = False
isPrefixOf (x:xs) (y:ys) = x == y && isPrefixOf xs ys

elem :: Eq a => a -> [a] -> Bool
elem e [] = False
elem e (x:xs) = e == x || elem e xs

nub :: Eq a => [a] -> [a]
