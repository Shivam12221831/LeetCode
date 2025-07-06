# Write your MySQL query statement below

-- select max(salary) from employee group by departmentId;
-- select * from employee where salary in (select max(salary) from employee group by departmentId)

select d.name as Department, e.name as Employee, e.salary as Salary
from (select * from employee where (departmentId, salary) in (select departmentId, max(salary) from employee group by departmentId)) as e
join department d
on e.departmentId = d.id;

