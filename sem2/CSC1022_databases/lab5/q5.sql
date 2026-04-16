-- 5. Return the count 
-- and the last name of the actor
-- starring in the most number of films
-- (Difficulty : Hard)
-- (Hint: You may have to use nested query and group by and ANY / ALL keywords)

-- select first_name, last_name from actor

select count(fa.film_id), last_name from actor a
join film_actor as fa on a.actor_id = fa.actor_id
group by a.actor_id
having count(fa.film_id) >= all (
	select count(film_id) from film_actor
    group by actor_id
)
;