# Write your MySQL query statement below

SELECT name, population, area
-- Select the country name, population and area because these are required in the output

FROM World
-- Take the data from the World table

WHERE area >= 3000000 OR population >= 25000000;
-- Keep the country if its area is at least 3,000,000 OR its population is at least 25,000,000