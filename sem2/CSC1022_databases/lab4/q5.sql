-- 5. How many movies last more than 3 hours?
select count(length) from film
where length > 180;