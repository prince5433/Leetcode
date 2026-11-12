# Select the name of each query
SELECT
    query_name,

    # Calculate the average of rating / position for each query.
    # AVG() calculates the average ratio across all rows in the group.
    # ROUND(..., 2) rounds the result to 2 decimal places.
    ROUND(AVG(rating / position), 2) AS quality,

    # Calculate the percentage of poor queries.
    # CASE WHEN rating < 3 THEN 1 END:
    # Returns 1 for poor queries and NULL for all other queries.
    #
    # COUNT(CASE WHEN rating < 3 THEN 1 END):
    # COUNT ignores NULL values, so it counts only poor queries.
    #
    # COUNT(*):
    # Counts all rows in the current query_name group.
    #
    # Multiply by 100.0 to convert the ratio into a percentage.
    # ROUND(..., 2) rounds the percentage to 2 decimal places.
    ROUND(
        (COUNT(CASE WHEN rating < 3 THEN 1 END) * 100.0) / COUNT(*),
        2
    ) AS poor_query_percentage

# Fetch records from the Queries table
FROM Queries

# Create a separate group for every query_name.
# All calculations (AVG and COUNT) happen independently for each group.
GROUP BY query_name;