--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- left join

# Write your MySQL query statement below
select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId;

