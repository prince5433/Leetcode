# Write your MySQL query statement below

SELECT DISTINCT a.num AS ConsecutiveNums  -- Aise numbers return karo jo consecutively aaye hain; DISTINCT duplicates hatata hai

FROM Logs a  -- Logs table ki first copy, jiska naam a hai

JOIN Logs b  -- Same table ki second copy, jiska naam b hai
ON a.id + 1 = b.id  -- Check karo ki b ki ID, a ki ID se exactly 1 zyada ho

JOIN Logs c  -- Same table ki third copy, jiska naam c hai
ON b.id + 1 = c.id  -- Check karo ki c ki ID, b ki ID se exactly 1 zyada ho

WHERE a.num = b.num  -- First aur second row ke numbers same hone chahiye
AND b.num = c.num;  -- Second aur third row ke numbers bhi same hone chahiye

-- TC: O(n) expected, agar IDs ke liye efficient indexing available ho
-- SC: O(n) tak ho sakta hai, query execution plan aur intermediate results par depend karta hai