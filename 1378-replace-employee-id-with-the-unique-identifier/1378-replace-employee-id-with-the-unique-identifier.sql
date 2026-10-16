SELECT EmployeeUNI.unique_id,  -- Employee ki unique ID select karo; match na mile toh NULL
       Employees.name          -- Employee ka naam select karo
FROM Employees                 -- Left table: saare employees ko preserve karna hai
LEFT JOIN EmployeeUNI          -- Unique ID wali table ko join karo
ON Employees.id = EmployeeUNI.id; -- Dono tables ki employee IDs match karo