-- 7. Using JOIN, 
-- get the name and the population
--  of the Irish city with more than 200,000 inhabitants.

-- (you can also practice using a nested query)

-- select code from country
-- where name = "Ireland"
-- ;

select name, population from city
where countryCode = (
	select code from country
    where name = "ireland"
)
and population > 200000
;