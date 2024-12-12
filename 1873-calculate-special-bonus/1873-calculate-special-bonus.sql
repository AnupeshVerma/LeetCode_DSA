WITH FullBonus AS (
    SELECT employee_id
    FROM Employees
    WHERE employee_id%2 != 0 AND name NOT LIKE 'M%'
)

SELECT 
    e.employee_id,
    CASE 
        WHEN fb.employee_id IS NOT NULL THEN salary
        ELSE 0
    END AS bonus
FROM Employees AS e
LEFT JOIN FullBonus AS fb
ON fb.employee_id = e.employee_id
ORDER BY employee_id;