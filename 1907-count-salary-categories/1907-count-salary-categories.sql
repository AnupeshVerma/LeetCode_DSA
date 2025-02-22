SELECT 'Low Salary' AS category, SUM(CASE WHEN income < 20000 THEN 1 ELSE 0 END) AS accounts_count FROM Accounts
UNION
SELECT 'High Salary' AS category, SUM(CASE WHEN income > 50000 THEN 1 ELSE 0 END) AS accounts_count FROM Accounts 
UNION
SELECT 'Average Salary' AS category, SUM(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 ELSE 0 END) AS accounts_count FROM Accounts;


/*

SELECT 'Low Salary' AS category, COUNT(*) AS accounts_count FROM Accounts WHERE income < 20000
UNION
SELECT 'Average Salary', COUNT(*) FROM Accounts WHERE income BETWEEN 20000 AND 50000
UNION
SELECT 'High Salary', COUNT(*) FROM Accounts WHERE income > 50000;

*/




-- Brute Force (CAUSE TLE)
/*

WITH cte AS (
    SELECT account_id,
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category
    FROM Accounts
),

categories AS (
    SELECT 'High Salary' AS category
    UNION
    SELECT 'Low Salary'
    UNION
    SELECT 'Average Salary'
)

SELECT 
    ctg.category,
    COALESCE(COUNT(cte.category), 0) AS accounts_count
FROM categories AS ctg
LEFT JOIN cte
USING (category)
GROUP BY category;

*/

