# Write your MySQL query statement below

SELECT user_id,  -- Har user ki ID output mein dikhane ke liye

COUNT(follower_id) AS followers_count  -- Us user ko follow karne wale followers count karo

FROM Followers  -- Followers table se data lena hai

GROUP BY user_id  -- Har user ka separate group banao, taaki followers alag-alag count hon

ORDER BY user_id;  -- Result ko user_id ke ascending order mein sort karo

-- TC: O(n) expected, indexing aur database execution plan par depend karta hai
-- SC: O(k) tak ho sakta hai, jahan k distinct user_id ki sankhya hai; execution plan par depend karta hai