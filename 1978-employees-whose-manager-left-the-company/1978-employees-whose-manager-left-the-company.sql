# Write your MySQL query statement below

SELECT
    employee_id  -- Return the ID of the employee whose manager has left
FROM Employees

WHERE Employees.salary < 30000
-- Consider only employees earning less than 30,000

AND manager_id NOT IN (
    SELECT employee_id
    FROM Employees
    -- Get all employee IDs currently present in the company
)
-- Keep employees whose manager ID is not present
-- in the list of existing employee IDs

ORDER BY employee_id;
-- Sort the final result by employee ID in ascending order