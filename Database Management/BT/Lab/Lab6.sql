CREATE FUNCTION ufn_NumoforderByCustID(@CustomerID INT=0)
RETURNS int
AS
BEGIN
    DECLARE @Totalorders INT

    SELECT @Totalorders = COUNT(*)
    FROM [Order]
    where CustomerId = @CustomerID

    RETURN @Totalorders
END

select *, dbo.ufn_NumoforderByCustID(Id) AS 'Number of Orders'
FROM Customer

--order way

select C.*,count (*) AS 'Number of Orders'
from [Order] O , Customer C  
where O.CustomerId = C.Id
group by C.FirstName,C.Id,C.LastName,C.City,C.Country,C.Phone

---------------------------------------------------------------------

CREATE FUNCTION ufn_ProductListByDesc (@Descr NVARCHAR(20))
RETURNS TABLE
AS
RETURN(
   SELECT*
    FROM Product
   WHERE LOWER (Package) LIKE '%'+LTRIM(RTRIM(LOWER(@Descr)))+'%'
   )

SELECT*FROM dbo.ufn_ProductlistByDesc('bottles')

CREATE FUNCTION ufn_CustomerListByCountryFilter (@CountryFilter NVARCHAR (MAX))
RETURNS @ResultTable TABLE (Id INT, FirstName NVARCHAR (MAX), LastName NVARCHAR (MAX),
                             Country NVARCHAR (MAX), Phone NVARCHAR (MAX))
AS
BEGIN
   SET @CountryFilter = LOWER (@CountryFilter);
   INSERT INTO @ResultTable
   SELECT Id, FirstName, LastName, Country, Phone
   FROM Customer
   WHERE CHARINDEX(LTRIM(RTRIM(LOWER(Country))), @CountryFilter)>0
   RETURN
END

CREATE FUNCTION ufn_CustomerListByCountryFilter2(@CountryFilter NVARCHAR(MAX))
RETURNS TABLE
AS
RETURN(
    SELECT *
    FROM Customer
    WHERE CHARINDEX(LTRIM(RTRIM(LOWER(Country))), LOWER(@CountryFilter))>0
	)

SELECT*FROM ufn_CustomerListByCountryFilter2('Germany, Sweden, USA, UK');

----------------------------------------------------------------------------------

CREATE FUNCTION ufn_CheckSupplierExistence (@SupplerId INT)
RETURNS BIT
AS
    BEGIN
        DECLARE @Existence BIT;
        IF(EXISTS(SELECT*FROM Supplier WHERE Id = @SupplerId))
            SET @Existence = 1;
        ELSE
            SET @Existence = 0;
        RETURN @Existence;
    END
GO
ALTER TABLE Product
ADD CONSTRAINT CheckProductExistence
    CHECK (dbo.ufn_CheckSupplierExistence(SupplierId)=1);

select *
from Product
order by SupplierId 

INSERT INTO Product VALUES('New Product 4', 31, 10, 'kgs',0);

drop function ufn_CheckSupplierExistence;

select *
from Product