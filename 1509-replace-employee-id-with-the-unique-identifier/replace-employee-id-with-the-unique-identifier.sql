# Write your MySQL query statement below
select em.unique_id , e.name from EmployeeUNI as em 
right join Employees as e on e.id = em.id