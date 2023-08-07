# Write your MySQL query statement below

SELECT v.customer_id, COUNT(*) AS count_no_trans FROM visits AS v
LEFT JOIN
transactions as t  ON v.visit_id = t.visit_id
WHERE t.transaction_id is NULL
GROUP BY v.customer_id;