game :: [Int] -> Int -> Int
game [x]_ = x
game xs mv   
    | mv == 1 = game[x | (i, x) <- zip [1..] xs, odd i] 2
    | mv == 2 = game[x | (i, x) <- zip [1..] xs, even i] 3
    | otherwise = game [x | (i, x) <- zip[1..] xs, i `mod` 3 /=0] 1


main :: IO ()
main=do
    n <- readLn
    let numbers = [1..n]
    print (game numbers 1)