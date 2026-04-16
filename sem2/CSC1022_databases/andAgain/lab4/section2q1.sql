-- USE sakila;
-- SHOW tables;

-- Return the title and the description of the movie
-- having length of at least 2 hours
-- and containing the word ‘wrestler’ in the description
-- and ‘agent’ in the title

SELECT title, description FROM film
WHERE description LIKE "%wrestler%"
	AND length >= 120
    AND title LIKE "%agent%";
