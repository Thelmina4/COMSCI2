-- Section 3. Sakila (Make default database)
-- use sakila;
-- 5. Return the email of the customers 
-- who have spent in total an amount more than 120 euro, DONE
-- with an average spent greater than 5 euro DONE
-- and a number of transaction between 28 and 35 (excluded). DONE
-- [Hint: Use of payment table

-- select * from payment as p
-- join customer as c
-- 	on c.customer_id = p.customer_id
-- ;

select c.email from customer as c
join payment as p
	on  c.customer_ID = p.customer_ID
group by c.customer_ID, c.email
having sum(p.amount) > 120
	and avg(p.amount) > 5
    and count(p.payment_id) > 28
    and count(p.payment_id) < 35
;