grayCode :: Int -> [String]
grayCode 0 = [""]
grayCode n = map ('0':) prev ++ map ('1':) (reverse prev)
  where prev = grayCode (n-1)

main :: IO ()
main = do
  n <- readLn :: IO Int
  let codes = grayCode n
  mapM_ putStrLn codes
