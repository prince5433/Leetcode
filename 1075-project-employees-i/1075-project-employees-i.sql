
-- Write your MySQL query statement below

SELECT project_id,
-- Har project ki ID output mein show karni hai

ROUND(AVG(Employee.experience_years), 2) AS average_years
-- AVG se assigned employees ka average experience nikaalo
-- ROUND(..., 2) se average ko 2 decimal places tak round karo
-- AS average_years output column ka naam set karta hai

FROM Project
-- Project table se start karte hain, jahan employee-project mapping hai

INNER JOIN Employee
-- Employee table join karte hain, taaki unka experience mil sake

ON Project.employee_id = Employee.employee_id
-- Dono tables ko employee_id ke basis par match karte hain

GROUP BY project_id;
-- Har project ka alag group banate hain aur uska average nikaalte hain
