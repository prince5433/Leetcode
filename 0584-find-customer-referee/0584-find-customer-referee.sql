
-- Write your MySQL query statement below

SELECT name
-- Select the customer's name because only names are required in the output

FROM Customer
-- Fetch customer records from the Customer table

WHERE referee_id != 2 OR referee_id IS NULL;
-- Include customers whose referee_id is not 2 OR whose referee_id is NULL
-- NULL is checked separately because comparisons with NULL don't return TRUE
