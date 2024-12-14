WITH threePairs AS (
    SELECT 
        num,
        LAG(num, 1) OVER (ORDER BY id) AS prev_val,
        LAG(num, 2) OVER (ORDER BY id) AS prev_prev_val
    FROM Logs
)

SELECT num AS ConsecutiveNums
FROM threePairs
WHERE num = prev_val AND num = prev_prev_val