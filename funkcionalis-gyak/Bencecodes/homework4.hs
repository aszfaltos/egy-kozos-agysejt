module Homework4 where



  f :: [[a]] -> Int
  f [x:xs] = 0
  f ([]:[[]]) = 1
  f ((xs:x):_) = 2

  x0 = [[1]]
  x1 = [[],[]]
  x2 = [[1],[1]]

  headTail :: [a] -> (a, [a])
  headTail (x:xs) = (x,xs)

  doubleHead :: [a] -> [b] -> (a, b)
  doubleHead (x:xs) (y:ys) = (x,y)

  howMany :: Char -> String -> Int
  howMany c str = length [x | x <- str, c == x]

  doubleAll :: [Int] -> [Int]
  doubleAll x = [y*2 | y<-x]
