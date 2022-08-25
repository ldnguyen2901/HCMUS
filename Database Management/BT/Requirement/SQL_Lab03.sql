
---cau1
SELECT * 
FROM 
(
	SELECT RowNum, Id, ProductName, SupplierId, UnitPrice, Package,
	IsDiscontinued, MAX(RowNum) OVER (ORDER BY (SELECT 1)) AS RowLast
	FROM(
		SELECT ROW_NUMBER() OVER (ORDER BY UnitPrice) AS RowNum,
				Id, ProductName, SupplierId, UnitPrice, Package,
				IsDiscontinued
		FROM Product
	) AS DerivedTable
) Report
WHERE Report.RowNum >= 0.2 * RowLast


---cau2
SELECT OrderId, Id, ProductName, UnitPrice, Package, Quantity, STR([Percent],5,2) + '%' AS [Percent]
FROM
(
	SELECT O.OrderId, P.Id, P.ProductName,P.UnitPrice,P.Package, O.Quantity,
	CAST(O.Quantity AS DECIMAL(5,2))*100/ (SUM(O.Quantity) OVER (PARTITION BY O.OrderId)) AS [Percent]
	FROM OrderItem AS O
	INNER JOIN Product AS P ON O.ProductId = P.Id
) Report
ORDER BY Report.OrderId

---cau3
IF EXISTS(SELECT * FROM INFORMATION_SCHEMA.TABLES
		  WHERE TABLE_NAME = N'Company')
BEGIN
	DROP TABLE Company
END



SELECT Id, CompanyName,
	   (CASE Country
			WHEN 'USA' THEN 'USA'
			WHEN 'UK' THEN 'UK'
			WHEN 'France' THEN 'France'
			WHEN 'Germany' THEN 'Germany'
			ELSE 'Other'
		END) AS Country INTO Company
FROM Supplier 


SELECT C.Id, C.CompanyName,
	   ISNULL(C.[USA],0) AS [USA],
	   ISNULL(C.[UK],0) AS [UK],
	   ISNULL(C.[France],0) AS [France],
	   ISNULL(C.[Germany],0) AS [Germany],
	   ISNULL(C.[Other],0) AS [Other]
	   

FROM
(
	SELECT * FROM Company
	PIVOT (COUNT(Country) FOR Country IN ([USA],[UK],[France],[Germany],[Other])) AS PivotedCompany
) C
ORDER BY C.Id

---cau4
SELECT O.OrderNumber,
	   OrderDate = CONVERT(VARCHAR(10),O.OrderDate, 103),
	   CustomerName = C.FirstName + SPACE(1) + C.LastName,
	   [Address] = 'Phone: ' + C.Phone + ', ' + 'City: ' + C.City + ' and Country: ' + C.Country,
	   TotalAmount = LTRIM(STR(CAST(O.TotalAmount AS DECIMAL(10)),10,0) + ' Euro')
FROM [Order] O
INNER JOIN Customer C ON O.CustomerId = C.Id
ORDER BY O.Id

---cau5

SELECT Id, ProductName, SupplierId, UnitPrice,
		Package = STUFF(Package, CHARINDEX('bags', Package), LEN('bags'), N'túi')
FROM Product
WHERE Package LIKE '%bags%'

---cau6
SELECT CustomerId, COUNT(OrderNumber) AS OrderCount INTO OCount
FROM [Order] 
GROUP BY CustomerId

SELECT*
FROM OCount

SELECT OC.CustomerId,
	   CustomerName = C.FirstName + SPACE(1) + C.LastName , 
	   OC.OrderCount,
	   [Rank] = DENSE_RANK() OVER (ORDER BY OrderCount),
	   [Group] = NTILE(3) OVER (ORDER BY OC.OrderCount DESC)
FROM OCount OC 
INNER JOIN Customer C ON OC.CustomerId = C.Id
ORDER BY OC.OrderCount DESC
