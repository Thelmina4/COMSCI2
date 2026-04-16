-- In the world schema, 
-- How would you find the total number of countries listed in the country table?

-- use world;
-- select count(code) from country;

-- Using the sakila database, 
-- how would you find the total replacement cost of all movies in the film table?
-- use sakila;
-- select sum(replacement_cost) from film;

-- In the world schema, 
-- which function identifies the population 
-- of the smallest country by land area or people in the country table?
-- NOT WORKING YET!!!
-- use world;
-- select * from country
-- order by SurfaceArea
-- ;

-- 4. If you want to find the typical (average) length of a movie in the sakila.film table, 
-- which query is correct?
-- USE sakila;
-- select avg(length) from film;

-- 5. In the basketball_men schema, 
-- how would you find the highest number of points scored by a player
--  in a single season in the master or player_stats table?

-- Use basketball_men;
-- select max(points) from players_teams
-- group by year;

-- use college;
-- select * from students;

-- use world;
select avg(population) from city;