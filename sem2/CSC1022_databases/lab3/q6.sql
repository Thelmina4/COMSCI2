-- 6. List all films whose title starts with 'THE', ordered by title.
select * from film
where title like "the%"
order by title;