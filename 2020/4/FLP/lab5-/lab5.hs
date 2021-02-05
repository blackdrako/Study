import Data.Maybe
import Data.Char

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


--Rework lab3
--Задание:
--Определим следующий набор операций над строками:
--Очистка: удаление всех символов из строки
--Удаление: удаление всех вхождений указанного символа
--Замена: замена всех вхождений одного символа на другой
--Добавление: добавление в начало строки указанного символа
--Разработайте тип данных, характеризующий операции над строками. Определите следующие функции:
--1)process, получающая в качестве аргумента действие и строку и возвращающая строку, модифицированную в соответствии с указанным действием.
--2)processAll, аналогичная предыдущей, но получающая список действий и выполняющая их по порядку.
--3)deleteAll, принимающая две строки и удаляющая из второй строки все символы первой. При реализации обязательно использовать функцию processAll.
type ProcS = String -> String

clear :: ProcS
clear = const []

delete :: Char  -> ProcS
delete = filter . (/=)

replace :: (Char, Char) -> ProcS
replace = map . sub where
  sub (c, e) d = 
    if c == d then e else d

push_front :: Char -> ProcS
push_front = (:)

process = ($)

processAll = flip $ foldl $ flip process

deleteAll = processAll . map delete