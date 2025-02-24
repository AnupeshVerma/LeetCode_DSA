-- -- Using Window Function


-- SELECT a.Id
-- FROM (
--     SELECT 
--         id,
--         recordDate,
--         temperature,
--         LAG(temperature, 1) OVER (ORDER BY recordDate) AS prev_day_temp
--     FROM Weather
-- ) AS a
-- WHERE a.temperature > a.prev_day_temp;



SELECT w2.id
FROM Weather AS w1, Weather AS w2
WHERE 
    w2.recordDate - w1.recordDate = 1 AND
    w2.temperature > w1.temperature;