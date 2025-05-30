WITH JoinedTable AS (
    SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
    UNION 
    SELECT * FROM Employees RIGHT JOIN Salaries USING (employee_id)    
)

SELECT employee_id 
FROM JoinedTable
WHERE 
    salary IS NULL OR
    name IS NULL
ORDER BY employee_id;