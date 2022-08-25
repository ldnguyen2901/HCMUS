---cau 1
SELECT Sup.Id,Sup.CompanyName,
	   Sup.ContactName,Sup.City,
	   Sup.Country,Sup.Phone,
	   MAX(P.UnitPrice) AS MaxPrice,
	   MIN(P.UnitPrice) AS MinPrice
FROM Supplier AS Sup
INNER JOIN [Product] AS P ON Sup.Id = P.SupplierId
GROUP BY Sup.Id,Sup.CompanyName,
		 Sup.ContactName,Sup.City,
		 Sup.Country,Sup.Phone
ORDER BY Sup.Id 


---cau 2
SELECT Sup.Id,Sup.CompanyName,
	   Sup.ContactName,Sup.City,
	   Sup.Country,Sup.Phone,
	   MAX(P.UnitPrice) AS MaxPrice,
	   MIN(P.UnitPrice) AS MinPrice
FROM Supplier AS Sup
INNER JOIN [Product] AS P ON Sup.Id = P.SupplierId
GROUP BY Sup.Id,Sup.CompanyName,
		 Sup.ContactName,Sup.City,
		 Sup.Country,Sup.Phone
HAVING (Max(P.UnitPrice)-MIN(P.UnitPrice)) <= 30
ORDER BY Sup.Id 


---cau 3
SELECT Ord.Id, Ord.OrderNumber, Ord.OrderDate,
	   SUM(OrdI.UnitPrice*OrdI.Quantity) AS Total,
	   'VIP' AS [Description]
FROM [Order] AS Ord
INNER JOIN [OrderItem] AS OrdI ON Ord.Id = OrdI.OrderId
GROUP BY Ord.Id, Ord.OrderNumber, Ord.OrderDate 
HAVING SUM(OrdI.UnitPrice*OrdI.Quantity) > 1500
UNION
SELECT Ord.Id, Ord.OrderNumber, Ord.OrderDate,
	   SUM(OrdI.UnitPrice*OrdI.Quantity) AS Total,
	   'Normal' AS [Description]
FROM [Order] AS Ord
INNER JOIN [OrderItem] AS OrdI ON Ord.Id = OrdI.OrderId
GROUP BY Ord.Id, Ord.OrderNumber, Ord.OrderDate 
HAVING SUM(OrdI.UnitPrice*OrdI.Quantity) < 1500
ORDER BY Ord.Id 


---cau 4
SELECT Id, OrderNumber, OrderDate
FROM [Order] 
WHERE MONTH(OrderDate) = 7
EXCEPT
SELECT Ord.Id, Ord.OrderNumber, Ord.OrderDate
FROM [Order] AS Ord
INNER JOIN [Customer] AS C ON Ord.CustomerId = C.Id
WHERE Country ='France';

---cau 5
SELECT Id, OrderNumber, OrderDate, TotalAmount
FROM [Order]
WHERE TotalAmount IN (SELECT TOP 5 TotalAmount
					  FROM [Order]
					  GROUP BY TotalAmount
					  ORDER BY COUNT(Id) DESC)

