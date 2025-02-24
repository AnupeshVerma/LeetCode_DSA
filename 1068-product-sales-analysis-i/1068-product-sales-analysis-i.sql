-- Using Subquery
/*
SELECT
    (SELECT product_name FROM Product WHERE product_id = s.product_id),
    s.year,
    s.price
FROM Sales AS s;

*/


-- Using JOIN
SELECT 
    p.product_name,
    s.year,
    s.price
FROM Sales AS s
INNER JOIN Product AS p
USING (product_id)
