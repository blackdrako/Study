import System.IO

main = do
		a <- readLn
		b <- readLn
		print (a + b)
		return (a + b)