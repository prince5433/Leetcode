
SELECT *
FROM Users

-- REGEXP_LIKE() checks whether the email matches
-- the given regular expression pattern.
--
-- Third argument 'c' means CASE-SENSITIVE matching.
-- This is important because the domain must be exactly
-- @leetcode.com in lowercase.
WHERE REGEXP_LIKE(

    mail,

    -- ^ : Email must start from the beginning.

    -- [A-Za-z] : First character must be an English letter.
    -- Uppercase (A-Z) and lowercase (a-z) are allowed.

    -- [A-Za-z0-9_\.\-]* :
    -- Remaining prefix can contain:
    -- Letters (A-Z, a-z)
    -- Numbers (0-9)
    -- Underscore (_)
    -- Dot (\.)
    -- Hyphen (\-)
    --
    -- * means zero or more occurrences.
    -- Therefore, a single-character prefix is also allowed.

    -- @leetcode : Exact domain name.
    -- [.]       : Matches a literal dot.
    -- com       : Domain extension.

    -- $ : Email must end exactly after .com.
    -- No additional characters are allowed.

    '^[A-Za-z][A-Za-z0-9_\.\-]*@leetcode[.]com$',

    'c' -- case sensitive ke liye
);

-- TC: O(n * m) approximately
-- n = number of email records
-- m = average email length
-- SC: O(1) auxiliary space per row, excluding regex engine internals.
