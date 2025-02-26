SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.Salary
FROM Employee AS e
JOIN Department AS d
ON e.departmentId = d.id
WHERE salary IN (
        SELECT MAX(salary)
        FROM Employee
        WHERE departmentId = e.departmentId
        GROUP BY departmentId
);