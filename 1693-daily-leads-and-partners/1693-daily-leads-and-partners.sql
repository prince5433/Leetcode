SELECT date_id,                              -- Sales ki date select karo
       make_name,                            -- Make ka naam select karo
       COUNT(DISTINCT lead_id) AS unique_leads,       -- Duplicate leads ko ignore karke unique leads count karo
       COUNT(DISTINCT partner_id) AS unique_partners  -- Duplicate partners ko ignore karke unique partners count karo
FROM DailySales                             -- DailySales table se records lo
GROUP BY date_id, make_name;                -- Har date aur make ke combination ka separate group banao