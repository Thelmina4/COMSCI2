-- Section 3. World (Make default database)
-- use world;
-- 6. Select countries whose population is greater
--  than every country in the 'Caribbean' region.
-- Display country name and the population.
-- (Use ANY / ALL / SOME keyword)

-- select count(name) as c from country
-- where population > (
-- 	select population from country
-- 	where region = "caribbean"
-- 	and population = (
-- 	select max(population) from country
-- 		where region = "caribbean"
-- 	)
-- )
-- ;

select name, population from country
where population > all (
	select population from country
    where region = "caribbean"
)
;

