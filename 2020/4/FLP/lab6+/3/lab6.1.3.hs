import System.IO
import System.Environment

main = do
		name <- getArgs
		fromHandle <- openFile name ReadMode
		contents <- hGetContents fromHandle
		hPutStr stdout contents