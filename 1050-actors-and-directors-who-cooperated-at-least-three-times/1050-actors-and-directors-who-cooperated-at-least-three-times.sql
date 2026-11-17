
SELECT
    actor_id,
    director_id

FROM ActorDirector

-- Group records using both actor_id and director_id.
-- This creates a separate group for every unique actor-director pair.
--
-- Example:
-- (1,1) -> All records where actor_id = 1 AND director_id = 1
-- (1,2) -> All records where actor_id = 1 AND director_id = 2
-- (2,1) -> All records where actor_id = 2 AND director_id = 1
GROUP BY actor_id, director_id

-- COUNT(*) counts the total number of rows in each group.
-- Every row represents one cooperation between an actor and director.
--
-- >= 3 means the same pair must have cooperated
-- at least three times.
--
-- HAVING filters groups after GROUP BY and aggregation.
HAVING COUNT(*) >= 3;


-- TC: Approximately O(n log n), depending on grouping implementation.
-- SC: O(n) worst case for intermediate grouping.
