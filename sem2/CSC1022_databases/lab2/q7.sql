-- 7. List the ID of the players who 
-- scored more than 400 points 
-- in less than 900 minutes played
-- during the season 1998

select * from players_teams
where points > 400
and minutes < 900
and year = 1998;