# Write your MySQL query statement below

-- with CTE as (select first_value(id) over(partition by email order by id) as unique_email_ids from person)
-- delete from person
-- where id not in (select * from CTE);


with CTE as ( select id, row_number() over(partition by email order by id) as rn from person )
delete from person where id in (select id from CTE where rn > 1);
