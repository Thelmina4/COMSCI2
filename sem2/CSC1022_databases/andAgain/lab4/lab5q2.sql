-- Return the id of the player who in 1997 
-- scored more than 1000 points 
-- and in 1996 played for Chicago Bulls 
-- and got more than 350 rebounds. (Difficulty : Hard)

select * from players_teams pt, teams t
where pt.lgID = t.lgID
and pt.points > 1000
and pt.year = 1997
and t.lgID in (
select t.lgID from teams t
where t.name like "Chicago Bulls"
and t.year = 1996)


-- Select * from teams
-- where name like "%Chicago%";
-- year = 1996,  name like Chicago Bulls 