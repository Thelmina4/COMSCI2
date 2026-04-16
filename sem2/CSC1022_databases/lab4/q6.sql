-- 6. Select the title and rating of suitable films
--  from the ‘Children’ category using a nested query.
-- (Hint: you have to use nested queries with multiple tables)

-- desc film;
-- select * from film_category;
 
-- select * from category; 

select f.title, f.rating from film f
where f.film_id in (
	select fg.film_id from film_category fg
	where fg.category_id = (
		select c.category_id from category c
		where c.name in ("Children")
	)
)
;

-- THIS FILM_ID S WHERE THE CATEGORY IS CHILDREN 

-- select fg.film_id from film_category fg
-- where fg.category_id = (
-- select c.category_id from category c
-- where c.name in ("Children");
-- )
-- GROUP BY fg.film_id;

-- THE CATEGORY_ID
-- select c.category_id from category c
-- where name in ("Children");