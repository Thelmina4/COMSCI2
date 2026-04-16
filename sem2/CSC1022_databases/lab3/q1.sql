-- Section 1. Basketball (Make default database)
-- 1. List the ID of the players who won an award in 1989.
--  (Challenge : Don’t display duplicate ID’s)

-- use basketball_men;
select distinct playerID from awards_players
where year = 1989;

-- select count(distinct playerID) from awards_players
-- where year = 1989;