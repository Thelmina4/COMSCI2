-- 4. Return the actors full name in any movie containing the word ‘pirates’ in the title.
-- select * from film
-- where title like "%pirates%";

select a.first_name, a.last_name from actor as a
join film_actor as fa
	on a.actor_id = fa.actor_id
join film as f
	on fa.film_ID = f.film_id
where f.title like "%pirates%"
group by a.actor_id
;