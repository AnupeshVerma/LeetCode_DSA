SELECT
    p.product_name,
    SUM(o.unit) AS unit
FROM Products AS p 
JOIN Orders AS o
ON p.product_id = o.product_id
WHERE YEAR(o.order_date) = 2020 AND MONTH(o.order_date) = 2
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100
