SELECT
    -- Return the activity date as the output column 'day'
    activity_date AS day,

    -- Count each user only once per day, even if they perform multiple activities
    COUNT(DISTINCT user_id) AS active_users

-- Fetch records from the Activity table
FROM Activity

-- Consider only activities within the given 30-day period (both dates included)
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'

-- Create a separate group for each activity date
GROUP BY activity_date;