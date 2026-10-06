# Write your MySQL query statement below

SELECT *
-- Saare columns chahiye: id, movie, description, rating

FROM Cinema
-- Data Cinema table se lena hai

WHERE id % 2 = 1
-- % remainder nikalta hai
-- Agar id ko 2 se divide karne par remainder 1 aaye,
-- toh id odd hai
-- Example: 5 % 2 = 1 ✅

AND description != "boring"
-- Sirf wahi movies chahiye jinki description "boring" nahi hai
-- != ka matlab NOT EQUAL TO hai

ORDER BY rating DESC
-- Movies ko rating ke according sort karo
-- DESC = highest rating se lowest rating
-- Example: 9.1, 8.9, 8.6...