-- SELECT
--     id,
--     CASE
--         WHEN id%2=0 THEN (SELECT student s2 FROM Seat WHERE id )




###### METHOD 2 #####
SELECT 
    CASE 
        WHEN id % 2 = 0 THEN id-1
        WHEN id % 2 = 1 AND id<(SELECT MAX(id) FROM Seat) THEN id+1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;