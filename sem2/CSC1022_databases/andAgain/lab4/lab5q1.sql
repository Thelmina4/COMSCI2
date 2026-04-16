-- Find the NBA Coach of the Year IN 1995 
-- and the number of games won

-- use basketball_men;
select c.lgID, c.coachID, c.won, ac.year from coaches c, awards_coaches ac
where c.coachID = ac.coachID
and c.year = ac.year
AND c.lgID  LIKE "NBA"
and ac.award = "NBA Coach of the Year"
and c.year=1995;
