-- Using SELF JOIN


SELECT DISTINCT a.id, a.visit_date, a.people
FROM Stadium a, Stadium b, Stadium c
WHERE
    a.people >= 100 AND b.people >= 100 AND c.people >= 100 
    AND (
        (a.id - b.id = 1 AND b.id - c.id = 1)
        OR
        (b.id - a.id = 1 AND c.id - b.id = 1)
        OR
        (a.id - c.id = 1 AND b.id - a.id = 1)
    )




-- Using WINDOW Function
/*

WITH cte AS (
    SELECT 
        id,
        visit_date,
        people,
        LAG(id, 1) OVER (ORDER BY id) AS last_id,
        LAG(id, 2) OVER (ORDER BY id) AS second_last_id,
        LEAD(id, 1) OVER(ORDER BY id) AS next_id,
        LEAD(id, 2) OVER(ORDER BY id) AS second_next_id
    FROM Stadium
    WHERE people >= 100
)

SELECT id, visit_date, people
FROM cte
WHERE
    (next_id - id = 1 AND second_next_id - next_id = 1)
    OR
    (next_id - id = 1 AND id - last_id = 1)
    OR
    (id - last_id = 1 AND last_id - second_last_id = 1)
ORDER BY visit_date;

*/


