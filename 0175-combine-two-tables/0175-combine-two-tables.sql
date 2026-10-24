SELECT Person.firstName,       -- Person ka first name select karo
       Person.lastName,        -- Person ka last name select karo
       Address.city,           -- Person ke address ka city select karo
       Address.state           -- Person ke address ka state select karo
FROM Person                    -- Person table se data lo
LEFT JOIN Address              -- Saare persons ko preserve karte hue Address table join karo
ON Person.personId=Address.personId; -- Dono tables ko personId ke basis par match karo