-- Section 2: Sakila (Make Sakila the default database)
-- 3. Find all actors who have appeared in at least one film. 
-- (Use EXISTS keyword)

-- use sakila;
select concat(first_name, " ", last_name) as fullname from actor as a
where exists (
	select * from film_actor as fa
    where fa.actor_ID = a.actor_ID
)
;
