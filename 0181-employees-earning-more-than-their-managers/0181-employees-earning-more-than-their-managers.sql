# Write your MySQL query statement below

SELECT e.name AS Employee
-- Employee ka naam return karna hai

FROM Employee e
-- Employee table ko 'e' naam diya
-- 'e' employee ko represent karega

JOIN Employee m
-- Same Employee table ko dobara join kiya
-- 'm' manager ko represent karega

ON e.managerId = m.id
-- Employee ka managerId
-- manager ke id ke equal hoga
-- Isse employee aur uske manager ka relation milega

WHERE e.salary > m.salary
-- Sirf wahi employees chahiye
-- jinki salary unke manager se zyada hai