##### METHOD 1 #####

-- SELECT MAX(num)
-- FROM (
--     SELECT num
--     FROM MyNumbers
--     GROUP BY num
--     HAVING COUNT(num) = 1;
-- )



##### METHOD 2 #####
SELECT (
    SELECT num 
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
    ORDER BY num DESC
    LIMIT 1
) AS num;