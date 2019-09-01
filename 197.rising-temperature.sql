--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- TO_DAYS

# Write your MySQL query statement below

SELECT w1.Id FROM Weather w1, Weather w2 WHERE w1.Temperature > w2.Temperature and TO_DAYS(w1.RecordDate)-TO_DAYS(w2.RecordDATE)=1;

