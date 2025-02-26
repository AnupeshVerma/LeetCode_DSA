SELECT
    request_at AS Day,
    ROUND(SUM(CASE WHEN status != 'completed' THEN 1 ELSE 0 END) / COUNT(*), 2) AS "Cancellation Rate"
FROM Trips AS t
LEFT JOIN Users AS c ON t.client_id = c.users_id
LEFT JOIN Users AS d ON t.driver_id = d.users_id
WHERE 
    c.banned = 'No' AND
    d.banned = 'No' AND
    request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Day