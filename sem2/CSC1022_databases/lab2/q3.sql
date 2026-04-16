-- 3. Did any actors have a surname with “queen” somewhere in the name?

select first_name, last_name from actor
where last_name like "%queen%";