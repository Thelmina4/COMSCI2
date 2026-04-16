-- SHOW TABLES;
-- describe player_allstar;

SELECT playerID from players_teams
WHERE playerID IN (
	SELECT playerID
    FROM players_teams
    WHERE tmID = "MIA" 
    AND year = 1998
    AND minutes > 1200)
GROUP BY playerID;

SELECT p. playerID, p.firstName, p.lastName 
FROM players p
JOIN players_teams pt ON p.playerID = pt.playerID
WHERE pt.tmID = "MIA" 
	AND pt.year = 1998
	AND pt.minutes > 1200
;
