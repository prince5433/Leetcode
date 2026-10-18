SELECT tweet_id             -- Invalid tweet ki ID return karo
FROM Tweets                 -- Tweets table se data lo
WHERE LENGTH(content) > 15; -- 15 se zyada characters wale tweets filter karo