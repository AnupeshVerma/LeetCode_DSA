# Write your MySQL query statement below


SELECT * FROM Cinema as c 
WHERE mod(id, 2)!=0 and description  NOT IN ('boring')
ORDER BY RATING DESC;