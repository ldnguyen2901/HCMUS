use master;
go

if exists(select * from sys.databases where name='CsdlDonDatHang')
drop database CsdlDonDatHang;
go

create database CsdlDonDatHang;
go

use CsdlDonDatHang;
go

create table NHACUNGCAP (
   MaNCC        int             not null,
   TenNCC       varchar(40)     not null,
   Email        varchar(40)     null,
   ThanhPho   	varchar(40)     null,
   QuocGia	varchar(40)	null,
   constraint PK_NHACUNGCAP primary key (MaNCC)
);

create table MATHANG (
   MaMH        	int             not null,
   TenMH        varchar(50)     not null,
   MaNCC        int             not null,
   DonGia       decimal(12,2)   null default 0,
   ConMH       	bit            	not null default 0,
   constraint PK_MATHANG primary key (MaMH),
   constraint FK_MATHANG_NHACUNGCAP foreign key (MaNCC) references NHACUNGCAP (MaNCC)
);

create table KHACHHANG (
   MaKH	       	int      	not null,
   HoTen	varchar(50)     not null,
   DiaChi       varchar(50)     null,
   ThanhPho     varchar(40)     null,
   QuocGia	varchar(40)	null,
   SoDT		varchar(15)     null,
   constraint PK_KHACHHANG primary key (MaKH)
);

create table DONDATHANG (
   MaDDH	int		not null,
   NgayDatHang	datetime	not null default getdate(),
   MaKH		int		not null,
   TriGia	decimal(12,2)	null default 0,
   constraint PK_DONDATHANG primary key (MaDDH),
   constraint FK_DONDATHANG_KHACHHANG foreign key (MaKH) references KHACHHANG (MaKH)
);

create table CTDDH (
   MaCT		int		not null,
   MaDDH	int		not null,
   MaMH		int		not null,
   DonGia	decimal(12,2)	not null default 0,
   SoLuong	int		not null default 1,
   constraint PK_CTDDH primary key (MaCT),
   constraint FK_CTDDH_DDH foreign key (MaDDH) references DONDATHANG (MaDDH),
   constraint FK_CTDDH_MATHANG foreign key (MaMH) references MATHANG (MaMH)
);

-- Inserting for NHACUNGCAP table
insert into NHACUNGCAP values (1,'Exotic Liquids',null,'London','UK');
insert into NHACUNGCAP values (2,'New Orleans Cajun Delights',null,'New Orleans','USA');
insert into NHACUNGCAP values (3,'Grandma Kelly''s Homestead',null,'Ann Arbor','USA');
insert into NHACUNGCAP values (4,'Tokyo Traders',null,'Tokyo','Japan');
insert into NHACUNGCAP values (5,'Cooperativa de Quesos ''Las Cabras''',null,'Oviedo','Spain');
insert into NHACUNGCAP values (6,'Mayumi''s',null,'Osaka','Japan');
insert into NHACUNGCAP values (7,'Pavlova, Ltd.',null,'Melbourne','Australia');
insert into NHACUNGCAP values (8,'Specialty Biscuits, Ltd.',null,'Manchester','UK');
insert into NHACUNGCAP values (9,'PB Knackebrod AB',null,'Goteborg','Sweden');
insert into NHACUNGCAP values (10,'Refrescos Americanas LTDA',null,'Sao Paulo','Brazil');
insert into NHACUNGCAP values (11,'Heli Subwaren GmbH & Co. KG',null,'Berlin','Germany');
insert into NHACUNGCAP values (12,'Plutzer Lebensmittelgrobmarkte AG',null,'Frankfurt','Germany');
insert into NHACUNGCAP values (13,'Nord-Ost-Fisch Handelsgesellschaft mbH',null,'Cuxhaven','Germany');
insert into NHACUNGCAP values (14,'Formaggi Fortini s.r.l.',null,'Ravenna','Italy');
insert into NHACUNGCAP values (15,'Norske Meierier',null,'Sandvika','Norway');
insert into NHACUNGCAP values (16,'Bigfoot Breweries',null,'Bend','USA');
insert into NHACUNGCAP values (17,'Svensk Sjofoda AB',null,'Stockholm','Sweden');
insert into NHACUNGCAP values (18,'Aux joyeux ecclesiastiques',null,'Paris','France');
insert into NHACUNGCAP values (19,'New England Seafood Cannery',null,'Boston','USA');
insert into NHACUNGCAP values (20,'Leka Trading',null,'Singapore','Singapore');
insert into NHACUNGCAP values (21,'Lyngbysild',null,'Lyngby','Denmark');
insert into NHACUNGCAP values (22,'Zaanse Snoepfabriek',null,'Zaandam','Netherlands');
insert into NHACUNGCAP values (23,'Karkki Oy',null,'Lappeenranta','Finland');
insert into NHACUNGCAP values (24,'G''day, Mate',null,'Sydney','Australia');
insert into NHACUNGCAP values (25,'Ma Maison',null,'Montreal','Canada');
insert into NHACUNGCAP values (26,'Pasta Buttini s.r.l.',null,'Salerno','Italy');
insert into NHACUNGCAP values (27,'Escargots Nouveaux',null,'Montceau','France');
insert into NHACUNGCAP values (28,'Gai paturage',null,'Annecy','France');
insert into NHACUNGCAP values (29,'Forets d''erables',null,'Ste-Hyacinthe','Canada');

-- Inserting for MATHANG table
insert into MATHANG values (1,'Chai',1,18.00,0);
insert into MATHANG values (2,'Chang',1,19.00,0);
insert into MATHANG values (3,'Aniseed Syrup',1,10.00,0);
insert into MATHANG values (4,'Chef Anton''s Cajun Seasoning',2,22.00,0);
insert into MATHANG values (5,'Chef Anton''s Gumbo Mix',2,21.35,1);
insert into MATHANG values (6,'Grandma''s Boysenberry Spread',3,25.00,0);
insert into MATHANG values (7,'Uncle Bob''s Organic Dried Pears',3,30.00,0);
insert into MATHANG values (8,'Northwoods Cranberry Sauce',3,40.00,0);
insert into MATHANG values (9,'Mishi Kobe Niku',4,97.00,1);
insert into MATHANG values (10,'Ikura',4,31.00,0);
insert into MATHANG values (11,'Queso Cabrales',5,21.00,0);
insert into MATHANG values (12,'Queso Manchego La Pastora',5,38.00,0);
insert into MATHANG values (13,'Konbu',6,6.00,0);
insert into MATHANG values (14,'Tofu',6,23.25,0);
insert into MATHANG values (15,'Genen Shouyu',6,15.50,0);
insert into MATHANG values (16,'Pavlova',7,17.45,0);
insert into MATHANG values (17,'Alice Mutton',7,39.00,1);
insert into MATHANG values (18,'Carnarvon Tigers',7,62.50,0);
insert into MATHANG values (19,'Teatime Chocolate Biscuits',8,9.20,0);
insert into MATHANG values (20,'Sir Rodney''s Marmalade',8,81.00,0);
insert into MATHANG values (21,'Sir Rodney''s Scones',8,10.00,0);
insert into MATHANG values (22,'Gustaf''s Knackebröd',9,21.00,0);
insert into MATHANG values (23,'Tunnbrod',9,9.00,0);
insert into MATHANG values (24,'Guarana Fantastica',10,4.50,1);
insert into MATHANG values (25,'NuNuCa Nub-Nougat-Creme',11,14.00,0);
insert into MATHANG values (26,'Gumbar Gummibarchen',11,31.23,0);
insert into MATHANG values (27,'Schoggi Schokolade',11,43.90,0);
insert into MATHANG values (28,'Rossle Sauerkraut',12,45.60,1);
insert into MATHANG values (29,'Thuringer Rostbratwurst',12,123.79,1);
insert into MATHANG values (30,'Nord-Ost Matjeshering',13,25.89,0);
insert into MATHANG values (31,'Gorgonzola Telino',14,12.50,0);
insert into MATHANG values (32,'Mascarpone Fabioli',14,32.00,0);
insert into MATHANG values (33,'Geitost',15,2.50,0);
insert into MATHANG values (34,'Sasquatch Ale',16,14.00,0);
insert into MATHANG values (35,'Steeleye Stout',16,18.00,0);
insert into MATHANG values (36,'Inlagd Sill',17,19.00,0);
insert into MATHANG values (37,'Gravad lax',17,26.00,0);
insert into MATHANG values (38,'Cote de Blaye',18,263.50,0);
insert into MATHANG values (39,'Chartreuse verte',18,18.00,0);
insert into MATHANG values (40,'Boston Crab Meat',19,18.40,0);
insert into MATHANG values (41,'Jack''s New England Clam Chowder',19,9.65,0);
insert into MATHANG values (42,'Singaporean Hokkien Fried Mee',20,14.00,1);
insert into MATHANG values (43,'Ipoh Coffee',20,46.00,0);
insert into MATHANG values (44,'Gula Malacca',20,19.45,0);
insert into MATHANG values (45,'Rogede sild',21,9.50,0);
insert into MATHANG values (46,'Spegesild',21,12.00,0);
insert into MATHANG values (47,'Zaanse koeken',22,9.50,0);
insert into MATHANG values (48,'Chocolade',22,12.75,0);
insert into MATHANG values (49,'Maxilaku',23,20.00,0);
insert into MATHANG values (50,'Valkoinen suklaa',23,16.25,0);
insert into MATHANG values (51,'Manjimup Dried Apples',24,53.00,0);
insert into MATHANG values (52,'Filo Mix',24,7.00,0);
insert into MATHANG values (53,'Perth Pasties',24,32.80,1);
insert into MATHANG values (54,'Tourtiere',25,7.45,0);
insert into MATHANG values (55,'Pâté chinois',25,24.00,0);
insert into MATHANG values (56,'Gnocchi di nonna Alice',26,38.00,0);
insert into MATHANG values (57,'Ravioli Angelo',26,19.50,0);
insert into MATHANG values (58,'Escargots de Bourgogne',27,13.25,0);
insert into MATHANG values (59,'Raclette Courdavault',28,55.00,0);
insert into MATHANG values (60,'Camembert Pierrot',28,34.00,0);
insert into MATHANG values (61,'Sirop d''erable',29,28.50,0);
insert into MATHANG values (62,'Tarte au sucre',29,49.30,0);
insert into MATHANG values (63,'Vegie-spread',7,43.90,0);
insert into MATHANG values (64,'Wimmers gute Semmelknodel',12,33.25,0);
insert into MATHANG values (65,'Louisiana Fiery Hot Pepper Sauce',2,21.05,0);
insert into MATHANG values (66,'Louisiana Hot Spiced Okra',2,17.00,0);
insert into MATHANG values (67,'Laughing Lumberjack Lager',16,14.00,0);
insert into MATHANG values (68,'Scottish Longbreads',8,12.50,0);
insert into MATHANG values (69,'Gudbrandsdalsost',15,36.00,0);
insert into MATHANG values (70,'Outback Lager',7,15.00,0);
insert into MATHANG values (71,'Flotemysost',15,21.50,0);
insert into MATHANG values (72,'Mozzarella di Giovanni',14,34.80,0);
insert into MATHANG values (73,'Rod Kaviar',17,15.00,0);
insert into MATHANG values (74,'Longlife Tofu',4,10.00,0);
insert into MATHANG values (75,'Rhonbrau Klosterbier',12,7.75,0);
insert into MATHANG values (76,'Lakkalikoori',23,18.00,0);
insert into MATHANG values (77,'Original Frankfurter grune Sobe',12,13.00,0);
insert into MATHANG values (78,'Stroopwafels',22,9.75,0);

-- Inserting for KHACHHANG table
insert into KHACHHANG values (1,'Maria Anders',null,'Berlin','Germany','030-0074321');
insert into KHACHHANG values (2,'Ana Trujillo',null,'Mexico D.F.','Mexico','(5) 555-4729');
insert into KHACHHANG values (3,'Antonio Moreno',null,'Mexico D.F.','Mexico','(5) 555-3932');
insert into KHACHHANG values (4,'Thomas Hardy',null,'London','UK','(171) 555-7788');
insert into KHACHHANG values (5,'Christina Berglund',null,'Lulea','Sweden','0921-12 34 65');
insert into KHACHHANG values (6,'Hanna Moos',null,'Mannheim','Germany','0621-08460');
insert into KHACHHANG values (7,'Frederique Citeaux',null,'Strasbourg','France','88.60.15.31');
insert into KHACHHANG values (8,'Martin Sommer',null,'Madrid','Spain','(91) 555 22 82');
insert into KHACHHANG values (9,'Laurence Lebihan',null,'Marseille','France','91.24.45.40');
insert into KHACHHANG values (10,'Elizabeth Lincoln',null,'Tsawassen','Canada','(604) 555-4729');
insert into KHACHHANG values (11,'Victoria Ashworth',null,'London','UK','(171) 555-1212');
insert into KHACHHANG values (12,'Patricio Simpson',null,'Buenos Aires','Argentina','(1) 135-5555');
insert into KHACHHANG values (13,'Francisco Chang',null,'Mexico D.F.','Mexico','(5) 555-3392');
insert into KHACHHANG values (14,'Yang Wang',null,'Bern','Switzerland','0452-076545');
insert into KHACHHANG values (15,'Pedro Afonso',null,'Sao Paulo','Brazil','(11) 555-7647');
insert into KHACHHANG values (16,'Elizabeth Brown',null,'London','UK','(171) 555-2282');
insert into KHACHHANG values (17,'Sven Ottlieb',null,'Aachen','Germany','0241-039123');
insert into KHACHHANG values (18,'Janine Labrune',null,'Nantes','France','40.67.88.88');
insert into KHACHHANG values (19,'Ann Devon',null,'London','UK','(171) 555-0297');
insert into KHACHHANG values (20,'Roland Mendel',null,'Graz','Austria','7675-3425');
insert into KHACHHANG values (21,'Aria Cruz',null,'Sao Paulo','Brazil','(11) 555-9857');
insert into KHACHHANG values (22,'Diego Roel',null,'Madrid','Spain','(91) 555 94 44');
insert into KHACHHANG values (23,'Martine Rance',null,'Lille','France','20.16.10.16');
insert into KHACHHANG values (24,'Maria Larsson',null,'Bracke','Sweden','0695-34 67 21');
insert into KHACHHANG values (25,'Peter Franken',null,'Munchen','Germany','089-0877310');
insert into KHACHHANG values (26,'Carine Schmitt',null,'Nantes','France','40.32.21.21');
insert into KHACHHANG values (27,'Paolo','Accorti','Torino','Italy','011-4988260');
insert into KHACHHANG values (28,'Lino Rodriguez',null,'Lisboa','Portugal','(1) 354-2534');
insert into KHACHHANG values (29,'Eduardo Saavedra',null,'Barcelona','Spain','(93) 203 4560');
insert into KHACHHANG values (30,'Jose Pedro Freyre',null,'Sevilla','Spain','(95) 555 82 82');
insert into KHACHHANG values (31,'Andre Fonseca',null,'Campinas','Brazil','(11) 555-9482');
insert into KHACHHANG values (32,'Howard Snyder',null,'Eugene','USA','(503) 555-7555');
insert into KHACHHANG values (33,'Manuel Pereira',null,'Caracas','Venezuela','(2) 283-2951');
insert into KHACHHANG values (34,'Mario Pontes',null,'Rio de Janeiro','Brazil','(21) 555-0091');
insert into KHACHHANG values (35,'Carlos Hernandez',null,'San Cristobal','Venezuela','(5) 555-1340');
insert into KHACHHANG values (36,'Yoshi Latimer',null,'Elgin','USA','(503) 555-6874');
insert into KHACHHANG values (37,'Patricia McKenna',null,'Cork','Ireland','2967 542');
insert into KHACHHANG values (38,'Helen Bennett',null,'Cowes','UK','(198) 555-8888');
insert into KHACHHANG values (39,'Philip Cramer',null,'Brandenburg','Germany','0555-09876');
insert into KHACHHANG values (40,'Daniel Tonini',null,'Versailles','France','30.59.84.10');

-- Inserting for DONDATHANG table
insert into DONDATHANG values (1,'Jul  4 2012 12:00:00:000AM',15,440.00);
insert into DONDATHANG values (2,'Jul  5 2012 12:00:00:000AM',9,1863.40);
insert into DONDATHANG values (3,'Jul  8 2012 12:00:00:000AM',34,1813.00);
insert into DONDATHANG values (4,'Jul  8 2012 12:00:00:000AM',14,670.80);
insert into DONDATHANG values (5,'Jul  9 2012 12:00:00:000AM',26,3730.00);
insert into DONDATHANG values (6,'Jul 10 2012 12:00:00:000AM',34,1444.80);
insert into DONDATHANG values (7,'Jul 11 2012 12:00:00:000AM',14,625.20);
insert into DONDATHANG values (8,'Jul 12 2012 12:00:00:000AM',38,2490.50);
insert into DONDATHANG values (9,'Jul 15 2012 12:00:00:000AM',28,517.80);
insert into DONDATHANG values (10,'Jul 16 2012 12:00:00:000AM',35,1119.90);

-- Inserting for CTDDH table
insert into CTDDH values (1,1,11,14.00,12);
insert into CTDDH values (2,1,42,9.80,10);
insert into CTDDH values (3,1,72,34.80,5);
insert into CTDDH values (4,2,14,18.60,9);
insert into CTDDH values (5,2,51,42.40,40);
insert into CTDDH values (6,3,41,7.70,10);
insert into CTDDH values (7,3,51,42.40,35);
insert into CTDDH values (8,3,65,16.80,15);
insert into CTDDH values (9,4,22,16.80,6);
insert into CTDDH values (10,4,57,15.60,15);
insert into CTDDH values (11,4,65,16.80,20);
insert into CTDDH values (12,5,20,64.80,40);
insert into CTDDH values (13,5,33,2.00,25);
insert into CTDDH values (14,5,60,27.20,40);
insert into CTDDH values (15,6,31,10.00,20);
insert into CTDDH values (16,6,39,14.40,42);
insert into CTDDH values (17,6,49,16.00,40);
insert into CTDDH values (18,7,24,3.60,15);
insert into CTDDH values (19,7,55,19.20,21);
insert into CTDDH values (20,7,74,8.00,21);
insert into CTDDH values (21,8,2,15.20,20);
insert into CTDDH values (22,8,16,13.90,35);
insert into CTDDH values (23,8,36,15.20,25);
insert into CTDDH values (24,8,59,44.00,30);
insert into CTDDH values (25,9,53,26.20,15);
insert into CTDDH values (26,9,77,10.40,12);
insert into CTDDH values (27,10,27,35.10,25);
insert into CTDDH values (28,10,39,14.40,6);
insert into CTDDH values (29,10,77,10.40,15);