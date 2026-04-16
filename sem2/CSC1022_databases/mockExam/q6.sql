-- 6. Find a list of all films 
-- that contained the word “Airport” 
-- along with the names of the actors
-- that appeared in those films, 
-- ordered by last name.

select f.title, concat(a.first_name, " ", a.last_name) as fullname from film as f
join film_actor as fa
	on f.film_id = fa.film_id
join actor as a
	on fa.actor_id = a.actor_id
where f.title like "%Airport%"
order by a.last_name asc
;