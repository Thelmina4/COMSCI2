-- 8. Find all cities whose name ends with ‘burg’ , ordered by population descending.

select * from city
where name like "%burg"
order by population desc;
