-- -- Write your PostgreSQL query statement below
-- SELECT 
--     machine_id,
--     ROUND(SUM(
--         CASE WHEN activity_type = 'start' THEN -1*timestamp::INT ELSE timestamp::INT END
--     )/COUNT(*), 3) AS processing_time
-- FROM Activity
-- GROUP BY machine_id


SELECT 
    a1.machine_id,
    ROUND(AVG(a1.timestamp::NUMERIC - a2.timestamp::NUMERIC), 3) AS processing_time
FROM Activity a1, Activity a2
WHERE
    a1.machine_id = a2.machine_id AND
    a1.activity_type = 'end' AND
    a2.activity_type = 'start'
GROUP BY a1.machine_id;