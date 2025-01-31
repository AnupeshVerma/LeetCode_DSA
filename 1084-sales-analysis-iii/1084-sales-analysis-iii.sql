SELECT DISTINCT p.product_id, p.product_name
FROM Product AS p
JOIN Sales AS s
ON p.product_id = s.product_id
WHERE s.product_id NOT IN (
    SELECT product_id
    FROM Sales
    WHERE sale_date > '2019-03-31' OR sale_date < '2019-01-01'
)