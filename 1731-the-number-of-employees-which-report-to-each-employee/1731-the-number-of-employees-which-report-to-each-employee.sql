# Write your MySQL query statement below

SELECT
    e1.employee_id,  -- Manager ki ID return karo
    e1.name,         -- Manager ka naam return karo

    COUNT(e2.employee_id) AS reports_count,
    -- Manager ko report karne wale employees count karo

    ROUND(AVG(e2.age)) AS average_age
    -- Reporting employees ki average age calculate karke
    -- nearest integer mein round karo

FROM Employees AS e1
-- e1 represents the manager

JOIN Employees AS e2
-- e2 represents the employees reporting to the manager

    ON e1.employee_id = e2.reports_to
    -- Manager ki ID ko employee ke reports_to se match karo

GROUP BY e1.employee_id, e1.name
-- Har manager ka separate group banao
-- Taaki COUNT aur AVG manager-wise calculate ho sake

ORDER BY e1.employee_id;
-- Final result ko employee ID ke ascending order mein sort karo

-- TC: Depends on the database's JOIN, grouping and sorting execution.
-- SC: Depends on intermediate JOIN and GROUP BY data.