# Write your MySQL query statement below

SELECT
    employee_id
FROM Employees
WHERE employee_id NOT IN (
    SELECT employee_id
    FROM Salaries
)
-- Find employees whose IDs exist in Employees
-- but do not exist in Salaries (salary information is missing)

UNION
-- Combine both results and remove duplicate employee IDs

SELECT
    employee_id
FROM Salaries
WHERE employee_id NOT IN (
    SELECT employee_id
    FROM Employees
)
-- Find employees whose IDs exist in Salaries
-- but do not exist in Employees (name information is missing)

ORDER BY employee_id;
-- Sort the final combined result by employee_id in ascending order