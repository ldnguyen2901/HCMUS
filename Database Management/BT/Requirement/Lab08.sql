use Northwind;

-- Câu 1:
-- Viết một stored procedure với Input là một mã khách hàng CustomerId và Output là 
-- một hóa đơn OrderId của khách hàng đó có Total Amount là nhỏ nhất và một hóa đơn OrderId 
-- của khách hàng đó có Total Amount là lớn nhất 

create procedure usp_GetOrderId_CustomerID_MaxAndMinTotalQuantity
	@CustomerId int,
	@MaxOrderId int output,
	@MaxTotalAmount decimal(12,2) output,
	@MinOrderId int output,
	@MinTotalAmount decimal(12,2) output
as
begin
	with OrderInfo(Id, CustomerId, TotalAmount)
	as
	(
		select Id, CustomerId, TotalAmount
		from [Order]
		where CustomerId = @CustomerId
	)
	select @MaxOrderId = (select top 1 Id from OrderInfo Order by TotalAmount DESC),
			@MaxTotalAmount = MAX(Totalamount),
			@MinOrderId = (select top 1 Id from OrderInfo Order by TotalAmount ASC),
			@MinTotalAmount = MIN(TotalAmount)
	from OrderInfo
end

declare @CustomerId2 int
declare @MaxOrderId2 int
declare @MaxTotalAmount2 decimal (12,2)
declare @MinOrderId2 int
declare @MintotalAmount2 decimal(12,2)
SET @CustomerId2 = 21
exec usp_GetOrderId_CustomerID_MaxAndMinTotalQuantity @CustomerId2,
	@MaxOrderId2 output, @MaxTotalAmount2 output, @MinOrderId2 output, @MintotalAmount2 output
select @CustomerId2 as CustomerID,
	@MaxOrderId2 as MaxOrderID, @MinOrderId2 as MinOrderId,
	@MaxTotalAmount2 as Maxtotalamount, @MintotalAmount2 as Mintotalamount


-- Câu 2: Viết một stored procedure để thêm vào một Customer với Input là FirstName,
-- LastName, City, Country, và Phone. Lưu ý nếu các input mà rỗng hoặc Input đó đã có
-- trong bảng thì báo lỗi tương ứng và ROLL BACK lại.

create procedure usp_InsertNewCustomer
	@CustomerId int,
	@FirstName nvarchar(50),
	@Lastname nvarchar(50),
	@City nvarchar(50),
	@Country nvarchar(30),
	@Phone nvarchar(30)
as
begin
	if(exists(select * from Customer where FirstName = @Firstname and Lastname = @Lastname and City = @City and Country = @Country and Phone = @Phone))
	begin
		print 'customer already exist'
		return -1
	end
	if(len(@FirstName) = 0 or len(@Lastname) = 0 or len(@City)=0 or len(@Country)=0 or len(@Phone)=0)
	begin
		print 'Customer description can not be blank'
		return -1
	end

	begin try
		begin transaction
			set IDENTITY_INSERT Customer on
			insert into [dbo].[Customer]([Id],[FirstName],[LastName],[City],[Country],[Phone])
			values (@CustomerId, @FirstName, @Lastname, @City, @Country, @Phone)
			set IDENTITY_INSERT Customer off
			print 'Insert successful'
		commit transaction
	end try
	
	begin catch
		if @@TRANCOUNT > 0 rollback transaction
		declare @ERR nvarchar(MAX)
		set @ERR = ERROR_MESSAGE()
		print 'An error occurred after insert data to the Customer table: '
		raiserror(@ERR, 16,1)
		return -1
	end catch
end

declare @StateInsert1 int
exec @StateInsert1 = usp_InsertNewCustomer 92, 'Paul', 'Henriot', 'Reims', 'France', '26.47.15.10'
print @StateInsert1


declare @StateInsert2 int
exec @StateInsert2 = usp_InsertNewCustomer 92, 'Bob', 'Nixon', 'Portland', 'USA', '(071) 34 52 64 28'
print @StateInsert2

-- Câu 3: Viết Store Procedure cập nhật lại UnitPrice của sản phẩm trong bảng OrderItem. Khi cập
-- nhật lại UnitPrice này thì cũng phải cập nhật lại Total Amount trong bảng Order tương
-- ứng với Total Amount = SUM (UnitPrice *Quantity)

create procedure usp_UpdatePriceOrderItem
	@OrderItemId int,
	@UnitPrice decimal(12,2)
as
begin
	if(not exists(select * from OrderItem where Id = @OrderItemId))
	begin
		print 'Order Item does not exist'
		return -1
	end

	declare @OrderId int
	declare @TotalAmount decimal(12,2)

	set @OrderId =(select OrderId from OrderItem where Id = @OrderItemId)
	begin try
		begin transaction
			update OrderItem set UnitPrice = @UnitPrice where Id = @OrderItemId

			set @TotalAmount = (select top 1 sum(UnitPrice*Quantity) over (partition by OrderId)
								from [OrderItem]
								where OrderId = @OrderId)
			update [Order] set TotalAmount = @TotalAmount where Id = @OrderId
			print 'Update successful'
		commit transaction
	end try
	begin catch
		if @@TRANCOUNT > 0 rollback transaction
		declare @ERR nvarchar(MAX)
		set @ERR = ERROR_MESSAGE()
		print 'Update failed.See detaail: '
		raiserror(@ERR,16,1)
		return -1
	end catch
end

declare @StateInsert1 int
exec @StateInsert1 = usp_UpdatePriceOrderItem 21  ,23.00

print @StateInsert1



declare @StateInsert2 int
exec @StateInsert2 = usp_UpdatePriceOrderItem 2145,17.00

print @StateInsert2


select * from OrderItem where OrderId = 8
select * from [Order] where Id = 8