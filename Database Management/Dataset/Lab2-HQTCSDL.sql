--voi moi khach hang cho biet Ma Khach Hang, Ten Khach Hang, Tong Gia Tri Trung Binh va Tong So Hoa Don
-- va sap xep theo Tong So Hoa Don
select C.Id, C.FirstName + ' ' + C.LastName as [Ho Ten],
	   count(O.OrderNumber) as [Tong So Hoa Don],
	   avg(O.TotalAmount) [Tong Gia Trung Binh]
from Customer as C
inner join [Order] as O on C.Id = O.CustomerId
group by C.Id, C.FirstName, C.LastName
order by [Tong So Hoa Don] desc;

--Nhu cau tren nhung chi xuat danh sach khong co hoac co it hon 3 hoa don mua hang
select C.FirstName + ' ' + C.LastName as [Ho Ten],
isnull(count(O.OrderNumber),0) as [Tong So Hoa Don],
isnull(avg(O.TotalAmount),0) [Tong Gia Trung Binh]
from Customer as C
left join [Order] as O on C.Id = O.CustomerId
group by C.FirstName, C.LastName
having count (O.OrderNumber) < 3
order by [Tong So Hoa Don] desc;

--Xuat danh sach scac OrderNumber kem theo Total Amount va Description
--Description la "Under Average" neu so luong Total Amount nho hon so luong trung binh
--va "Above Average" neu nguoc lai
select OrderNumber, TotalAmount, 'Above Average' as [Description]
from [Order]
where TotalAmount >= (select(avg(TotalAmount)) from [Order])
union
select OrderNumber, TotalAmount, 'Below Average' as [Description]
from [Order]
where TotalAmount < (select(avg(TotalAmount)) from [Order]);

--Xuat thong tin nhung quoc gia nao vua co nha cung cap va vua co khach hang
select Country
from Customer
intersect
select Country
from Supplier;

--Xuat thong tin nhung quoc gia nao chi co khach hang ma khong co nha cung cap
select Country
from Customer
except
select Country
from Supplier;

--Xuat thong tin nhung san pham nao co gia cao hon gia cac san pham cua SupplierId 8
select *
from Product
where UnitPrice >= all(select UnitPrice from Product where SupplierId = 8);

--Xuat danh sach cac san pham co nha cung cap nhieu thu 4 trong cac nha cung cap
select *
from Product
where SupplierId in (select top 4 SupplierId 
					 from Product
					 group by SupplierId
					 order by count(ProductName)desc);

--Xuat danh sach cac khach hang co hoa don vao thang 7
select *
from Customer C
where exists (select *
			  from [Order] as O, Customer C
			  where O.CustomerId = C.Id and MONTH(O.OrderDate) = 7)


