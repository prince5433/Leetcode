# Write your MySQL query statement below
SELECT
IF(
    id%2=1 AND id=(SELECT COUNT(*) FROM Seat),
    id,
    IF (id%2=1,id+1,id-1)
) AS id,
student
From Seat
ORDER BY id;