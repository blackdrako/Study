getPyramidalList :: Integer -> [Integer]
getPyramidalList 0 = [ ]
getPyramidalList x = getPyramidalList (x-1)++[n(x)]
pyr 1 = 1
pyr(x) = x+pyr(x-1)
n 1 = 1
n x = pyr(x) + n(x-1)
substitute :: Char -> Char -> String -> String
substitute a b [] = []
substitute a b (x:xs) = if x == a then b : substitute a b xs else x :   substitute a b xs