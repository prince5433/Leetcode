SELECT

    -- Select the date so results are grouped date-wise
    Activities.sell_date,

    -- Count only unique products sold on each date
    COUNT(DISTINCT product) AS num_sold,

    -- Combine unique product names into one string
    -- ORDER BY product ASC sorts names alphabetically (A to Z)
    GROUP_CONCAT(
        DISTINCT product
        ORDER BY product ASC
    ) AS products

-- Read data from the Activities table
FROM Activities

-- Create a separate group for every selling date
GROUP BY sell_date;