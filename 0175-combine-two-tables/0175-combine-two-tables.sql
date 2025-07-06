# Write your MySQL query statement below
select p.firstName, p.lastName, ad.city, ad.state
from person p 
left join address ad 
on p.personId = ad.personId;