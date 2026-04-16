-- show databases;
-- USE basketball_men;
-- show tables;
-- desc teams;
SELECT tmID, year, AVG(won) as avgWon FROM teams
WHERE year > 1990
GROUP BY tmID, year
HAVING avgWon < 40;