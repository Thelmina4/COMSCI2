-- 4. Count the number of movies belonging to the ‘Action’ category
-- select * from film_category;
-- film_id, category_id

-- select * from category;
-- category_id, name

select count(distinct film_id) from film_category
where category_id in (
	select category_id from category
    where name = "Action"
)
;