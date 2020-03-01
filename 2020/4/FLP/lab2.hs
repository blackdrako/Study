baz :: Integer -> [Integer]
baz
countTrue :: [Bool] -> Integer
countTrue [] = 0
countTrue (x:xs) i = if x == true then i++