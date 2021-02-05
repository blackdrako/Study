import System.IO
import System.Environment
import Data.Char
import Data.Maybe
import Data.List

main = do
		putStrLn "Enter an x1,y1: "
		line <- getLine
		let x1 = read line::Double
		line <- getLine
		let y1 = read line::Double
		putStrLn "Enter an x2,y2: "
		line <- getLine
		let x2 = read line::Double
		line <- getLine
		let y2 = read line::Double
		putStrLn "Enter an x3,y3: "
		line <- getLine
		let x3 = read line::Double
		line <- getLine
		let y3 = read line::Double
		print (isRectangular (x1,y1) (x2,y2) (x3,y3)) >> main


isRectangular ::(Double,Double) -> (Double,Double) -> (Double,Double) -> Bool
isRectangular (a,b) (c,d) (e,f) = if (c-a)*(e-a)+(d-b)*(f-b)==0 || (a-c)*(e-c)+(b-d)*(f-d)==0 || (a-e)*(c-e)+(b-f)*(d-f)==0 then True else False