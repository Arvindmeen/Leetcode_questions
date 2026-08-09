# Write your MySQL query statement below
-- SELECT(
--     SELECT DISTINCT salary FROM Employee
--     ORDER BY salary DESC
--     LIMIT 1 OFFSET 1
-- ) AS SecondHighestSalary;


-- by colaesc
SELECT COALESCE(
   (SELECT DISTINCT salary FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1),
    NULL
) AS SecondHighestSalary;