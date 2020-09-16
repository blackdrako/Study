data Employee = Employee { uid :: String, sub ::  [Employee] } deriving (Eq, Show)
 
orelse = (++)

getSubordinates :: Employee -> String -> [Employee]
getSubordinates hs uid1 = aux hs
  where aux x 
          | uid x /= uid1 = foldr (orelse . aux) [] (sub x)
        aux x             = sub x

getAllSubordinates :: Employee -> String -> [Employee]
getAllSubordinates hs = go . getSubordinates hs
  where 
    go = concatMap (\x1 -> x1 : go (sub x1))
 
getBoss :: Employee -> String -> [Employee]
getBoss hs uid1 = aux [] hs
  where aux s x 
          | uid x /= uid1 = foldr (orelse . aux [x]) [] (sub x)    
        aux s _ = s    

getList :: Employee -> [(String, Int)]
getList hs = (uid hs, length xs) : xs
  where
    xs = concatMap getList (sub hs)
	
hierarchy = Employee "Simon"
            [
              Employee "Eva" [Employee "Dons" [Employee "Io" []]],
              Employee "Ron" []
            ]
           