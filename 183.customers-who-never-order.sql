--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

-- not in, not exists, left join

# Write your MySQL query statement below

select c1.Name as Customers from Customers c1 where not exists (select 1 from Orders o1 where c1.Id=o1.CustomerId);

