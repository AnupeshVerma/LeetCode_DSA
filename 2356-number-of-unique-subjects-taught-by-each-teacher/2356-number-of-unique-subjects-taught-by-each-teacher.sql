SELECT teacher_id, COUNT(*) As cnt
FROM (
    SELECT teacher_id, subject_id
    FROM Teacher
    GROUP BY teacher_id, subject_id
)
GROUP BY teacher_id;

