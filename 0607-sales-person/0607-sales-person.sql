SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (

    -- STEP 1: Find the sales_id of all salespersons
    -- who have placed at least one order with company RED.

    SELECT o.sales_id

    -- STEP 2: Take Orders table because it contains
    -- which salesperson placed which order and for which company.
    FROM Orders AS o

    -- STEP 3: JOIN Company table to identify the company name.
    -- Orders contains com_id, while Company contains company name.
    JOIN Company AS c
        ON o.com_id = c.com_id

    -- STEP 4: Keep only those orders that belong to RED.
    WHERE c.name = 'RED'

);

-- STEP 5: Outer query selects all salespersons
-- whose sales_id is NOT present in the inner query result.
-- Therefore, anyone who has even one order with RED is excluded.