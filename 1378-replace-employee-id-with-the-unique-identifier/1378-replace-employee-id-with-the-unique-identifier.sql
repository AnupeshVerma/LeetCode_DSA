# Write your MySQL query statement below

SELECT eu.unique_id, e.name FROM employees AS e LEFT JOIN EmployeeUNI AS eu ON e.id=eu.id;