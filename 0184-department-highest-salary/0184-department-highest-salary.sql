SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.Salary
FROM Employee AS e
JOIN Department AS d
ON e.departmentId = d.id
WHERE e.salary IN (
        SELECT MAX(salary)
        FROM Employee
        WHERE departmentId = e.departmentId
);