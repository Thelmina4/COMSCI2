-- 4. What monarch (of any type) 
-- is the head of stat over the
--  greatest number of cities? 
-- Return the top three results.

select c.HeadOfState, count(ct.id) from country as c
join city as ct
on c.code = ct.CountryCode
where c.GovernmentForm like "%monarch%"
group by c.HeadOfState
order by count(ct.id) desc
limit 3
;
