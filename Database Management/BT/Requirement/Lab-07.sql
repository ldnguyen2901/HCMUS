---cau 1.1
CREATE TRIGGER [dbo].[Trigger_OrderDelete]
ON [dbo].[OrderItem]
FOR DELETE 
AS

DECLARE @DeletedOrderId INT
SELECT @DeletedOrderId = OrderId FROM deleted

ALTER TABLE [OrderItem] DROP CONSTRAINT FK_ORDERITE_REFERENCE_ORDER
 
DELETE FROM OrderItem WHERE OrderId = 26

---cau 1.2
CREATE TRIGGER [dbo].[Trigger_Order1Delete]
ON [dbo].[Order]
FOR DELETE 
AS

DECLARE @DeletedOrderId INT
SELECT @DeletedOrderId = CustomerId FROM deleted

IF(@DeletedOrderId = 1)
BEGIN	
	RAISERROR ('Order nay khong the xoa',
				16,
				1
			  );
	ROLLBACK TRANSACTION
END

EXEC sp_settriggerorder @triggername = 'Trigger_Order1Delete', @order ='First', @stmttype = 'DELETE';

DELETE FROM [Order] WHERE Id = 396

SELECT *
FROM [Order] where CustomerId = 1

--- cau 1.3
CREATE TRIGGER [dbo].[Trigger_SupplierUpdate]
ON [dbo].[Supplier]
FOR UPDATE
AS
DECLARE @UpdatePhone NVARCHAR(30)
IF UPDATE(Phone)
BEGIN
	SELECT @UpdatePhone = Phone FROM inserted
	IF @UpdatePhone IS NULL OR @UpdatePhone LIKE '%[^0-9]%'
	BEGIN
		RAISERROR ('Phone khong duoc NULL hay co chu',
					16,
					1
				  );
		ROLLBACK TRANSACTION
	END	
END

UPDATE Supplier SET Phone = NULL WHERE Id = 1

UPDATE Supplier SET Phone = ' ' WHERE Id = 1

UPDATE Supplier SET Phone = 'abcde' WHERE Id = 1

UPDATE Supplier SET Phone = '0909400733a' WHERE Id = 1

UPDATE Supplier SET Phone = '0909400733' WHERE Id = 1

SELECT*FROM Supplier

---cau 2
CREATE FUNCTION dbo.unf_ListCompanyByCountry (@CountryDescr NVARCHAR(MAX))
RETURNS NVARCHAR(MAX)
AS
BEGIN
	DECLARE @CompanyList NVARCHAR(MAX) = 'Companies in ' + @CountryDescr + ' are :';
	DECLARE @Id INT;
	DECLARE @CompanyName NVARCHAR(MAX);

	DECLARE CompanyCursor CURSOR READ_ONLY
	FOR
	SELECT Id, CompanyName
	FROM Supplier
	WHERE Country LIKE @CountryDescr

	OPEN CompanyCursor
	
	FETCH NEXT FROM CompanyCursor INTO @Id, @CompanyName

	WHILE @@FETCH_STATUS = 0
	BEGIN
		SET @CompanyList = @CompanyList + @CompanyName + '(ID:'+LTRIM(STR(@Id))+')' + ' ; ' ;
		FETCH NEXT FROM CompanyCursor INTO @Id, @CompanyName
	END

	CLOSE CompanyCursor
	DEALLOCATE CompanyCursor

	RETURN @CompanyList
END

SELECT dbo.unf_ListCompanyByCountry('USA')


drop function dbo.unf_ListCompanyByCountry

---cau 3
BEGIN TRY
	BEGIN TRANSACTION UpdateQuantityTrans

		SET NOCOUNT ON;

		DECLARE @NumOfUpdateRecords INT = 0;
		DECLARE @DFactor INT;
		SET @DFactor = 1;

		UPDATE OI SET Quantity = Quantity / @DFactor
		FROM OrderItem OI
		INNER JOIN [Order] O on OI.OrderId = O.Id
		INNER JOIN  Customer C on O.CustomerId = C.Id
		WHERE C.Country LIKE '%USA%'

		SET @NumOfUpdateRecords = @@ROWCOUNT
		PRINT 'Cap Nhat Thanh Cong ' + LTRIM(STR(@NumOfUpdateRecords)) + ' dong trong bang OrderItem';

	COMMIT TRANSACTION UpdateQuantityTrans
END TRY
BEGIN CATCH
	ROLLBACK TRAN UpdateQuantityTrans
	PRINT 'Cap Nhat That Bai. Xem Chi Tiet :';
	PRINT ERROR_MESSAGE();
END CATCH


---cau 4
BEGIN TRY
BEGIN TRANSACTION CompareTwoCountryTrans

	SET NOCOUNT ON;
	DECLARE @Country1 NVARCHAR(40)
	DECLARE @Country2 NVARCHAR(40)
	
	SET @Country1 = 'USA'
	SET @Country2 = 'UK'

	CREATE TABLE #CountryInfo1
	(
		SupplierId INT,
		Country NVARCHAR(40)
	)

	DECLARE @CountryInfo2 TABLE
	(
		SupplierId INT,
		Country NVARCHAR(40)
	)

	INSERT INTO #CountryInfo1
	SELECT P.SupplierId, S.Country
	FROM Product P
	INNER JOIN Supplier S ON P.SupplierId = S.Id
	WHERE S.Country = @Country1

	INSERT INTO @CountryInfo2
	SELECT P.SupplierId, S.Country
	FROM Product P
	INNER JOIN Supplier S ON P.SupplierId = S.Id
	WHERE S.Country = @Country2

	DECLARE @NumProduct1 INT
	SET @NumProduct1 = (SELECT COUNT(SupplierId) FROM #CountryInfo1);
	DECLARE @NumProduct2 INT
	SET @NumProduct2 = (SELECT COUNT(SupplierId) FROM @CountryInfo2);

	PRINT 
	CASE
		WHEN @NumProduct1 = @NumProduct2
			THEN 'So Luong San Pham Cua ' + @Country1 + ' = ' + @Country2
		WHEN @NumProduct1 > @NumProduct2
			THEN 'So Luong San Pham Cua ' + @Country1 + ' nhieu hon ' + @Country2
		ELSE 'So Luong San Pham Cua ' + @Country1 + ' it hon ' + @Country2
	END

	PRINT 'So Luong San Pham Cua ' + @Country1+ ' : ' + LTRIM(STR(@NumProduct1))
	PRINT 'So Luong San Pham Cua ' + @Country2+ ' : ' + LTRIM(STR(@NumProduct2))

	DROP TABLE #CountryInfo1

	COMMIT TRANSACTION CompareTwoCountryTrans
END TRY
BEGIN CATCH
	ROLLBACK TRAN CompareTwoCountryTrans
	PRINT 'Co Loi Xay Ra. Xem Chi Tiet :';
	PRINT ERROR_MESSAGE();
END CATCH



SELECT P.SupplierId, S.Country
FROM Product P
INNER JOIN Supplier S ON P.SupplierId = S.Id
WHERE S.Country  = 'UK'