# Write your MySQL query statement below

SELECT DISTINCT author_id AS id
-- Select author IDs, rename the output column to 'id',
-- and use DISTINCT to avoid duplicate author IDs

FROM Views
-- Read the data from the Views table

WHERE author_id = viewer_id
-- Keep only rows where the author viewed their own article

ORDER BY id;
-- Sort the author IDs in ascending order (default order)