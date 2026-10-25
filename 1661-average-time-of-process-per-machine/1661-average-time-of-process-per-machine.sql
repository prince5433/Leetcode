SELECT a.machine_id,                         -- Start record wali machine ki ID select karo
ROUND(AVG(b.timestamp-a.timestamp),3) AS processing_time      -- Average processing time 3 decimals tak round karo
FROM Activity a                              -- Activity table ko start records ke liye alias a do
JOIN Activity b                              -- Same table ko end records ke liye alias b do
ON a.machine_id=b.machine_id                 -- Same machine ke records match karo
AND a.process_id=b.process_id                -- Same process ke records match karo
AND a.activity_type='start'                  -- a mein start wali row select karo
AND b.activity_type='end'                    -- b mein end wali row select karo
GROUP BY a.machine_id;                       -- Har machine ka separate average nikalo