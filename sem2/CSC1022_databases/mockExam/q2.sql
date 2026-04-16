-- use basketball_men;

-- 2. Find the number of points and the team containing ‘Los Angeles’ in its name 
-- who have scored in all the seasons a number of points 
-- 	higher than the number of points scored by all
-- the teams containing ‘Philadelphia’ in their name.
-- [Hint: Join and nested queries with an aggregate function for determining how many
-- points have scored by the teams with Philadelphia’ in their name]

-- select * from teams;
-- year, lgid, tmid, name - la /phili

-- players_teams
-- id, playerID, year, tmID, lgID, points

select pt.points from players_teams as pt
join teams as t 
    on pt.tmID = t.tmID
    and pt.year = t.year
where t.name like "%Los Angeles%" 

and pt.points >  (
select pt2.points from players_teams as pt2
join teams as t2 
	on pt2.tmID = t2.tmID
where t2.name like "%Philadelphia%"
order by pt2.points desc
limit 1
)
;
-- id, playerID, year, tmID, lgID, points
-- select pt2.points from players_teams as pt2
-- join teams as t2 
-- 	on pt2.tmID = t2.tmID
-- where t2.name like "%Philadelphia%"
-- order by pt2.points desc
-- limit 1
-- ;
