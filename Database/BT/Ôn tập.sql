--cau 12
select *
from CHUNGNHAN as cn, MAYBAY as MB
where cn.MaMB =  MB.MaMB and (MB.Loai like 'Boeing%' or MB.Loai like 'Airbus%'); 

--cau 14
select *
from CHUYENBAY as CB, MAYBAY as MB
where MB.TamBay >= CB.DoDai and MB.Loai like 'Airbus A320';

--cau 16
select MB.MaMB, MB.Loai, count(CN.MaNV) as SumNV
from MAYBAY as MB, CHUNGNHAN as CN
where CN.MaMB = MB.MaMB
group by MB.MaMB,MB.Loai;

--cau 19
select CB.GaDi, sum(CB.ChiPhi) as ChiPhi
from CHUYENBAY as CB, NHANVIEN as NV, CHUNGNHAN as CN, MAYBAY as MB
where MB.TamBay >= CB.DoDai and (MB.MaMB = CN.MaMB and CN.MaNV = NV.MaNV)
group by CB.GaDi;

select GaDi, sum(ChiPhi) as TongCPfrom CHUYENBAYgroup by GaDi;

--cau 21
select CN.MaNV
from MAYBAY as MB, CHUNGNHAN as CN
where MB.MaMB = CN.MaMB
group by CN.MaNV
having count(CN.MaMB) = 3; 

--cau 23
select MaNV, count(MaMB) as MayBay
from CHUNGNHAN 
group by MaNV

--cau 25
select MaNV, count(MaMB) as MayBay
from CHUNGNHAN 
group by MaNV
having count(MaMB) <=  all(select count(MaMB)
						  from CHUNGNHAN
						  group by MaNV)