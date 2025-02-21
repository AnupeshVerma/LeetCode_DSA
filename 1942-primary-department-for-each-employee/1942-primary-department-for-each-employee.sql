-- Using GROUP BY in subquery
/*
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
    OR employee_id IN (
            SELECT employee_id
            FROM Employee
            GROUP BY employee_id
            HAVING COUNT(employee_id) = 1
    );
*/


-- Using WINDOW FUNCTION in subquery
/*
SELECT employee_id, department_id
FROM (
    SELECT *,
        COUNT(employee_id) OVER (PARTITION BY employee_id ORDER BY employee_id) as emp_count
    FROM Employee
 )AS a 
WHERE primary_flag = 'Y' OR a.emp_count = 1;
*/


-- Using UNION 
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(employee_id) = 1;