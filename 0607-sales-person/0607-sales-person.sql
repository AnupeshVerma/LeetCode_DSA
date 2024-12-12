
####### METHOD 1 #######

-- SELECT s.name
-- FROM SalesPerson AS s
-- WHERE s.sales_id NOT IN (
--     SELECT o.sales_id
--     FROM Orders AS o
--     WHERE o.com_id IN (
--         SELECT c.com_id
--         FROM Company AS c
--         WHERE c.name = 'RED'
--     )
-- )


####### METHOD 2 ######

SELECT s.name
FROM SalesPerson AS s
WHERE s.sales_id NOT IN (
    SELECT o.sales_id
    FROM Orders AS o
    JOIN Company AS c
    ON o.com_id = c.com_id
    WHERE c.name = 'RED'
)