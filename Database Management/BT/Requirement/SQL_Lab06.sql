--cau 1
CREATE FUNCTION ufn_NumOfTotalAmountByCustID(@CustomerID INT=0)
RETURNS float
AS
BEGIN
    DECLARE @TotalAmount float

    SELECT @TotalAmount = sum(TotalAmount)
    FROM [Order]
    where CustomerId = @CustomerID

    RETURN @TotalAmount
END

SELECT *,dbo.ufn_NumOfTotalAmountByCustID(Id) as 'Total Amount'
FROM Customer

-- cau 3
CREATE FUNCTION ufn_OrderListByMonthFilter(@MonthFilter NVARCHAR(MAX))
RETURNS TABLE
AS
RETURN(
	SELECT *
    FROM [Order]
    WHERE CHARINDEX(LTRIM(RTRIM(lower(datename(M,OrderDate)))), lower(@MonthFilter))>0
	)


CREATE FUNCTION ufn_OrderListByMonthFilter2 (@MonthFilter NVARCHAR (MAX))
RETURNS @ResultTable TABLE (Id INT, OrderDate NVARCHAR (MAX), OrderNumber NVARCHAR (MAX),
                             CustomerId int, TotalAmount float)
AS
BEGIN
   SET @MonthFilter = LOWER (@MonthFilter);
   INSERT INTO @ResultTable
   SELECT Id, OrderDate, OrderNumber,CustomerId,TotalAmount
   FROM [Order]
   WHERE CHARINDEX(LTRIM(RTRIM(LOWER(datename(M,OrderDate)))), @MonthFilter)>0
   RETURN
END

set statistics time on
select *from ufn_OrderListByMonthFilter('June;July;August;September')
select *from ufn_OrderListByMonthFilter2('June;July;August;September')
set statistics time off

-- in-line statement (10 ms) nhanh hon multi-statement (285 ms) khoang 250ms (co sai so)

-- cau 2
CREATE FUNCTION ufn_ProductListByUnitPrice(@pricebegin float, @priceend float)
RETURNS TABLE
AS
RETURN(
   SELECT*
    FROM Product
   WHERE @pricebegin <= UnitPrice and UnitPrice <= @priceend
   
   )

SELECT*FROM ufn_ProductlistByUnitPrice(16,20)
order by UnitPrice

-- cau 4
--exists(select * from [Order] where Id = @OrderId) and
--CREATE FUNCTION ufn_CheckOrderLess5Product (@OrderIdL INT)
--RETURNS bit
--AS
--    BEGIN
--        DECLARE @Existence bit;
--        IF((select OrderId,count(OrderId) 
--		from [OrderItem]
--		where OrderId = @OrderIdL
--		group by OrderId)<5)
        
--		    SET @Existence = 1;
--        ELSE
--            SET @Existence = 0;
--        RETURN @Existence;
--    END
--GO
--ALTER TABLE [Order] 
--ADD CONSTRAINT CheckOrderList
--    CHECK (dbo.ufn_CheckOrderLess5Product(Id) = 1);

--drop function ufn_CheckOrderLess5Product;

select OrderId,count(OrderId) As 'TotalByProduct'
from [OrderItem]
--where OrderId = 2
group by OrderId
having count(OrderId)>5

select *
from [Order]


select *
from [OrderItem]

insert into [OrderItem] values(600,5,17,15)

--cau 4
CREATE FUNCTION NumOfPro(@OrderId INT)
RETURNS BIT
AS
	BEGIN
		DECLARE @check BIT;
		IF ((SELECT COUNT(*) FROM OrderItem WHERE OrderId = @OrderId)<=5)
			SET @check = 1;
		ELSE 
			SET @check = 0;
		RETURN @check;
	END
GO

ALTER TABLE OrderItem
ADD CONSTRAINT CheckNumOfPro1
	CHECK (dbo.NumOfPro(26) =1) ;

INSERT INTO OrderItem VALUES(26, 30, 4.5, 15);
