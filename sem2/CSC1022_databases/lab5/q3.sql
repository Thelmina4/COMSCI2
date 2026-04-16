-- Section 2: Sakila (Make Sakila the default database)
-- use sakila;
-- show tables
-- ;

-- list customers (customer id) whose total payments are less than at least one other
-- customer’s total payments. Order by Total payments (Hint: Use payment table)

-- When filtering based on a SUM(), you must use HAVING.

select customer_ID, Sum(amount) from payment
group by customer_ID
having sum(amount) < (
	select max(sub.total) from (
		SELECT  SUM(amount) AS total
		FROM payment
		GROUP BY customer_id
	) as sub
)
order by sum(amount)
;