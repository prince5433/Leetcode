
SELECT
    employee_id,

    -- Since each employee has only one department
    -- in this group, MAX returns that department_id.
    MAX(department_id) AS department_id

FROM Employee

-- Group all departments belonging to the same employee.
GROUP BY employee_id

-- Keep only employees having exactly one department.
HAVING COUNT(department_id) = 1

-- For a single-department employee, the problem guarantees
-- primary_flag = 'N'.
-- MAX is used because primary_flag is inside a grouped query.
AND MAX(primary_flag) = 'N'


UNION


SELECT
    employee_id,
    department_id

FROM Employee

-- For employees having multiple departments,
-- select the department explicitly marked as primary.
WHERE primary_flag = 'Y';


-- UNION combines both result sets and removes duplicates.

-- TC: Approximately O(n log n), execution-plan dependent.
-- SC: O(n) worst case for intermediate results.
