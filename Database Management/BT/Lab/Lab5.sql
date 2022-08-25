--create view uvw_DetailCustomerInOrder_A
--as
--	select O.OrderDate, O.OrderNumber, O.CustomerId, C.FirstName + SPACE(1) + C.LastName as [FullName],
--		   C.City, C.Country, O.TotalAmount
--	from [Order] O inner join Customer C on O.CustomerId = C.Id
--go

--select *
--from uvw_DetailCustomerInOrder_A
--where Country = 'France'

--update uvw_DetailCustomerInOrder_A set TotalAmount = 10
--where Country = 'France' and CustomerId = 85

--select *
--from uvw_DetailCustomerInOrder_A
--where Country = 'France' and CustomerId = 85

--CREATE TRIGGER uVw_DetailCustomerInOrder_A_Trigger_OnInsertOrUpdateOrDelete
--ON uvw_DetailCustomerInorder_A
--INSTEAD OF INSERT, UPDATE, DELETE
--AS
--BEGIN
--   RAISERROR('You are not allowed to insert, update, or delete through this view', 16,1)
--END

--CREATE VIEW uvw_DetailCustomerInOrder_B
--AS
--    SELECT O.OrderDate, O.OrderNumber, O.customerId, C.FirstName + SPACE (1) + C.LastName AS [FullName],
--            C.City, C.Country, O.TotalAmount
--    FROM [Order] O
--    INNER JOIN Customer C ON O.CustomerId = C.Id
--    UNION
--    SELECT NULL,NULL, NULL, NULL, NULL, NULL, NULL 
--	WHERE 1 = 0
--GO

--update uvw_DetailCustomerInOrder_B set TotalAmount = 10
--where Country = 'France' and CustomerId = 85

--CREATE VIEW uvw_DetailCustomerInOrder_C
--AS
--    WITH TotalAmountFromOrderItem (OrderId, TotalAmount)
--    AS
--	(
--        SELECT OrderId, SUM(UnitPrice*Quantity) AS TotalAmount
--        FROM OrderItem
--        GROUP BY OrderId
--	)
--    SELECT O.OrderDate, O.OrderNumber, O.CustomerId, C. FirstName + SPACE (1) + C.LastName AS [FullName],
--            C.City, C.Country, O.TotalAmount
--    FROM [Order]o
--    INNER JOIN Customer C ON O.CustomerId = C.Id
--    INNER JOIN TotalAmountFromorderItem T ON O.Id=T.OrderId
--    WHERE O. TotalAmount=T. TotalAmount
--    WITH CHECK OPTION;
--GO
--UPDATE uvw_DetailCustomerInorder_C SET TotalAmount=10
--WHERE Country='Germany' AND CustomerId=79
                                                  
exec sp_helptext uvw_DetailCustomerInOrder_A
print object_definition(object_id('uvw_DetailCustomerInOrder_A'));

CREATE VIEW uvw_DetailCustomerInOrder_D with encryption
AS
    WITH TotalAmountFromOrderItem (OrderId, TotalAmount)
    AS
	(
        SELECT OrderId, SUM(UnitPrice*Quantity) AS TotalAmount
        FROM OrderItem
        GROUP BY OrderId
	)
    SELECT O.OrderDate, O.OrderNumber, O.CustomerId, C. FirstName + SPACE (1) + C.LastName AS [FullName],
            C.City, C.Country, O.TotalAmount
    FROM [Order]o
    INNER JOIN Customer C ON O.CustomerId = C.Id
    INNER JOIN TotalAmountFromorderItem T ON O.Id=T.OrderId
    WHERE O. TotalAmount=T. TotalAmount
    WITH CHECK OPTION;
GO

print object_definition(object_id('uvw_DetailCustomerInOrder_D'));

SET STATISTICS IO, TIME ON
GO
SELECT*FROM uvw_DetailCustomerInOrder_D
WHERE Country IN ('Germany', 'France', 'Mexico')
GO
WITH TotalAmountFromOrderItem (OrderId, TotalAmount)
AS
(
    SELECT OrderId, SUM(UnitPrice*Quantity) AS TotalAmount
    FROM OrderItem
    GROUP BY OrderId
)
SELECT O.OrderDate, O.OrderNumber, O.CustomerId, C.FirstName + SPACE (1)+C. LastName AS [Ful1Name],
        C.city, C.Country, O.TotalAmount
FROM [Order] O
INNER JOIN Customer C ON O.CustomerId = C.Id
INNER JOIN TotalAmountFromOrderItem T ON O.Id = T.OrderId
WHERE O. TotalAmount = T.TotalAmount AND C.Country IN ('Germany', 'France', 'Mexico')
GO
SET STATISTICS IO, TIME OFF

CREATE SCHEMA MySchema
    CREATE TABLE DetailCustomer (Id int, FullName nvarchar (40), City nvarchar (40), Country nvarchar (40))
    CREATE TABLE DetailSupplier (Id int, CompanyName nvarchar (40), City nvarchar (40), Country nvarchar(40), ContactInfo nvarchar (40))
    CREATE TABLE Detailorder (Id int, OrderDate datetime, OrderNumber nvarchar (40), CustomerId int, TotalAmount decimal(12,2));
GO

INSERT INTO MySchema.DetailCustomer
SELECT Id, FirstName+SPACE (1)+LastName AS [FullName], City, Country
FROM Customer

INSERT INTO MySchema.DetailSupplier
SELECT Id, CompanyName, City, Country, ISNULL (Fax, Phone) AS [ContactInfo]
FROM Supplier

INSERT INTO Myschema.Detailorder
SELECT Id, OrderDate, OrderNumber, CustomerId, TotalAmount
FROM [Order]

CREATE VIEW uvw_Order_Customer WITH SCHEMABINDING AS
    SELECT O.OrderDate, O.OrderNumber, O.CustomerId, C.FullName, C.City, C.Country, O. TotalAmount
    FROM MySchema.Detailorder O
    INNER JOIN MySchema.DetailCustomer C ON O.CustomerId = C.Id
GO
CREATE VIEW uvw_Supplier AS
    SELECT*
    FROM MySchema.DetailSupplier S
    WHERE Country='USA'
GO

ALTER TABLE MySchema.DetailOrder ALTER COLUMN TotalAmount float
ALTER TABLE MySchema.Detailsupplier ALTER COLUMN Country nvarchar (20)

select *
from MySchema.Detailorder

select *
from uvw_Order_Customer
