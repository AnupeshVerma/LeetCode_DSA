SELECT
    name,
    SUM(amount) AS balance
FROM Users
JOIN Transactions USING(account)
GROUP BY name
HAVING SUM(amount) > 10000