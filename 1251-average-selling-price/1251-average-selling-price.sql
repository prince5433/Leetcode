
SELECT p.product_id,
-- Har product ki ID output mein dikhani hai

IFNULL(ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0) AS average_price
-- Weighted average calculate karo, 2 decimal places tak round karo,
-- aur agar result NULL ho toh 0 return karo

FROM Prices p
-- Prices table se start karo

LEFT JOIN UnitsSold u
-- Sales ko jodo aur unsold products ko bhi preserve karo

ON p.product_id = u.product_id
-- Dono tables mein product ID match karo (= use hoga, minus nahi)

AND u.purchase_date >= p.start_date
-- Purchase date price ki start date par ya uske baad honi chahiye

AND u.purchase_date <= p.end_date
-- Purchase date price ki end date par ya usse pehle honi chahiye

GROUP BY p.product_id;
-- Har product ka separate average calculate karo
