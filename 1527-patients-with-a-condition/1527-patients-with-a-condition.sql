SELECT
    patient_id,                 -- Patient ki ID select karo
    patient_name,               -- Patient ka naam select karo
    conditions                  -- Patient ki saari condition codes select karo
FROM Patients                  -- Patients table se data lo
WHERE conditions LIKE 'DIAB1%' -- Check karo ki conditions DIAB1 se start hoti hain
   OR conditions LIKE '% DIAB1%'; -- Ya DIAB1 se pehle space ho, yani code baad mein aata ho