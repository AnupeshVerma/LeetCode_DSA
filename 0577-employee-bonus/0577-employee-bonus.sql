/*

-- this will not work because NULL < 1000 give unknown
-- so you have to add this in where condition explicitly
SELECT e.name, COALESCE(b.bonus, null) AS bonus 
FROM Employee AS e
LEFT JOIN Bonus AS b USING (empID)
WHERE b.bonus < 1000

*/

SELECT 
    e.name,
    b.bonus
FROM Employee e
LEFT JOIN Bonus b USING(empId)
WHERE b.bonus < 1000 OR b.bonus IS NULL