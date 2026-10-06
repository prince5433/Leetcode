# Write your MySQL query statement below
SELECT email from Person
GROUP BY email
HAvING COUNT(email)>1