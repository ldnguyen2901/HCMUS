--cau 26
select *
from NHANVIEN
where MaNV not in (select MaNV from CHUNGNHAN);

--cau 28
select sum(Luong) as Tongluong
from CHUNGNHAN as CN, NHANVIEN as NV
where CN.MaNV = NV.MaNV

--cau 31 b
select *
from NHANVIEN 
where MaNV in (select MaNV
			   from CHUNGNHAN) and Luong>100000 

--cau 34
select MaNV
from NHANVIEN
where Luong = (select max(Luong) 
			   from NHANVIEN
			   where Luong < any(select Luong
			   		     from NHANVIEN));

--cau 38
select NV.Ten,count (MB.MaMB) as 'Phi cong lai it nhat 3 may bay co tam bay > 3200' 
from NHANVIEN as NV, CHUNGNHAN as CN, MAYBAY as MB
where (NV.MaNV = CN.MaNV) and (MB.TamBay >3200) and (MB.MaMB = CN.MaMB)
group by Ten
having count(MB.MaMB)>=3;

--cau 40
select NV.MaNV, NV.Ten, count(CN.MaMB) as SoMB
from (NHANVIEN as NV left join CHUNGNHAN as CN on NV.MaNV = CN.MaNV),MAYBAY as MB
where (Loai like 'Boeing%') and (CN.MaMB = MB.MaMB)
group by NV.MaNV, NV.Ten;

--cau 42 b
select MB.Loai, count(CB.MaCB) as SoCB 
from (MAYBAY as MB left join CHUYENBAY as CB on MB.TamBay <= CB.DoDai)
group by MB.MaMB,MB.Loai;
--cau 45
select MB.Loai, count(NV.MaNV) as SoNV
from(MAYBAY as MB left join NHANVIEN as NV on not exists (select *
														  from CHUNGNHAN as CN
														  where CN.MaMB = MB.MaMB and CN.MaNV = NV.MaNV))
group by MB.MaMB, MB.Loai;

--cau 48 
select NV.MaNV,NV.Ten,count(CB.MaCB) as SoCB
from (NHANVIEN as NV left join CHUYENBAY as CB on CB.GaDi = 'SGN' and CB.DoDai >= all(select MB.tambay
																					  from MAYBAY as MB, CHUNGNHAN as CN
																					  where MB.MaMB = CN.MaMB and CN.MaNV = NV.MaNV))
group by NV.MaNV,NV.Ten;
--cau 61
select *
from NHANVIEN as NV
where not exists (select *
				  from MAYBAY as MB
				  where (MB.Loai like 'Boeing%') and not exists  (select *
																  from CHUNGNHAN as CN
																  where (CN.MaNV = NV.MaNV) and (CN.MaMB = MB.MaMB)))

--cac vi du
--cau 27
select MaNV
from NHANVIEN
where Luong	>=	all(select Luong
					from NHANVIEN);
--other way cau 27
select MaNV
from NHANVIEN
where Luong = (select max(Luong) 
			   from NHANVIEN);

--cau 60
-- R1 = NHANVIEN(MaNV)
-- R = CHUNGNHAN(Manv, MaMB)
-- S = MAYBAY(MaMB)
-- R : S
select *
from NHANVIEN as NV
where not exists (select *
				  from MAYBAY as MB
				  where not exists (select *
									from CHUNGNHAN as CN
									where CN.MaNV = NV.MaNV and CN.MaNV = MB.MaMB));

--cau 39
select NV.MaNV, NV.Ten, count(CN.MaMB) as SoMB
from (NHANVIEN as NV left join CHUNGNHAN as CN on NV.MaNV = CN.MaNV)
group by NV.MaNV, NV.Ten;