-- Section 2. World (Make default database)

-- 4. Get a list of all the cities with over 1 million people, ordered alphabetically.
-- use world;
-- show tables;
select * from city
where population > 1000000
order by Name
;