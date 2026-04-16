-- Section 2. World (Make default database)
-- 3. For each country in North America show the name of the capital, the population
-- of the capital, the name of the country and the official language(s).
-- [Hint: Three joins (it is possible to obtain more than one row for each city)]

-- Capital, Continent, name, population, 
use World;
select ct.name, ct.population, c.code, cl.language from city as ct
join country as c
	on ct.id = c.capital
	and ct.countryCode = c.Code
join countryLanguage as cl
	on ct.countryCode = cl.countryCode
 where c.continent = "North America"
 and cl.isOfficial = "T"
 ;
