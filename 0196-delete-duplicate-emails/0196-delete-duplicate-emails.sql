-- Delete only those rows that have a duplicate with a smaller ID
DELETE p1

-- Use Person table twice so we can compare its rows
FROM Person p1

-- Compare each row with another row from the same table
JOIN Person p2

-- Emails must match, otherwise they are not duplicates
ON p1.email = p2.email

-- Delete the row with the bigger ID; keep the smaller ID
AND p1.id > p2.id;