-- Section 3. World (Make default database)
-- 7. Get a list of cities in 'USA' 
-- where the city name contains the letter sequence 'New', 
-- ordered by name. 
-- (Hint : use country code in city table)

-- use world;
select * from city
where countryCode in ("USA")
and name like "%new%"
order by name;