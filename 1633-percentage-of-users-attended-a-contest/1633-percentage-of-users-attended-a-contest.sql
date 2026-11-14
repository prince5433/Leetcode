
SELECT
    contest_id,

    -- COUNT(DISTINCT user_id):
    -- Counts the number of unique users registered
    -- in the current contest.
    --
    -- * 100:
    -- Converts the participation ratio into a percentage.
    --
    -- Scalar subquery:
    -- Fetches the total number of users registered
    -- on the platform from the Users table.
    --
    -- ROUND(..., 2):
    -- Rounds the calculated percentage to 2 decimal places.
    ROUND(
        (COUNT( user_id)) * 100 /
        (SELECT COUNT(user_id) FROM Users),
        2
    ) AS percentage

FROM Register

-- Groups all registrations belonging to the same contest.
-- COUNT() will therefore calculate participants contest-wise.
GROUP BY contest_id

-- First sort by participation percentage in descending order.
-- If two contests have the same percentage,
-- sort their contest_id in ascending order.
ORDER BY percentage DESC, contest_id;

-- TC: Approximately O(n log n), depending on grouping and sorting.
-- SC: O(n) worst case for intermediate grouping/sorting.
