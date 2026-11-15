
SELECT
    *,
    
    -- Check whether the given three sides can form a valid triangle.
    --
    -- Triangle inequality theorem:
    -- Sum of any two sides must be STRICTLY greater
    -- than the third side.

    IF(
        x + y > z AND
        y + z > x AND
        z + x > y,

        -- If all three conditions are TRUE:
        "Yes",

        -- If even one condition is FALSE:
        "No"

    ) AS triangle

FROM Triangle;
