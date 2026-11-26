SELECT
    IF(
        id % 2 = 1 AND id = (SELECT COUNT(*) FROM Seat), -- Odd count mein last student ki ID same rakho
        id,
        IF(id % 2 = 1, id + 1, id - 1) -- Odd ID ko next, even ID ko previous ID par shift karo
    ) AS id,
    student -- Student ka naam original row se lo; swapped ID ke saath output hoga
FROM Seat
ORDER BY id; -- Swapped IDs ko ascending order mein arrange karo