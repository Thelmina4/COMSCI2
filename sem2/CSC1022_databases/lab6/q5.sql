-- Section 3. World (Make default database)
-- USE world;
-- 5. Return a table with the name of the country and the average population of its cities.

-- select * from city;
-- Name char(35) 
-- CountryCode char(3) 
-- District char(20) 
-- Population

-- select * from country;
-- Code char(3)
-- Name char(52) 
-- Population

select c.name, avg(ct.population) as avgPop from country as c
join city as ct on c.code = ct.countryCode
group by c.code, c.name;

