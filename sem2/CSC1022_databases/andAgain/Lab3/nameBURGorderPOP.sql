-- Find all cities
-- name ends with ‘burg’
-- ordered by population descending.

SELECT * FROM city
WHERE name LIKE "%burg"
ORDER BY Population DESC;