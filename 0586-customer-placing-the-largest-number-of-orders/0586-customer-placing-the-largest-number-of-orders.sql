# Write your MySQL query statement below

SELECT
    customer_number  -- Return the customer who placed the maximum number of orders
FROM Orders
GROUP BY customer_number  -- Create a separate group for each customer
ORDER BY COUNT(order_number) DESC  -- Sort customers by order count (highest first)
LIMIT 1;  -- Return only the customer with the most orders