--
-- @lc app=leetcode id=180 lang=mysql
--
-- [180] Consecutive Numbers
--
# Write your MySQL query statement below

select distinct l1.Num as ConsecutiveNums from Logs l1, Logs l2, Logs l3
where l1.num=l2.num and l1.num=l3.num and l1.id=l2.id+1 and l1.id=l3.id-1;
