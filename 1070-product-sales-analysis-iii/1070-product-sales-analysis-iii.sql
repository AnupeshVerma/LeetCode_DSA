##### METHOD 1 (Gives TLE) ######

-- SELECT 
--     product_id,
--     year AS first_year,
--     quantity,
--     price
-- FROM Sales AS s
-- WHERE year = (
--     SELECT MIN(year)
--     FROM Sales
--     WHERE product_id = s.product_id
-- )



##### METHOD 2 ######

WITH sortedYear AS (
    SELECT product_id, MIN(year) AS min_year
    FROM Sales
    GROUP BY product_id
)

SELECT
    s.product_id,
    s.year AS first_year,
    s.quantity,
    s.price
FROM Sales AS s
JOIN sortedYear AS sy
ON s.product_id = sy.product_id AND s.year = sy.min_year