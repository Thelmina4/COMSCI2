-- 3. Print the players (playerID) 
-- of the Miami 1998 team 
-- with over 1200 minutes played. 
-- Use a nested query in your answer.

-- use basketball_men;
-- desc players_teams;
-- select tmID from teams
-- where name like "%MIAMI%"
-- and year = 1998;

-- SELECT playerID from players_teams
-- WHERE playerID IN (
-- 	SELECT playerID
--     FROM players_teams
--     WHERE tmID = "MIA" 
--     AND year = 1998
--     AND minutes > 1200)
-- GROUP BY playerID;

-- (Challenge: Can you display the player names as well?)

SELECT p.playerID, p.firstName, p.lastname from players p
join players_teams pt on p.playerID = pt.playerID
WHERE pt.tmID = "MIA" 
    AND pt.year = 1998
    AND pt.minutes > 1200
;

-- SELECT p.playerID, p.firstName, p.lastName 
-- FROM players p
-- JOIN players_teams pt ON p.playerID = pt.playerID
-- WHERE pt.tmID = "MIA" 
-- 	AND pt.year = 1998
-- 	AND pt.minutes > 1200
-- ;
