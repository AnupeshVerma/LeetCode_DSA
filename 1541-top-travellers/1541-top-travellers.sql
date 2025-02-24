SELECT u.name, 
    COALESCE((
        SELECT SUM(distance) 
        FROM Rides
        WHERE user_id = u.id
    ), 0) AS travelled_distance
FROM Users AS u
ORDER BY travelled_distance DESC, name;