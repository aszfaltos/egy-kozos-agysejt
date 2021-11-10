module Gyak9 where

import Prelude hiding ((.), zipWith, sqrt, uncurry, curry)

-- Továbbra is magasabbrendű függvények

-- Segédfüggvénynek használjuk a flip és notElem függvényeket.
filters :: Eq a => [a] -> [a] -> [a]
filters xs ys = filter (flip notElem xs) ys

zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith f (x:xs) (y:ys) = f x y : zipWith f xs ys
zipWith _ _ _ = []

-- zipWith alkalmazása
differences :: Num a => [a] -> [a]
differences xs = zipWith (-) (tail xs) xs

-- Névtelen függvények, lambdák
-- A matematikai jelöléshez hasonló szintaxissal adhatunk meg névtelen függvényeket
-- Pl.:
inc :: Int -> Int
inc = \x -> x + 1

add :: Int -> Int -> Int
add = \x y -> x + y

-- Függvénykompozíció lambdával
(.) :: (b -> c) -> (a -> b) -> a -> c
--f . g = h
--where h x = f (g x)
--(f . g) x = f (g x)
f . g = \x -> f (g x)

-- Fibonacci párok, mintaillesztés lambdákban
fibPairs :: [(Integer, Integer)]
fibPairs = iterate (\(a,b) -> (b,a+b)) (0,1)

-- Egyenlő elemek csoportosítása
group :: Eq a => [a]{-véges-} -> [[a]]
group [] = []
group (x:xs) = takeWhile (==x) (x:xs) : group (dropWhile (==x) xs)

-- Egymás után ismétlődő elemek tömörítése
compress :: Eq a => [a] -> [(Int,a)]
compress xs = map (\l -> (length l, head l)) (group xs)

-- Pascal háromszög előállítása
--     1
--    1 1
--   1 2 1
--  1 3 3 1
-- 1 4 6 4 1
pascalTriangle :: [[Integer]]
pascalTriangle = iterate (\xs -> [1] ++ zipWith (+) xs (tail xs) ++ [1]) [1]


-- Newton módszer négyzetgyök számolására
-- until függvény: iterálás feltételig
sqrt :: RealFloat a => a -> a
--sqrt a = iterate (\x->(x+a/x)/2) a !! 10
sqrt a = until (\x -> abs (x*x - a) < 1e-8) (\x->(x+a/x)/2) a

-- uncurry és curry:
uncurry :: (a -> b -> c) -> ((a, b) -> c)
uncurry f (a,b) = f a b

curry :: ((a, b) -> c) -> a -> b -> c
curry f a b = f (a,b)

-- A compress inverze
-- Használható függvény: concatMap
decompress :: Eq a => [(Int,a)] -> [a]
-- concatMap = concat $ map
decompress xs =concatMap (uncurry replicate) xs

-- Súlyozott összeg
weightedSum :: Num a => [(a,a)] -> a
--weightedSum xs = sum $ map (\(a,b) -> a*b) xs
--weightedSum xs = sum $ map (uncurry (*)) xs
weightedSum = sum . map (uncurry (*))

-- Függvénykompozíció használata (http://lambda.inf.elte.hu/Composition.xml)
-- numbersMadeOfOnes :: [Integer]
-- numbersMadeOfThrees :: [Integer]
-- numbersMadeOfThreesAndOne :: [Integer]

-- Szóközök eldobása
-- dropSpaces :: String -> String
-- trim :: String{-véges-} -> String

-- Minimumok maximuma
-- maximumOfMinimums :: Ord a => [[a]] -> a

-- Dupla map
-- mapMap :: (a -> b) -> [[a]] -> [[b]]

-- Miért működik?
-- map :: (a -> b) -> [a] -> [b]
-- (.) :: (b -> c) -> (a -> b) -> a -> c

-- Kezdőbetűk
-- firstLetters :: String -> String
-- monogram :: String -> String

-- Ismétlődő elemek manipulálása
-- reduce :: Eq a => [a] -> [a]
-- uniq :: Ord a => [a]{-véges-} -> [a]
-- repeated :: Ord a => [a]{-véges-} -> [a]

-- Iterálás feltételig
-- until :: (a -> Bool) -> (a -> a) -> a -> a

-- Részsorozatok
-- sublists :: [a] -> [[a]]
