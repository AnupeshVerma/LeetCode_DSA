-- Using WINDOW FUNCTIONS
/*

SELECT DISTINCT
    student_id, 
    subject, 
    first_score,
    latest_score
FROM (
    SELECT student_id, subject,
        FIRST_VALUE(score) OVER (PARTITION BY student_id, subject ORDER BY exam_date) AS first_score,
        FIRST_VALUE(score) OVER (PARTITION BY student_id, subject ORDER BY exam_date DESC) AS latest_score
    FROM Scores
) AS a
WHERE a.first_score < a.latest_score
ORDER BY student_id, subject;

*/




SELECT 
    f.student_id,
    f.subject,
    f.score as first_score,
    l.score as latest_score
FROM scores AS f 
JOIN scores l 
ON 
    f.student_id = l.student_id AND 
    f.subject = l.subject AND
    f.exam_date != l.exam_date  
WHERE 
    f.score < l.score AND
    f.exam_date = (SELECT min(exam_date) FROM scores WHERE f.student_id = student_id AND f.subject = subject) AND
    l.exam_date = (SELECT max(exam_date) FROM scores WHERE l.student_id = student_id AND l.subject = subject)
ORDER BY f.student_id,f.subject;