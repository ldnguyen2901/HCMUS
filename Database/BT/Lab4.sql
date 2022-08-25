--cau so 1
select *
from CHUYENBAY
where GaDen = 'DAD';

--cau so 3
select *
from NHANVIEN
where Luong<10000;

--cau so 5
select *
from CHUYENBAY
where GaDi = 'SGN' and GaDen = 'BMV';

--cau so 7
select Loai
from MAYBAY
where Loai like 'Boeing%';

--cau so 9
select distinct CN.MaNV
from MAYBAY as MB,CHUNGNHAN as CN
where (CN.MaMB = MB.MaMB) and (Loai like 'Boeing%');

--cau so 11
select MB.MaMB
from NHANVIEN as NV,MAYBAY as MB,CHUNGNHAN as CN
where (NV.Ten like 'Nguyen%') and ((NV.MaNV = CN.MaNV) and (CN.MaMB = MB.MaMB)); 

--cau so 18
select GaDi, count(MaCB) as 'Số chuyến bay'
from CHUYENBAY
group by GaDi;

--cau so 20
select GaDi, count(MaCB) as 'Chuyến bay trước 12h'
from CHUYENBAY
where (GioDi<'12:00:00')
group by GaDi

--cau so 22
select CN.MaNV, MAX(MB.Tambay) as 'Tam bay lon nhat'
from NHANVIEN as NV,MAYBAY as MB,CHUNGNHAN as CN
where (CN.MaNV = NV.MaNV) and (MB.MaMB = CN.MaMB)
group by CN.MaNV
having count(CN.MaMB) > 3

--cau so 24
select MaNV
from CHUNGNHAN as CN, MAYBAY as MB
where (CN.MaMB=MB.MaMB) 
group by MaNV
having count(MaNV) >= All (
select count(MaNV) 
from CHUNGNHAN as CN, MAYBAY as MB 
where (CN.MaMB=MB.MaMB) 
group by MaNV);


--vidu
-- cau so 2
select Loai
from MAYBAY
where TamBay>10000;

--cau so 10
select *
from CHUNGNHAN as CN,NHANVIEN as NV
where (CN.MaNV=NV.MaNV) and (MaMB=747);
