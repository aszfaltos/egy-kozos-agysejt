module Homework5  where

sumFirst :: Int -> [Int] -> Int
sumFirst 1 (x:xs) = x
sumFirst _ [] = 0
sumFirst n (x:xs) = x + sumFirst(n-1) xs

everySecond :: [a] -> [a]
everySecond [] = []
everySecond [x] = [x]
everySecond (x:xs) =[x]++ (everySecond (tail xs))

insertAt :: Int -> a -> [a] -> [a]
insertAt 0 n [] = [n]
insertAt 0 n (x:xs) = n:(x:xs)
insertAt i n (x:xs) = x:(insertAt (i-1) n xs)

letterize :: String -> [String]
letterize [] = []
letterize (x:xs) = [x] : (letterize xs)
