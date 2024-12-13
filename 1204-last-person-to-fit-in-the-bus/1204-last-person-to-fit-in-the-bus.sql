##### METHOD 1 #####

-- WITH cumulativeWeight AS (
--     SELECT 
--         person_name,
--         SUM(weight) OVER (ORDER BY turn) AS cum_weight
--         FROM Queue
-- )

-- SELECT person_name
-- FROM cumulativeWeight
-- WHERE cum_weight <= 1000
-- ORDER BY cum_weight DESC
-- LIMIT 1;



##### METHOD 2 #####

# q2 represent the people having less turn value than q1
# SUM(q2.weight) represent the cumulative sum of people having turn less than q1.turn

SELECT q1.person_name
FROM Queue q1
JOIN Queue q2
ON q1.turn >= q2.turn
GROUP BY q1.turn
# Represent the cumulative sum of people having turn less than q1.turn
HAVING SUM(q2.weight) <= 1000  
ORDER BY SUM(q2.weight) DESC
LIMIT 1;