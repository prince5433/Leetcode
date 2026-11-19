
SELECT
    user_id,

    -- MAX() returns the latest (greatest) login timestamp
    -- among all login records belonging to the same user.
    MAX(time_stamp) AS last_stamp

FROM Logins

-- Filter login records to include only dates from 2020.
-- BETWEEN includes both the starting and ending values.
WHERE time_stamp BETWEEN '2020-01-01 00:00:00'
                     AND '2020-12-31 23:59:59'

-- Group the filtered records user-wise.
-- Each user gets one group containing their 2020 logins.
GROUP BY user_id;


-- TC: Approximately O(n log n), depending on execution plan.
-- SC: O(n) worst case for grouping.
