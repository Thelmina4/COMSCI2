-- Section 3. World (Make default database)
-- 7. Count how many cities are located in a European country 
-- with more than 90 million inhabitants? 
-- Use a nested query.

-- use World ;
select count(*) as total_cities from city ct
where ct.CountryCode in (
	select c.Code from country c
	where c.continent = "europe"
    and c.population > 90000000
);

-- GET THE COUNTRY CODE 
-- CITY.CountryCode  == COUNTRY.Code
-- select Code from country
-- where continent like "europe";
