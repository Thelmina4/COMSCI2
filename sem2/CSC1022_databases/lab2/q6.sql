-- Section 3. Basketball (Make default database)
-- 6. List the ID of the players who won an award in 1989. 
-- (Challenge : Don’t display duplicate ID’s)

-- use basketball_men;
-- show tables;
select distinct playerID from awards_players
where year = 1989
order by playerID
;