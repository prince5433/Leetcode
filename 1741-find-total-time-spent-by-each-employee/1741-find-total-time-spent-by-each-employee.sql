# Select the event date and rename it as day
SELECT
    event_day AS day,

    # Select employee ID to identify each employee
    emp_id,

    # Calculate the duration of each entry:
    # out_time - in_time
    # SUM() adds all entry durations belonging to the same group
    SUM(out_time - in_time) AS total_time

# Fetch records from the Employees table
FROM Employees

# Group records by employee and date
# This ensures each employee gets a separate total for each day
GROUP BY emp_id, event_day;