SELECT OrderNumber, OrderDate,
        CustomerId, TotalAmount,
        SUM(TotalAmount) OVER (PARTITION BY CustomerId) AS TotalAmountByCustomer,
       CAST((TotalAmount/(SUM(TotalAmount) OVER (PARTITION BY CustomerId)) * 100)
                                                 AS DECIMAL (6,2)) AS PercentByCustomer
FROM [Order]
ORDER BY CustomerId, OrderNumber


SELECT DATENAME(dw, OrderDate) AS [Day Name],
       DATENAME (MONTH, OrderDate) AS [Month Name],*
FROM [Order]
WHERE DATENAME (dw, OrderDate)='Sunday' AND DATENAME (MONTH, OrderDate) = 'August'

SELECT CompanyName, ContactName, COALESCE (Fax, Phone) AS ContactInfo,
        CASE COALESCE (Fax, Phone) WHEN Fax THEN 'Fax' ELSE 'Phone' END AS ContactType
FROM Supplier

with SupplierCategory(Country, City, CompanyName, alevel)
as(
	select distinct Country,
					City = cast('' as nvarchar(255)),
					CompanyName = cast('' as nvarchar(255)),
					alevel = 0
	from Supplier

	union all

	select S.Country,
		   City = cast(S.City as nvarchar(255)),
		   CompanyName = cast('' as nvarchar(255)),
		   alevel = SC.alevel + 1
	from SupplierCategory SC inner join Supplier S on SC.Country = S.Country
	where SC.alevel = 0

	union all

	select S.Country,
		   City = cast(S.City as nvarchar(255)),
		   CompanyName = cast(O.TotalAmount as nvarchar(255)),
   		   alevel = SC.alevel + 1
	from SupplierCategory SC inner join Supplier S on SC.Country = S.Country and SC.City = S.City,[Order] O
	where SC.alevel = 1
)
SELECT [Quoc Gia] = CASE WHEN alevel = 0 THEN Country ELSE '--' END,
       [Thanh Pho]= CASE WHEN alevel = 1 THEN City ELSE '----' END,
       [Nha Cung Cap] = CompanyName,
       Cap=alevel
FROM SupplierCategory
ORDER BY Country, City, CompanyName, alevel


WITH AvgBySupplier AS
(
    SELECT SupplierId, AVGUnitPrice=AVG(UnitPrice)
    FROM Product
    GROUP BY SupplierId
    HAVING SupplierId=3
),
ProductByCountry AS
(
    SELECT P.*
    FROM Product P
    INNER JOIN Supplier S ON P.SupplierId=S.Id
    WHERE S.Country='Germany'
)
SELECT*
FROM ProductByCountry
WHERE UnitPrice>ALL (SELECT AVGUnitPrice FROM AvgBySupplier)