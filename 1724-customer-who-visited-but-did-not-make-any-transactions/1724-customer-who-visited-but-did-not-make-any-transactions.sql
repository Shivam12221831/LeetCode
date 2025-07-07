# Write your MySQL query statement below

with CTE as (select v.*, t.transaction_id
from visits v
left join transactions t
on v.visit_id = t.visit_id)

select customer_id, count(*) as count_no_trans from CTE where transaction_id is null group by customer_id order by count_no_trans desc;