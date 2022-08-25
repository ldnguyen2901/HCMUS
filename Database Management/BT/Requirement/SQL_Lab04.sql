--cau1
select OrderId, Quantity, ProductId,
        SUM (Quantity) over (partition by OrderId) as TotalQuantity,
        CAST (((1.0* Quantity)/(SUM(Quantity) over (partition by OrderId))*100)
                                          as decimal(6,2)) as PercentofQuantity
from OrderItem 

-- cau2
SELECT DATENAME(dw, OrderDate) AS [Day Name],*
FROM [Order]
WHERE DATENAME (dw, OrderDate)='Monday' or
	  DATENAME (dw, OrderDate)='Tuesday' or
	  DATENAME (dw, OrderDate)='Wednesday' or
	  DATENAME (dw, OrderDate)='Thursday' or
	  DATENAME (dw, OrderDate)='Friday' or
	  DATENAME (dw, OrderDate)='Saturday' or
	  DATENAME (dw, OrderDate)='Sunday' 

-- cau3
SELECT  OI.OrderID, OI.ProductId, P.ProductName, P.UnitPrice, OI.Quantity, 
	    coalesce(Fax,Phone) as ContactInfo, 
		case coalesce(Fax,Phone) when Fax then 'Fax' else 'Phone' end as ContactType
FROM OrderItem OI inner join Product P on OI.ProductId = P.Id,Supplier S
where P.SupplierId = S.Id
	 
-- cau4
DECLARE @sys_usr CHAR(30),@user_name CHAR(30);  
SET @sys_usr = SYSTEM_USER; 
set @user_name = USER_NAME();
SELECT DB_ID('Northwind') AS [Database ID],
	   object_id('Supplier') as [Table ID],
	   USER_ID(@user_name) as [User ID],
	   @sys_usr as [User_Name],
	   user_name(1) as [Else UserName]

 --cau5
select [TableName]=OBJECT_NAME(object_id),
        user_updates, user_seeks, user_scans, user_lookups
from sys.dm_db_index_usage_stats as SIUS
where database_id=DB_ID('Northwind') and OBJECT_NAME(object_id)='Order'

--cau6
with OrderCategory(Country, City, OrderNumber, alevel)
as
(
	select distinct Country,
					City = cast('' as nvarchar(255)),
					OrderNumber = cast('' as nvarchar(255)),
					alevel = 0
	from Supplier,[Order]

	union all

	select C.Country,
		   City = cast(C.City as nvarchar(255)),
		   OrderNumber = cast('' as nvarchar(255)),
	       alevel = OC.alevel + 1
	from OrderCategory OC inner join Customer C on OC.Country = C.Country
	where OC.alevel = 0

	union all

	select C.Country,
		   City = cast(C.City as nvarchar(255)),
		   OrderNumber = cast(O.OrderNumber as nvarchar(255)),
	       alevel = OC.alevel + 1
	from OrderCategory OC inner join Customer C on OC.Country = C.Country and OC.City = C.City inner join [Order] as O on C.Id= O.CustomerId

	where OC.alevel = 1
)
select [Quoc gia] = case when alevel = 0 then Country else '--' end,
	   [Thanh pho] = case when alevel = 1 then City else '----' end,
	   [Hoa don] = OrderNumber,
	   Cap = alevel
from OrderCategory
order by Country, City, OrderNumber, alevel

-- cau7
with SumQuantityByOrder as
(
    select OI.OrderId, SumQuantity=SUM(Quantity)
    from OrderItem as OI
    group by OrderId
),
CustomerByOrder as
(
    select O.*, SQBO.SumQuantity 
    from Customer as C inner join [Order] as O on C.Id=O.CustomerId
        inner join SumQuantityByOrder as SQBO on O.Id=SQBO.OrderId
    where C.Country='France'
)
select*
from CustomerByOrder
where SumQuantity>50