# Write your MySQL query statement below

SELECT
    s.student_id,                 -- Student ki ID, taaki har student ka result separately identify ho
    s.student_name,               -- Student ka naam output mein dikhane ke liye
    sub.subject_name,              -- Har student ke saath har subject ka result chahiye
    COUNT(e.student_id) AS attended_exams -- Matching exam records count karo; NULL count nahi hota, isliye zero attendance ka answer 0 aata hai

FROM Students s                    -- Students table ko s alias diya, jahan se saare students milenge

CROSS JOIN Subjects sub            -- Har student ko har subject ke saath pair karo;
                                   -- isse un subjects ki rows bhi banengi jinka student ne exam nahi diya

LEFT JOIN Examinations e           -- Exam records match karo, lekin saare student-subject combinations preserve rakho
    ON s.student_id = e.student_id -- Same student ki exam attendance match karne ke liye
    AND sub.subject_name = e.subject_name -- Usi student ka same subject match karne ke liye;
                                          -- dono conditions se incorrect student-subject pairing nahi hogi

GROUP BY
    s.student_id,                  -- Alag-alag students ko separate groups mein rakho
    s.student_name,                -- Student ka naam group mein identify karne ke liye
    sub.subject_name               -- Har student ke har subject ka separate group banao;
                                   -- duplicate exam rows ek group mein aayengi aur COUNT unhe ginega

ORDER BY
    s.student_id,                  -- Output ko student ID ke ascending order mein sort karo
    sub.subject_name;              -- Same student ke subjects ko alphabetical order mein sort karo

-- TC: Query ka exact time complexity database execution plan, indexes aur row counts par depend karta hai.
-- SC: Intermediate result aur grouping ke liye memory/storage lag sakti hai; exact usage execution plan par depend karta hai.