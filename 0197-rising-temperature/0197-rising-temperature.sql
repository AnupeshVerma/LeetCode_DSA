# Write your MySQL query statement below


# SELECT w1.id FROM weather AS w1
# INNER JOIN
# weather AS w2
# WHERE w1.temperature > w2.temperature and w1.recordDate = w2.recordDate + interval 1 day;

# SELECT w1.id FROM weather w1, weather w2
# WHERE w1.temperature>w2.temperature AND datediff(w1.recordDate, w2.recordDate)=1


SELECT w1.id FROM weather AS w1
JOIN
weather AS w2 on datediff(w1.recordDate, w2.recordDate)=1 
WHERE w1.temperature > w2.temperature;