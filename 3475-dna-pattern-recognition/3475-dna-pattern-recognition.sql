SELECT
    sample_id,
    dna_sequence,
    species,

    -- Check whether the DNA sequence starts with 'ATG'.
    -- 'ATG%' means the string must begin with ATG,
    -- followed by zero or more characters.
    -- IF(condition, 1, 0) returns 1 if the condition is true,
    -- otherwise it returns 0.
    IF(dna_sequence LIKE 'ATG%', 1, 0) AS has_start,

    -- Check whether the DNA sequence ends with TAA, TAG, or TGA.
    -- REGEXP checks the sequence using a regular expression.
    -- '$' means the end of the string.
    -- '|' means OR, so any one of these three endings is enough.
    IF(dna_sequence REGEXP 'TAA$|TAG$|TGA$', 1, 0) AS has_stop,

    -- Check whether 'ATAT' appears anywhere in the DNA sequence.
    -- '%' before and after ATAT allows any characters
    -- to appear before or after the pattern.
    IF(dna_sequence LIKE '%ATAT%', 1, 0) AS has_atat,

    -- Check whether the sequence contains at least
    -- three consecutive G characters.
    -- 'GGG' matches three Gs together.
    -- It also matches inside a longer sequence, such as GGGG.
    IF(dna_sequence REGEXP 'GGG', 1, 0) AS has_ggg

-- Read each DNA sample from the Samples table.
FROM Samples

-- Return the samples in ascending order of sample_id.
ORDER BY sample_id;