-- 9. Which distinct languages represent the majority language in at least one country? 
-- Display ordered by percentage descending. 
-- (Hint: Use ‘countrylanguage’ table)

select language, max(percentage) from countrylanguage
where Percentage > 50
group by language
order by max(percentage)
;