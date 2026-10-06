# Group students based on their class
# Then count students in each class and keep only classes having 5 or more students
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;