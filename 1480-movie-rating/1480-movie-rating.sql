(
    SELECT u.name AS results
    FROM MovieRating AS mr
    JOIN Users AS u
    ON mr.user_id = u.user_id
    GROUP BY mr.user_id
    ORDER BY COUNT(mr.user_id) DESC, u.name
    LIMIT 1
)

UNION ALL

(
    SELECT m.title AS results
    FROM Movies AS m
    JOIN MovieRating AS mr
    ON m.movie_id = mr.movie_id
    WHERE YEAR(mr.created_at) = 2020 AND MONTH(mr.created_at) = 2
    GROUP BY mr.movie_id
    ORDER BY AVG(mr.rating) DESC, m.title 
    LIMIT 1
)