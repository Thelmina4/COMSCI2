-- Section 1. Basketball (Make default database)
-- 1. Find the NBA Coach of the Year IN 1995
-- and the number of games won

-- use basketball_men;
select c.coachID, c.year, c.won 
from coaches c
join awards_coaches ac
on c.coachID = ac.coachID
and c.year = ac.year
where ac.year = 1995
and ac.award = "NBA Coach of the Year"
;

-- select coachID from awards_coaches
-- where award = "NBA Coach of the Year"
-- and year = 1995;

-- select c.coachID, ac.award, c.won from coaches c
-- join awards_coaches ac on c.coachID = ac.coachID
-- where ac.year = 1995
-- and ac.award = "NBA Coach of the Year"
-- group by ac.coachID;