%Le Dinh Nguyen
%19110398
%Sang Tuan 2
clc
clear all
close all
% a=input('nhap a: ')
% b=input('nhap b: ')
% c=a*b
% disp('c=')
% disp(c)

% %chuong trinh tinh dthcn
% disp('tinh dien tich hinh chu nhat');
% a=input('nhap a: ');
% b=input('nhap b: ');
% s=a*b;
% disp('dien tich hinh chu nhat');
% disp(s)
% %chuong trinh giai phuong trinh bac 2
% disp('CHUONG TRINH GIAI PHUONG TRINH BAC 2');
% disp('nhap vao cac he so')
% a=input('nhap he so a= ');
% b=input('nhap he so b= ');
% c=input('nhap he so c= ');
% delta =b^2-4*a*c;
% disp('cac nghiem so: ');
% x1=(-b+sqrt(delta))/(2*a)
% x2=(-b-sqrt(delta))/(2*a)

% a=input('nhap a= ');
% b=input('nhap b= ');
% if(a<b)
%     disp('a nho hon b');
% end
% if(a==b)
%     disp('a bang b')
% end
% if(a>b)
%     disp('a lon hon b')
% end

% %Giai phuong trinh bat nhat
% a=input('nhap a= ');
% b=input('nhap b= ');
% if(a~=0)
%     x=-b/a;
%     disp(x)
% elseif (a==0)
%     if(b~=0)
%         disp('ptvn');
%     else
%         disp('ptsvn');
%     end
% end
        
% %bai4
% km=input('km = ');
% if(km<1)
%     x=15000*km;
%     disp(x)
% elseif(km>=1)&(km<6)
%     x=15000+13500*(km-1);
%     disp(x)
% elseif(km>=5)&(km<120)
%     x=15000+13500*4+11000*(km-5);
%     disp(x)
% elseif(km>120)
%     x=(15000+13500*4+11000*115000+(km-120))*0.9;
%     disp (x)
% end
   
% %bai1
% a=input('nhap a: ');
% switch a
%     case 1
%         disp('Mot');
%     case 2
%         disp('Hai');
%     case 3
%         disp('Ba');
%     case 4
%         disp('Bon');
%     case 5
%         disp('Nam');
%     case 6
%         disp('Sau');
%     case 7
%         disp('Bay');
%     case 8;
%         disp('Tam');
%     case 9
%         disp('Chin');
%     otherwise
%         disp('nhap sai');
% end

%bai2
month=input('thang: ');
year=input('nam: ');
switch month
    case {1,3,5,7,8,10,12}
        disp('31 days');
    case {4,6,9,11}
        disp('30 days');
    case 2
        if(mod(year,400)==0)|(mod(year,4)==0&mod(year,100)~=0)
            disp('29 days');
        else disp('28 days');
        end
    otherwise
        disp('du lieu khong hop le');
end
    
    
        
