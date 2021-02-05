type Name = String
type Phone  = String
type Descriptions  = String
type Date = (Int,Int,Int) 
data Records = Remind Name Date |  
               PhoneBook  Name Phone |
               Meet   Descriptions  Date
               deriving Show
               
getByName:: [Records] -> String -> (Maybe Phone, Maybe Date )
getByName l p = (getPhone l, getRemind l)
  where getPhone [] = Nothing
        getPhone ( PhoneBook p' n :xs) 
            | p' == p = Just n
            | otherwise = getPhone xs
        getPhone (_:xs) = getPhone xs
        getRemind [] = Nothing
        getRemind ( Remind p' d :xs) 
            | p' == p = Just d
            | otherwise = getRemind xs
        getRemind (_:xs) = getRemind xs
        
extra n l
  | elem n l = l
  | otherwise = n:l
 
getByLetter:: [Records] -> Char -> [Name]
getByLetter [] _ = []
getByLetter ( PhoneBook [] _ :xs) c = getByLetter xs c
getByLetter ( PhoneBook p@(n:_) _ :xs) c 
    | n == c = extra p  (getByLetter xs c)
    | otherwise = getByLetter xs c
getByLetter ( Remind [] _ :xs) c = getByLetter xs c
getByLetter ( Remind p@(n:_) _ :xs) c 
    | n == c = extra p (getByLetter xs c)
    | otherwise = getByLetter xs c
getByLetter (_:xs) c = getByLetter xs c
 
getAssignment:: [Records] -> Date  -> [Records] 
getAssignment [] _ = []
getAssignment (r@(Remind _ d'):xs) d 
    | d == d' = r : getAssignment xs  d
    | otherwise = getAssignment xs  d
getAssignment (r@(Meet _ d'):xs) d 
    | d == d' = r : getAssignment xs  d
    | otherwise = getAssignment xs  d
getAssignment (_:xs) d = getAssignment xs  d
 
testBook = [Remind "Joseph Joestar" (27, 8,1920),
		Remind "Ivan" (1, 1,1999),
		PhoneBook "Joseph Joestar" "99-99-99",
		PhoneBook "Guido Mista" "13-65-27",
		Meet "Morio" (1, 1,1999)]