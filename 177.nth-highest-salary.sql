--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M=N-1;
  RETURN (
      select distinct Salary from Employee order by Salary desc limit M, 1
  );
END

