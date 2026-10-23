SELECT w1.id                          -- Aaj ke record ki ID return karo
FROM Weather w1                       -- Weather table ko w1 alias do (aaj ka record)
JOIN Weather w2                       -- Same table ko w2 alias do (pichhle din ka record)
    ON DATEDIFF(w1.recordDate, w2.recordDate) = 1 -- Dono dates mein exactly 1 din ka difference ho
WHERE w1.temperature > w2.temperature; -- Aaj ka temperature pichhle din se zyada ho