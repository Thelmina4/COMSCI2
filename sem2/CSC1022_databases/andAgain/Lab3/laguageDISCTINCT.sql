-- Show tables;
-- DESC countrylanguage;

SELECT Language, MAX(Percentage) AS MaxPercentage 
FROM countrylanguage
WHERE Percentage > 50
GROUP BY Language
ORDER BY MaxPercentage;
