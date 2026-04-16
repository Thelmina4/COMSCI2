-- 5. What countries have a different local name?
-- show tables
select Name, LocalName from country
where Name <> LocalName;