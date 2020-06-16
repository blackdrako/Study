square :: Double -> Double
square x = x * x
calcSide :: Double -> Double -> Double -> Double -> Double
calcSide ax ay bx by = sqrt (square (bx - ax) + square (by - ay))
isSovlePifagor :: Double -> Double -> Double -> Bool
isSovlePifagor a b c = if ((square c) - ((square a) + (square b))) < 0.00001 then True else False
isRectangular :: Double -> Double -> Double -> Double -> Double -> Double -> Bool
isRectangular x_1 y_1 x_2 y_2 x_3 y_3 = if (isSovlePifagor a b c)||(isSovlePifagor b a c)||( isSovlePifagor c a b)== True then True else False where
	a = calcSide x_1 y_1 x_2 y_2
	b = calcSide x_1 y_1 x_3 y_3
	c = calcSide x_2 y_2 x_3 y_3