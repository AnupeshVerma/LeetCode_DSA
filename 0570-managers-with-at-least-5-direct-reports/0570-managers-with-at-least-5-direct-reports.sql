SELECT name
FROM Employee
WHERE id = (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(managerId) >= 5
)