avg :: [Double] -> Double
avg x = (foldr (\ a y -> a+y) 0.0 x) / (fromIntegral $ length x)

scalProd :: [Double] -> [Double] -> Double
scalProd x y = foldr (+) 0.0 (zipWith (*) x y)

countEven :: [Int] -> Int
countEven = length . filter even

qSort :: Ord a => [a] -> [a]
qSort [] = []
qSort (x:xs) = qSort (filter (< x) xs) ++ [x] ++ qSort (filter (>= x) xs)

qSort' :: (a -> a -> Bool) -> [a] -> [a]
qSort' fc []     = []
qSort' fc (x:xs) = qSort' fc (filter (fc x) xs) ++ [x] ++ (qSort' fc (filter (\ y -> not $ fc x y) xs))
