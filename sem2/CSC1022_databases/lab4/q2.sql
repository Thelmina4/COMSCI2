-- 2. Find all the basketball coach IDs 
-- with more than 900 of wins, 
-- order by ascending number of losses
-- (Hint: Group By required)

select coachID, sum(won) as sumWon from coaches
group by coachID
having sumWon > 900
order by sum(lost) asc
;
