SELECT
    employee_id,
    IF(
        employee_id MOD 2 = 1 AND name NOT LIKE 'M%',
        salary,
        0
    ) AS bonus
FROM Employees
ORDER BY employee_id;

-- TC: O(n log n), approximately, due to sorting.
-- SC: O(1) auxiliary space, excluding sorting internals.