-- SHOW DATABASES;
-- USE sakila;
-- 6. List all films whose title starts with 'THE', ordered by title 
-- SHOW TABLES;
SELECT * FROM film
WHERE title LIKE "THE%"
ORDER BY title ASC;