SELECT
    -- Fetch the product name for the final output
    Products.product_name,

    -- Calculate total units ordered for each product
    SUM(Orders.unit) AS unit

-- Use Products as the main table
FROM Products

-- Match each product with its corresponding orders using product_id
INNER JOIN Orders
    ON Products.product_id = Orders.product_id

-- Filter orders to include only February 2020
WHERE Orders.order_date >= '2020-02-01'
  AND Orders.order_date < '2020-03-01'

-- Group orders belonging to the same product together
GROUP BY Products.product_id, Products.product_name

-- Keep only products whose total ordered units are at least 100
HAVING SUM(Orders.unit) >= 100;