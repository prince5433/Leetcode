SELECT customer_id,                    -- Customer ki ID select karo
       COUNT(*) AS count_no_trans       -- Bina transaction wali visits count karo
FROM Visits                             -- Saari visits se start karo
LEFT JOIN Transactions                  -- Transactions table ko LEFT JOIN karo
ON Visits.visit_id = Transactions.visit_id -- Same visit ko match karo
WHERE transaction_id IS NULL            -- Sirf unmatched visits rakho
GROUP BY customer_id;                   -- Har customer ki visits ka count nikalo