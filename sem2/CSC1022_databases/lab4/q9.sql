-- 9. Count the total number of people in all the countries 
-- whose official language is Spanish. 
-- Use a nested query.

select * from country;
select sum(Population) from country
where code in (
	select CountryCode from countrylanguage
	where language = "Spanish"
    and IsOfficial = "T"
);
-- select CountryCode, language, IsOfficial from countrylanguage
-- where language = "Spanish"
-- and IsOfficial = "T";