SELECT Users.name,                       -- User ka naam select karo
SUM(Transactions.amount) AS balance      -- Total balance calculate karo
FROM Users                               -- Users table se data lo
INNER JOIN Transactions                  -- Matching transactions ko join karo
ON Users.account=Transactions.account    -- Account number ke basis par match karo
GROUP BY Users.account                   -- Har account ka group banao
HAVING SUM(Transactions.amount)>10000;   -- Sirf 10000 se zyada balance wale accounts rakho