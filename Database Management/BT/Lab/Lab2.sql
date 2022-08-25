select*
from(
SELECT RowNum, Id, OrderId, ProductId, Quantity, MAX (RowNum) OVER (ORDER BY (SELECT 0)) AS RowLast
FROM (
	  SELECT ROW_NUMBER() OVER (ORDER BY Quantity) AS RowNum,
			 Id, OrderId, ProductId, Quantity
	  FROM OrderItem
	  ) as DerivedTable
) report
where report.RowNum >= 0.1*RowLast;

select OrderNumber, OrderDate, CustomerId, TotalAmount,
	   STR([Percent]*100,5,2)+'%' as [Percent]
from (
select OrderNumber, OrderDate, CustomerId, TotalAmount, 
	   TotalAmount/(sum(TotalAmount) over (partition by CustomerId)) as [Percent]
from [Order]
)report
order by CustomerId, OrderDate

select report.*
from(
select P.Id, P.ProductName,O.Quantity,
	   ROW_NUMBER()over(partition by O.ProductId order by O.Quantity DESC) as RowNum
from OrderItem O inner join Product P on O.ProductId = P.Id
)report
where RowNum<=3
order by report.Id

if exists (select * from INFORMATION_SCHEMA.TABLES
		   where TABLE_NAME = N'OrderByMonth')
begin 
	drop table OrderByMonth
end

select CustomerId,MONTH(OrderDate) as MonthOrder, count(OrderNumber) as OrderCount into OrderByMonth
from [Order]
group by CustomerId, MONTH(OrderDate)
--SELECT * FROM OrderByMonth

 SELECT CustomerByMonth. CustomerId, C.FirstName + ' ' + C. LastName AS [CustomerName],
ISNULL (CustomerByMonth. [1],0) AS [Order in T1],
ISNULL(CustomerByMonth. [2], 0) AS [Order in T2],
ISNULL(CustomerByMonth. [3],0) AS [Order in T3],
ISNULL(CustomerByMonth. [4],0) AS [Order in T4],
ISNULL(CustomerByMonth. [5], 0) AS [Order in T5],
ISNULL (CustomerByMonth. [6],0) AS [Order in T6],
ISNULL(CustomerByMonth. [7],0) AS [Order in T7],
ISNULL(CustomerByMonth. [8],0) AS [Order in T8],
ISNULL(CustomerByMonth. [9],0) AS [Order in T9],
ISNULL (CustomerByMonth. [10], 0) AS [Order in T10],
ISNULL(CustomerByMonth. [11],0) AS [Order in T11],
ISNULL (CustomerByMonth. [12], 0) AS [Order in T12]
FROM
(
SELECT * FROM OrderByMonth
PIVOT (SUM(OrderCount) FOR MonthOrder IN ([1], [2], [3], [4], [5], [6], [7], [8], [9], [10], [11], [12])) AS PivotedOrder
) CustomerByMonth
INNER JOIN Customer C ON CustomerByMonth. CustomerId = C. Id

 SELECT Id, OrderNumber, OrderDate,
(CASE MONTH (OrderDate)
WHEN 1 THEN 'Month 1'
WHEN 2 THEN 'Month 2'
WHEN 3 THEN 'Month 3'
WHEN 4 THEN 'Month 4'
WHEN 5 THEN 'Month 5'
WHEN 6 THEN 'Month 6'
WHEN 7 THEN 'Month 7'
WHEN 8 THEN 'Month 8'
WHEN 9 THEN 'Month 9'
WHEN 10 THEN 'Month 10'
WHEN 11 THEN 'Month 11'
ELSE 'Month 12'
END
) AS OrderMonth
FROM [order] 

SELECT Id, OrderNumber, OrderDate,
(CASE
WHEN MONTH (OrderDate) < 4 THEN 'Period 1'
WHEN MONTH (OrderDate) < 7 THEN 'Period 2'
WHEN MONTH (OrderDate) < 10 THEN 'Period 3'
ELSE 'Period 4'
END
) AS OrderPeriod
FROM [order]

select O.Id, O.OrderNumber,
	   OrderDate = convert(varchar(10),O.OrderDate,103),
	   CustomerName = 'Customer' + Space(1) + ':' + C.FirstName + SPACE(1) + C.LastName,
	   Amount = LTRIM(STR(cast(O.TotalAmount as decimal(10,1)),10,1)+'$')
from [Order] O inner join Customer C on O.CustomerId = C.Id

SELECT Id, ProductName, SupplierId, UnitPrice,
Package = STUFF (Package, CHARINDEX('bottles', Package), LEN('bottles'), 'chai')
FROM Product
WHERE Package LIKE '%bottles%'

SELECT Id, ProductName, UnitPrice,
[Rank] = DENSE_RANK () OVER (ORDER BY UnitPrice)
FROM Product

SELECT CustomerID = Report.Id,
	   CustomerName = Report.FirstName + SPACE (1) + Report.LastName,
	   OverallAmount = Report. OverallAmount,
	   [Group] = NTILE (3) OVER (ORDER BY Report.OverallAmount DESC)
FROM
(
SELECT C.Id, C.FirstName, C. LastName, [OverallAmount] = SUM (ISNULL(TotalAmount,0))
FROM Customer C
LEFT JOIN [Order] O ON C.Id = O.CustomerId
GROUP BY C.Id, C.FirstName, C.LastName
) Report