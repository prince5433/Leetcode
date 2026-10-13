
-- Write your MySQL query statement below

SELECT product_name, year, price
-- Select the product name, sale year, and price required in the output

FROM Sales
-- Take Sales as the main table because we need details of every sale

INNER JOIN Product
-- Join Product table to get the product names corresponding to each sale

ON Sales.product_id = Product.product_id;
-- Match both tables using product_id; '=' is the standard SQL equality operator
