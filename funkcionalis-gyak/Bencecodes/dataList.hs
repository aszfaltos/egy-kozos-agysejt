module Datalist where

  insert:: 0rd a => a-> [a] -> [a]
  insert e [] = [e]
  insert e (x:xs)
    | e <= x = e :x : xs
    | otherwise = x : insert e xs

  combinations:: Int -> [a] -> [[a]]
  combinations 0 _ = [[]]
  combinations n _ | n < 0 = []
  combinations n [] = []
  combinations n (x:xs) = [x:c | c <- combinations (n-1) xs] ++ combinations n xs
