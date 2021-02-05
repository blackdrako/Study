--Список натуральных чисел
listN :: Integer -> [Integer]
listN 0 = [ ]
listN x = listN (x-1)++(x:[])
--Список нечетных натуральных чисел
listOddN :: Integer -> [Integer]
listOddN 0 = [ ]
listOddN x = listOddN (x-1)++(2*x-1:[])
--Список четных натуральных чисел
listEvenN :: Integer -> [Integer]
listEvenN 0 = [ ]
listEvenN x = listEvenN (x-1)++(2*x:[])
--Список квадратов натуральных чисел
listPow2N :: Integer -> [Integer]
listPow2N 0 = [ ]
listPow2N x = listPow2N (x-1)++(x*x:[])
--Список факториалов
listFactorial :: Integer -> [Integer]
factorial 0 = 1
factorial x = x*factorial(x-1)
listFactorial 0 = [ ]
listFactorial x = listFactorial (x-1)++[factorial(x)] 
--Список степеней двойки
listPow2 :: Integer -> [Integer]
stepen 1 = 1
stepen x = 2*stepen(x-1)
listPow2 0 = [ ]
listPow2 x = listPow2 (x-1)++[stepen(x+1)]
--Список треугольных чисел
listTri :: Integer -> [Integer]
piram 1 = 1
piram(x) = x+piram(x-1)
listTri 0 = [ ]
listTri x = listTri (x-1)++[piram(x)]
--Список пирамидальных чисел
getPyramidalList :: Integer -> [Integer]
getPyramidalList 0 = [ ]
getPyramidalList x = getPyramidalList (x-1)++[n(x)]
pyr 1 = 1
pyr(x) = x+pyr(x-1)
n 1 = 1
n x = pyr(x) + n(x-1)
--8 Функция countTrue :: [Bool] -> Integer, возвращающая количество элементов списка, равных True.
countTrue :: [Bool] -> Integer
countTrue []            =  0
countTrue (True  : xs)  =  1 + countTrue xs
countTrue (False : xs)  =  countTrue xs
--11
substitute :: Char -> Char -> String -> String
substitute a b [] = []
substitute a b (x:xs) = if x == a then b : substitute a b xs else x :   substitute a b xs