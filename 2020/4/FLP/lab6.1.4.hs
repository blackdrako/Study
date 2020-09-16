import System.IO
import System.Environment

main = do
		[n, path] <- getArgs
		content <- readFile path 
		print (take (read n) (lines content))