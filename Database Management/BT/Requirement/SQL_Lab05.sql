--cau1
create view uvw_DetailProductInOrder 
as
	select OI.OrderId, O.OrderNumber, O.OrderDate, OI.ProductId,
		   P.ProductName + SPACE(1) + P.Package as [ProductInfo],
		   OI.UnitPrice, OI.Quantity
	from OrderItem OI
		 inner join [Order] O on OI.OrderId = O.Id
		 inner join Product P on OI.ProductId = P.Id
go

create view uvw_AllProductInOrde
as
select OI.OrderId, O.OrderNumber,O.OrderDate,
   stuff((
		  select ',' + cast(ProductId as nvarchar(max))
		  from [OrderItem] OII
		  where OI.OrderId = OII.OrderId
		  FOR XML PATH ('')
		  ),1,1,'') as [ProductList],
  		  sum(Quantity*UnitPrice) as TotalAmount
from [OrderItem] OI inner join [Order] O on OI.OrderId = O.Id
group by OrderId,O.OrderNumber,O.OrderDate
go

--cau2
select *
from uvw_DetailProductInOrder
where MONTH(OrderDate)=7

--cau3
select *
from uvw_AllProductInOrde as viewOutside
where (select LEN(ProductList) - LEN(REPLACE(ProductList, ',', ''))
	   from uvw_AllProductInOrde as viewInside
	   where viewInside.OrderId = viewOutside.OrderId) >= 2

-- cau4
-- 2 view tren chua readonly
-- lay bang uvw_DetailProductInOrder lam mau readonly 
-- (tuong tu voi bang uvw_AllProductInOrde)

-- cau4.1
CREATE TRIGGER uvw_DetailProductInOrder_trigger
on uvw_DetailProductInOrder
instead of insert, update, delete
as
begin
	raiserror('You are not allowed to insert, update, delete through this view',16,1)
end
-- cau4.2
create view uvw_DetailProductInOrder_B
as
	select OI.OrderId, O.OrderNumber, O.OrderDate, OI.ProductId,
		   P.ProductName + SPACE(1) + P.Package as [ProductInfo],
		   OI.UnitPrice, OI.Quantity
	from OrderItem OI
		 inner join [Order] O on OI.OrderId = O.Id
		 inner join Product P on OI.ProductId = P.Id
	union
	select null,null,null,null,null,null,null where 1 = 0;
go
-- cau4.3
create view uvw_DetailProductInOrder_C
as
	select OI.OrderId, O.OrderNumber, O.OrderDate, OI.ProductId,
		   P.ProductName + SPACE(1) + P.Package as [ProductInfo],
		   OI.UnitPrice, OI.Quantity
	from OrderItem OI
		 inner join [Order] O on OI.OrderId = O.Id
		 inner join Product P on OI.ProductId = P.Id
WITH CHECK OPTION;
go

--cau5
set statistics io, time on
go

select *
from uvw_DetailProductInOrder

select *
from uvw_AllProductInOrde

set statistics io, time off
go