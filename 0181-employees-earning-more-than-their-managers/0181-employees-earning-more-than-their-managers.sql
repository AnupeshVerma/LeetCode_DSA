# Write your MySQL query statement below
SELECT e1.name as 'Employee'
FROM Employee as e1
WHERE e1.salary > (SELECT salary FROM Employee AS e2
                    WHERE e2.id = e1.managerId )