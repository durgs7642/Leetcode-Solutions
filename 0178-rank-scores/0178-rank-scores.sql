-- Write your PostgreSQL query statement below
SELECT score, DENSE_RANK() OVER(ORDER BY score DESC) AS "Rank"
FROM Scores;