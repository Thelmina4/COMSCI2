-- 8. Return the count and average life expectancy
-- of the countries grouped by continent of origin 
-- with an average life expectancy greater than 45 years. (Hint: Group By required)


-- select count(*) from country where continent = "North America";

select continent, count(*), avg(LifeExpectancy) from country
group by continent
having avg(LifeExpectancy) > 45
;
