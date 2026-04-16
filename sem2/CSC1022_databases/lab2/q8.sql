-- 8. Return the name and the number of wins at home 
-- of the teams with ‘Chicago' in their name
-- during the season 1994.

-- select name, homeWon from teams
-- where name like "%Chicago%"
-- and year = 1994;

-- (Challenge : Return the name of the teams with ‘C’ in their name 
-- during the season 1994 where they won more games at home than away)

select name, homeWon, awayWon from teams
where name like "%c%"
and year = 1994
and homeWon > awayWon;
