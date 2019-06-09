--
-- @lc app=leetcode id=178 lang=mysql
--
-- [178] Rank Scores
--
# Write your MySQL query statement below

select a.Score, (select count(distinct b.Score) from Scores b where b.Score>=a.Score) as Rank  from Scores a order by Rank ;

