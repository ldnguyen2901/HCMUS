--exam1
if DB_ID('Northwind') is not null 
begin
select 'database does exit'
end
else
begin
select 'database does not exit'
end;

--exam2
select *
from Supplier;

--exam3
select id, 
		LEFT(ContactName,charindex(' ',ContactName)-1)as 'FirstName',
		SUBSTRING(ContactName, CHARINDEX(' ',ContactName)+1,100)as 'LastName',
		City, Country
from Supplier
order by FirstName ASC, City DESC;

--exam4
select distinct Country
from Supplier
select count(distinct Country)
from Supplier;

--exam5
SELECT *
FROM Supplier
WHERE Id = 3 OR Id = 5;

SELECT TOP 5 *
from Supplier;

SELECT *
FROM Supplier
ORDER BY Id
OFFSET 2 ROWS
FETCH NEXT 3 ROWS ONLY;

--exam6
select *
from Supplier
where Country in ('USA','UK') and not City = 'London' and Fax is not null;

--exam7
select*
from Product
where Package like '%boxes%' and UnitPrice between 10 and 20;