# Write your MySQL query statement below

UPDATE Salary
SET sex = IF(sex = 'm', 'f', 'm');
-- If sex is 'm', change it to 'f'; otherwise, change it to 'm'.
-- This swaps 'm' and 'f' values in a single UPDATE statement.