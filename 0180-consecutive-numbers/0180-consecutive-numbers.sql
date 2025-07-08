# Write your MySQL query statement below
with CTE as (select id, num, lag(num, 1) over w as prev1, lag(num, 2) over w as prev2 from logs
window w as (order by id))
select distinct num as ConsecutiveNums from CTE where num = prev1 and num = prev2;