# Write your MySQL query statement below
with CTE as (select id, num, lag(id, 2) over(partition by num order by id) as prev_id from logs)
select distinct num as ConsecutiveNums from CTE where (id - 2) = prev_id;