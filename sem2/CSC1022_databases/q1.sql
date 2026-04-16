-- Section 1. Basketball (Make default database)
-- 1. Return the year and the average wins of the NBA teams 
-- after the 1990 season only when this
-- average is less than 40 
-- (Hint: Group By required)

-- use basketball_men;
select name, year, avg(won) as avgWon from teams
where lgID in ("NBA")
and year > 1990
group by name, year
having avgWon < 40;