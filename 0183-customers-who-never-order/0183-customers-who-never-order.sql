# Write your MySQL query statement below

SELECT Customers.name AS Customers
-- Select the customer's name and rename the output column as "Customers"

FROM Customers
-- Take the Customers table as the main table

LEFT JOIN Orders
-- Keep all customers and join their matching orders

ON Customers.id = Orders.customerId
-- Match a customer with their orders using customer ID

WHERE Orders.customerId IS NULL;
-- Keep only those customers whose order is NULL, meaning they never placed an order