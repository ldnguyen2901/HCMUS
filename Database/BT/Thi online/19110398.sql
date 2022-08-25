--Ho va Ten: Le Dinh Nguyen
--MSSV: 19110398

--cau 1
select*
from MATHANG AS mh
where mh.DonGia > '20.00' and mh.Conmh = '1';
--cau 2
select NCC.TenNCC, mh.*
from NHACUNGCAP as ncc, MATHANG as mh
where NCC.QuocGia = 'Germany'and ncc.MaNCC = mh.MaNCC;;
--cau 3
select  ddh.*
from DONDATHANG as ddh , CTDDH
where CTDDH.MaDDH=ddh.MaDDH and CTddh.Mamh in (select MaMH
												 from MATHANG
												 where MATHANG.Tenmh ='Manjimup Dried Apples');
--cau 4
select dh.MaKH, kh.HoTen
from KHACHHANG as kh left join DONDATHANG as dh on dh.MaKH = kh.MaKH
group by dh.MaKH,kh.HoTen
having sum(dh.TriGia)>3000;
--cau 5
select kh.MaKH,kh.HoTen, count(ddh.MaDDH) as TongDH
from KHACHHANG as kh left join DONDATHANG as ddh on  kh.MaKH = ddh.MaKH
group by  kh.MaKH,kh.HoTen;
--cau 6
select distinct kh.*
from KHACHHANG as kh, DONDATHANG as ddh
where kh.QuocGia like 'Brazil' and ddh.TriGia >= all(select ddh.TriGia
													 from DONDATHANG as ddh);
			