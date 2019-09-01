--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--
# Write your MySQL query statement below

select d1.Name as Department, e1.name as Employee, e1.Salary as Salary 
from Department d1, Employee e1, Employee e2
where d1.Id = e1.DepartmentId and e1.DepartmentId = e2.DepartmentId and e1.Salary <= e2.Salary 
group by d1.Id, e1.name having count(distinct e2.Salary)<=3;
