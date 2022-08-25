--yeu cau 1
select *
from Customer;

--yeu cau 2
select id, FirstName +' '+ LastName as FullName, City, Country
from Customer;

--yeu cau 3
select *
from Customer
where Country like '%Germany%' or Country like '%UK%'; 

--yeu cau 4
select *
from Customer
order by FirstName ASC, Country DESC;

--yeu cau 5.1
select *
from Customer
where id = 10 or id = 5;

--yeu cau 5.2.1
select *
from Customer
order by id
offset 0 rows
fetch first 10 rows only;
--yeu cau 5.2.1
SELECT TOP 10 *
from Customer;
--yeu cau 5.3
select *
from Customer
order by id
offset 4 rows
fetch next 6 rows only;

--yeu cau 6
select *
from Product
where UnitPrice between 15 and 20 and not SupplierId = 16
order by UnitPrice;