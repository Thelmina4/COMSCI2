-- Find all the basketball coach IDs with more than 900 of wins
-- , order by ascending number of losses

-- show databases;
-- use basketball_men;
-- show tables;
-- DESCRIBE coaches;
-- SELECT coachID, SUM(won) as totalWon from coaches
SELECT coachID from coaches
GROUP BY coachID
HAVING SUM(WON) > 900
ORDER BY SUM(won) ASC
