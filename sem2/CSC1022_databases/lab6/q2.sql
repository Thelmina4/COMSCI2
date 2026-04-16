-- 2. Return the average height for each team
--  in the year 1998,
--  ordered from the highest to the lowest.

-- (Hint: Similar to the previous query. In addition, you need to group by the name of the
-- teams and to order them)

-- select avg(height) as avgHeight from players;

select avg(p.height) as avgHeight FROM players as p
join players_teams as pt on p.playerID = pt.playerID
join teams as t on pt.tmID = t.tmID and pt.year = t.year
where pt.year = 1998
group by pt.tmID
order by avgHeight desc

