SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1 -- Highest salary skip karke next distinct salary lo
) AS SecondHighestSalary; -- Subquery ka result is naam ke column mein return karo