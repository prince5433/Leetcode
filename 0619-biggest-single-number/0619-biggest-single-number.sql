# Write your MySQL query statement below

SELECT
    MAX(num) AS num  -- Return the largest number among all single-occurrence numbers
FROM (
    SELECT
        num
    FROM MyNumbers
    GROUP BY num          -- Group identical numbers together
    HAVING COUNT(num) = 1   -- Keep only numbers that appear exactly once
) AS single_numbers;      -- Treat the filtered result as a temporary table