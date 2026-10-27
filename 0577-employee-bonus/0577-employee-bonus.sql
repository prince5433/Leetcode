# Write your MySQL query statement below

SELECT Employee.name,       -- Employee ka naam output mein dikhane ke liye
       Bonus.bonus          -- Employee ka bonus amount dikhane ke liye

FROM Employee               -- Employee table ko main table rakha, taaki saare employees consider hon

LEFT JOIN Bonus             -- Bonus table se matching bonus records jodo;
                            -- LEFT JOIN bonus record na hone par bhi employee ko preserve karta hai

ON Employee.empId = Bonus.empId  -- Dono tables mein same employee ID wale records match karo

WHERE Bonus.bonus IS NULL   -- Jin employees ka bonus record nahi hai, unhe include karo
   OR BONUS.bonus < 1000;   -- Ya jin employees ka bonus 1000 se kam hai, unhe include karo

-- TC: Exact time complexity execution plan, indexes aur table size par depend karti hai.
-- SC: JOIN aur filtering ke intermediate results ke liye extra memory/storage lag sakti hai.