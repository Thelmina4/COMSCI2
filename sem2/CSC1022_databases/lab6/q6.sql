-- 6. List the top 10 most used languages, 
-- 		the number of countries which speak the language and
-- 		total amount of people who speak this language 
-- 		(not the percent). 
--         Order the results by the
-- 			total number of people who speak these languages
--             from highest to lowest.
-- (Hint: Use LIMIT to display only 10 and think how to convert percentages into absolute)
 
-- select language from countrylanguage
-- group by language
-- order by count(CountryCode) desc
-- limit 10
-- ;

select cl.language, 
	count(cl.CountryCode) as c_code, 
	sum((cl.Percentage / 100) * c.population) as speakers 
    from countrylanguage as cl
join country as c on cl.CountryCode = c.Code
group by cl.Language
order by speakers desc
limit 10
;