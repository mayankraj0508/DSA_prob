# Write your MySQL query statement below
select u.unique_id ,name from Employees
as e

left  join  EmployeeUNI u  on
e.id  = u.id