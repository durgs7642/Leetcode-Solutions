-- Write your PostgreSQL query statement below
SELECT
(
SELECT DISTINCT salary
FROM
(SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) as rank
FROM Employee
) AS RankedSalaries
WHERE rank = 2
) AS Secondhighestsalary ;