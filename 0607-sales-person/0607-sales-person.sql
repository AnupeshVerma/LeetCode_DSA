-- Using Subqueries
/*
SELECT s.name
FROM SalesPerson AS s
WHERE s.sales_id NOT IN (
        SELECT sales_id FROM Orders
        WHERE com_id = (SELECT com_id FROM Company WHERE name = 'RED')
);

*/


-- Using JOIN

/*
SELECT s.name
FROM SalesPerson AS s
WHERE s.sales_id NOT IN (
        SELECT sales_id FROM Orders
        JOIN Company AS c
        USING (com_id)
        WHERE c.name = 'RED'
);

*/


-- Using Common Table Expression


WITH acceptable_sales_ids AS (
    SELECT sales_id FROM Orders
    WHERE com_id = (SELECT  com_id FROM Company WHERE name = 'RED')
)

SELECT s.name
FROM SalesPerson AS s
WHERE s.sales_id NOT IN (SELECT sales_id FROM acceptable_sales_ids);

