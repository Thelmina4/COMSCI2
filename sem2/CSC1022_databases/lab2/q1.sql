-- use sakila;
-- Show tables;
-- 1. Which movies have a title containing the word “games”?
select title from film
where title like "%games%"
;