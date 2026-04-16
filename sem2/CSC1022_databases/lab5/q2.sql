-- 2. Return the id of the player 
-- who in 1997 scored more than 1000 points 
-- and in 1996 played for Chicago Bulls 
-- and got more than 350 rebounds.
--  (Difficulty : Hard)

-- (Hint: You could need to join the same table twice. You need to obtain the players’ ID list
-- matching the requirements for 1997, and the list for 1996. The inner join will give you
-- the final player. You need to join again with another table to ensure the correct name of
-- the team.)

-- select playerID from players_teams
-- where year = 1997
-- and points = 1000;

-- select tmID from teams
-- where name = "Chicago Bulls"
-- and year = 1996;

-- select playerID
-- use basketball_men;
SELECT pt97.playerID
FROM players_teams AS pt97
-- Join the table to itself to get the 1996 data for the same player
JOIN players_teams AS pt96 
    ON pt97.playerID = pt96.playerID
-- Join the teams table to find the ID for the Chicago Bulls
JOIN teams AS t 
    ON pt96.tmID = t.tmID 
    AND pt96.year = t.year
WHERE 
    -- 1997 Requirements
    pt97.year = 1997 
    AND pt97.points > 1000
    -- 1996 Requirements
    AND pt96.year = 1996
    AND pt96.rebounds > 350
    AND t.name = 'Chicago Bulls';