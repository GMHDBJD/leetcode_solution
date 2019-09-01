--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--

-- nested select, group

# Write your MySQL query statement below

select d1.name as Department, e1.name as Employee, e1.Salary as Salary from Department d1, Employee e1, (select e2.DepartmentId as d, max(Salary) as m from Employee e2 group by d) t where e1.DepartmentId=t.d and e1.Salary = t.m and t.d=d1.Id;
