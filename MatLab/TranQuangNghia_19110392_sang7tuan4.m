clc
close all
clear all
%bai 4
% disp('BANG CUU CHUONG');
% s=input('nhap bang cuu chuong: ');
% % for i = 2:9
% %     for j=1:10
% %         t=i*j;
% %         fprintf ('%d * %d = %d\n',i,j,t);
% %     end
% % end
% for i=1:(100-52)/48:10
%     fprintf('%d * %d = %d\n',s,i,s*i);
% end

% %bai 7
% x=input('nhap vector x = ');
% s1=0;s2=0;
% n=length(x);
% for i=1:n
% s1=s1+abs(x(i));
% s2=s2+(x(i)^2);
% end
% s2=sqrt(s2);
% disp(s1);
% disp(s2);
% s3=max(x);
% disp(s3)

% x=input('nhap vector: ');
% xmin=min(x);
% xmax=max(x);
% fprintf('gia tri lon nhat: %2.5g\n',xmax);
% fprintf('gia tri nho nhat: %2.5g\n',xmin);

% xchan=input('nhap vector: ');
% n=length(xchan);
% schan=0;
% for i=1:n
%     if(mod(xchan(i),2)==0)
%         schan=schan+xchan(i);
%     end
% end
% disp(schan);
% 
% xle=input('nhap vector: ');
% n=length(xle);
% sle=0;
% for i=1:n
%     if(mod(xle(i),2)==1)
%         sle=sle+xle(i); 
%     end
% end
% disp(sle);

F=zeros(1,50);
F(1)=1;
F(2)=1;
%tong finabonacci cua 10 so dau tien 
s=F(1)+F(2);
for i=3:10
    F(i)=F(i-1)-F(i-2);
        s=s+F(i);
    end
end
fprintf('s = %d',s)

%tong finabonacci (chia het cho 2 hoac 5) tu 1 den 50
s=0;
for i=3:50
    F(i)=F(i-1)-F(i-2);
    if mod(F(i),2)==0||mod(F(i),5)==0
         s=s+F(i);
    end
end

%tim n de F(n)<100 va F(n+1)>=1000
a=1;
b=1;
n=0;
i=2;
while n==0
    c=a+b;
    i=i+1;
    if(c<1000) && (c+b>=1000)
        n=i;
        disp(n);
    end
    a=b;
    b=c;
end