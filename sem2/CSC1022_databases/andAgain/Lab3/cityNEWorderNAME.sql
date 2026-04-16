-- USE world;
-- Get a list of cities in 'USA' 
-- where the city name contains the letter sequence 'New'
-- ordered by name

-- SHOW tables;
SELECT Name FROM city
WHERE CountryCode = "USA" AND name LIKE "%New%"
ORDER BY name ASC;