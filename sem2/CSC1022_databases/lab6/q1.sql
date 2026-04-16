-- Goal: Practice miscellaneous SQL queries and try out EXISTS, LIMIT clauses.
-- You have finished the lab when you have finished all queries.

-- Section 1. Basketball (Make default database)
-- use basketball_men;

-- 1. Return the max height 
-- 		among the players playing with ‘Chicago Bulls’ 
-- 		in the year 1998.

-- (Hint: you need to join three columns. Use players_teams.year to filter the requested year)


-- select height from players
-- order by height desc
-- limit 1;
-- OR
-- select max(height) as mheight from players;

select height from players
where playerID in (
	select playerID from players_teams
	where tmID in (
		select tmID from teams
		where name = "Chicago Bulls"
		and year = 1995
	)
    and year = 1995
)
order by height desc
limit 1
;