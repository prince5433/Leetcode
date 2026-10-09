# Write your MySQL query statement below

SELECT product_id
-- Select the product IDs because we only need IDs in the output

FROM Products
-- Fetch the data from the Products table

WHERE low_fats = 'Y' AND recyclable = 'Y';
-- Keep only those products that satisfy BOTH conditions:
-- low_fats must be 'Y' and recyclable must also be 'Y'