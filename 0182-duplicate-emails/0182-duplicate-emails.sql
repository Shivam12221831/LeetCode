# Write your MySQL query statement below

with CTE as (select id, email, row_number() over(partition by email order by id) as rn from person)
select distinct email as Email from CTE where rn > 1;