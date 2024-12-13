##### METHOD 1 : Using subquery #####

-- SELECT
--     user_id AS buyer_id,
--     join_date,
--     (
--         SELECT COUNT(buyer_id) FROM Orders 
--         WHERE buyer_id = user_id AND YEAR(order_date) = 2019
--     ) AS orders_in_2019
-- FROM Users;



##### METHOD 1 : Using Joins #####

SELECT
    u.user_id AS buyer_id,
    u.join_date,
    COALESCE(COUNT(o.buyer_id)) AS orders_in_2019
FROM Users u
LEFT JOIN Orders o
ON u.user_id = o.buyer_id AND YEAR(o.order_date) = 2019
GROUP BY user_id
ORDER BY buyer_id

