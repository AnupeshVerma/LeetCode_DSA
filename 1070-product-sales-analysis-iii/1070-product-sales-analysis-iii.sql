SELECT 
    product_id,
    year AS first_year,
    quantity,
    price
FROM Sales AS s
WHERE year = (
    SELECT MIN(year)
    FROM Sales
    WHERE product_id = s.product_id
)