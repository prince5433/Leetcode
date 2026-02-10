-- Select teacher_id and count of unique subjects taught by each teacher
SELECT 
    teacher_id,
    COUNT(DISTINCT subject_id) AS cnt   -- COUNT(DISTINCT ...) ensures only unique subjects are counted
FROM Teacher
-- Group rows by teacher so aggregation happens per teacher
GROUP BY teacher_id;
