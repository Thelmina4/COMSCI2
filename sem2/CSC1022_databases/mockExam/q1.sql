-- This is a Mock Exam with questions of similar difficulty levels as the original exam to be held on 10th
-- April. You should familiarise yourself with the format and try to complete the questions within the
-- duration given.
-- Do not use any external help, AI chat bots or LLM’s as during the exam you won’t have access to
-- the internet. You have to use MySQL Workbench for writing the queries. So you should practice on
-- that.
-- Duration: 1 Hour

-- Section 1. Basketball (Make default database)
-- 1. Return the ID and the number of wins for the coach who was awarded 
-- ‘NBA Coach of the Year’ in the year 2000. 
-- [Hint: You should make use of awards_coaches table]

-- show tables;
select ac.id, c.won  from awards_coaches as ac, coaches as c
where ac.year = c.year
and ac.coachID = c.coachID
and ac.award = "NBA Coach of the Year"
and ac.year = 2000
group by ac.coachID
;
