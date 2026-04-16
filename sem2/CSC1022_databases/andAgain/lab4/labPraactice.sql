-- use basketball_men;
-- select DISTINCT playerID, year from awards_players;
-- where year = 1989;

-- q2
-- 2. List the ID of the players who scored more than 400 points 
-- in less than 900 minutes played during the season 1998
-- select playerID, minutes, points, year from player_teams
-- where points > 400
-- and minutes < 900
-- and year = 1998;

-- Return the name and the number of wins at home of the teams with ‘Chicago' in their name
-- during the season 1994. (Challenge : Return the name of the teams with ‘C’ in their name
-- during the season 1994 where they won more games at home than away)
-- select name, year, homeWon from teams
-- where name like "%C%"
-- and year = 1994
-- and homeWon > awayWon;

-- 4. Show all films with rating 'PG' or 'PG-13', ordered by length (shortest first) and then title.
-- Use sakila;
-- Select * from film
-- where rating like "%PG%"
-- -- where rating in ("PG", "PG-13")
-- ORDER by length, title ASC;

--  List all distinct film ratings in the database, sorted alphabetically.
-- select distinct rating from film order by rating ASC;

--  List all films whose title starts with 'THE', ordered by title.
-- Select title from film
-- where title like "the%"
-- order by title;

-- Get a list of cities in 'USA' where the city name contains the letter sequence 'New', ordered by name. (Hint : use country code in city table)

-- use world;
-- select * from city
-- where CountryCode = "USA" and name like "%New%"
-- order by name;

-- Find all cities whose name ends with ‘burg’ , ordered by population descending.
-- select * from city
-- where CountryCode = "USA" and name like "%burg"
-- order by Population;

-- select distinct language, countryCode, percentage from countrylanguage
-- where percentage > 50
-- order by percentage DESC;

-- LAB 4
-- 1. Return the year and the average wins of the NBA teams after the 1990 season only when this
-- average is less than 40 (Hint: Group By required)
-- use basketball_men;
-- SELECT year, avg(won) from teams
-- where year > 1990 group by year
-- having avg(won) < 40;

-- Find all the basketball coach IDs with more than 900 of wins
-- , order by ascending number of losses
-- SELECT coachID from coaches
-- GROUP BY coachID
-- HAVING SUM(WON) > 900
-- ORDER BY SUM(won) ASC

-- 3. Print the players (playerID) of the Miami 1998 team with over 1200 minutes played. Use a nested query in your answer. (Challenge: Can you display the player names as well?)
-- select firstName, lastName playerID from player_teams 
-- where playerID in (
-- where year = 1998 and minutes > 1200
-- and tmID in 
-- (select tmID from teams where name like "%miami%"))


-- id -> 1997
-- pts -> 1000
-- team -> chicago bulls
-- rebounds -> 35
select distinct pt1.playerID, pt1.points from players_teams pt1, teams t, players_teams pt2
where pt1.points > 1000
and pt1.year = 1997
and pt1.playerID = pt2.playerID 
and pt2.rebounds > 350 and pt2.year =1996
and t.tmID and pt2.tmID and t.year = pt2.year
and t.name = "chicago bulls";