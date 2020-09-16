import System.IO
import System.Environment

main = do
	(name:_) <- getArgs
	fromHandle <- openFile name ReadMode
	contents <- hGetContents fromHandle
	hPutStr stdout contents