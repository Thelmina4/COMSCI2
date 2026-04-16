-- 8. Return the name of the countries 
-- where English is the official language, 
-- the form of government is Republic 
-- and life expectancy is greater than 70 years. 
-- (Use Join)
-- (Hint: You need to join two tables)

select Name from country
where GovernmentForm = "Republic"
and LifeExpectancy > 70
and code in (
	select CountryCode from countrylanguage
	where Language = "English"
	and IsOfficial = "T"
)
group by name
;
-- BOTH WORK

-- select CountryCode from countrylanguage
-- where Language = "English"
-- and IsOfficial = T;

-- select c.name from country as c
-- join countrylanguage as cl
-- on c.code = cl.countryCode
-- where cl.Language = "English"
-- and cl.IsOfficial = "T"
-- and c.GovernmentForm = "Republic"
-- and c.LifeExpectancy > 70
-- group by c.name;