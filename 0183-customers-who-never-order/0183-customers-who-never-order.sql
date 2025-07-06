# Write your MySQL query statement below

select name as Customers
from customers where (id, name) not in (select c.id, c.name from customers c join orders o on c.id = o.customerId );