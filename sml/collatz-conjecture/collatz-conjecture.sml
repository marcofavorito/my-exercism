fun collatz n = if (n = 1) 
                then 0 
                else if (n mod 2 = 0) 
                    then 1 + collatz(n div 2) 
                    else 1 + collatz(3 * n + 1)
