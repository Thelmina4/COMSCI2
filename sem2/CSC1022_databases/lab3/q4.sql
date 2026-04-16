-- Section 2: Sakila (Make Sakila the default database)
-- 4. Show all films with rating 'PG' or 'PG-13', 
-- ordered by length (shortest first) 
-- and then title

-- use sakila;
select title, length, rating  from film
where rating in ("PG", "PG-13")
order by length, title;
