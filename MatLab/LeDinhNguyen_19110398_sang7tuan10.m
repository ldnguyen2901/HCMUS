clc
close all
clear

%%BT8
%bai 3
% %3a
% x= -4:0.2:4;
% y= -4:0.2:4;
% [X,Y]= meshgrid(x,y);
% Z= X.^2.*Y.*exp(-X.^2-Y.^2)
% mesh(X,Y,Z);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat X.^2.*Y.exp(-X.^2-Y.^2)');

% %b
% x= -2:0.1:2;
% y= -2:0.1:2;
% [X,Y]= meshgrid(x,y);
% Z= 0.5.*abs(X)+0.5.*abs(Y);
% mesh(X,Y,Z);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat 0.5.*abs(x)+0.5.*abs(y)');

% %c
% x= -10:0.2:10;
% y= -10:0.2:10;
% [X,Y]= meshgrid(x,y);
% R= sqrt(X.^2+Y.^2);
% Z=sin(R)./R;
% mesh(X,Y,Z);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat sqrt(X.^2+Y.^2)');

% %bai 4
% t = linspace(0,2*pi,100);
% x = 5*cos(t);
% y = 5*sin(t);
% plot(x,y);
% axis([-6 6 -6 6]);
% xlabel('x');
% ylabel('y');
% axis equal
% title('Ve ham so x = 5cost, y=5sint');

% %bai 5
% t = linspace(0,6*pi,200);
% x = sin(t);
% y = cos(t);
% z = t;
% plot3(x,y,z);
% axis([-1 1 -1 1 20 20]);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% axis equal
% title('Ve ham so plot3 x = sint, y = cost, z = t');

% % bai 6
% u = linspace(0,2*pi,50);
% v = linspace(-pi/2,pi/2,50);
% [U,V] = meshgrid(u,v)
% X = cos(V).*cos(U);
% Y = cos(V).*sin(U);
% Z = sin(V);
% mesh(X,Y,Z);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('do thi hinh cau voi lenh mesh');

% % bai 7
% t = linspace(0,2*pi,300);
% x = (4+3*cos(11*t)).*cos(t);
% y = (4+3*cos(11*t)).*sin(t);
% plot(x,y);
% axis([-8 8 -8 8]);
% xlabel('x');
% ylabel('y');
% axis equal
% title('Ve ham so');

% %bai 8
% t = linspace(0,6*pi,200);
% x = sqrt(t).*sin(2*t);
% y = sqrt(t).*cos(2*t);
% z = 0.5.*t;
% plot3(x,y,z);
% axis([-5 5 -5 5 10 10]);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% axis equal
% title('Ve ham so plot3 x = sint, y = cost, z = t');

% %bai 9
% u = linspace(0,2*pi,100);
% v = linspace(-5,5,100);
% [U,V] = meshgrid(u,v)
% X = cos(U);
% Y = sin(U);
% Z = V;
% mesh(X,Y,Z);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('do thi hinh cau voi lenh mesh');

% %bai 10
% u = linspace(0,2*pi,100);
% v = linspace(0,2*pi,100);
% [U,V] = meshgrid(u,v);
% X = (1+0.5.*cos(V)).*cos(U);
% Y = (1+0.5.*cos(V)).*sin(U);
% Z = 0.5.*sin(V);
% mesh(X,Y,Z);
% axit([-1.5 1.5 -1.5 1.5 -.5 0.5]);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% axit equal;
% title('do thi hinh cau voi lenh mesh');

% %bai 11
% u = linspace(0,2*pi,50);
% v = linspace(-2,2,50);
% [U,V] = meshgrid(u,v);
% X = cos(U);
% Y = sin(U);
% Z = V;
% X1=0.5.*cos(U);
% Y1=V;
% Z1=0.5.*sin(U);
% mesh(X,Y,Z);
% hold on
% mesh(X1,Y1,Z1);
% xlabel('x');
% ylabel('y');
% zlabel('z');

% %bai 12
% u = linspace(0,2*pi,50);
% v = linspace(-2,2,50);
% [U,V] = meshgrid(u,v);
% s = linspace(-pi/2,pi/2,50);
% t = linspace(0,2*pi,50);
% [S,T] = meshgrid(s,t);
% X = cos(U);
% Y = sin(U);
% Z = V;
% X1=1+cos(S).*(1+(1/4).*cos(T));
% Y1=(1/4).*sin(T);
% Z1=(1/2)+sin(S).*(1+(1/4).*cos(T));
% mesh(X,Y,Z);
% % axit([-2 3 -2 2 -2 2 ]);
% hold on;
% mesh(X1,Y1,Z1);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% % axit equal;

%%BT9
%bai 1
%1.1
% a=[1 -2 3;-1 3 0;2 -5 5]
% b=[9 -4 17]';
% x1 = a\b

%1.2
% a=[3 3 4;1 1 4;2 -5 4];
% b=[2 -2 3]';
% x1=a\b

%bai 3
% A=[3 3 4;1 1 4;2 -5 4]
% B=[2 -2 3]';
% x=zeros(3,1);
% A1=A;
% A1(:,[1])=B;
% x(1)=det(A1)/det(A);
% 
% A2=A;
% A2(:,[2])=B;
% x(2)=det(A2)/det(A);
% 
% A3=A;
% A3(:,[3])=B;
% x(3)=det(A3)/det(A)


%bai 4
%a)
% A=[1 3 3 -2;2 -1 -2 -3;3 2 -1 2;2 -3 2 1];
% B=[6 4 4 -8]';
% x=zeros(4,1);
% A1=A;
% A1(:,[1])=B;
% x(1)=det(A1)/det(A);
% A2=A;
% A2(:,[2])=B;
% x(2)=det(A2)/det(A);
% A3=A;
% A3(:,[3])=B;
% x(3)=det(A3)/det(A)
% A4=A;
% A4(:,[4])=B;
% x(4)=det(A4)/det(A)

%b)
% A=[1 3 5 -4 0;1 3 2 -2 1;1 -2 1 -1 -1;1 -4 1 1 -1;1 2 1 -1 1];
% B=[1 -1 3 3 -1]';
% x=zeros(5,1);
% A1=A;
% A1(:,[1])=B;
% x(1)=det(A1)/det(A);
% A2=A;
% A2(:,[2])=B;
% x(2)=det(A2)/det(A);
% A3=A;
% A3(:,[3])=B;
% x(3)=det(A3)/det(A)
% A4=A;
% A4(:,[4])=B;
% x(4)=det(A4)/det(A)
% A5=A;
% A5(:,[5])=B;
% x(5)=det(A5)/det(A)


%bai 6
%a)
% R=linspace(0,4,100);
% theta=linspace(0,2*pi,100);
% [RR,Ttheta] = meshgrid(R,theta);
% x = (RR.*cos(Ttheta));
% y = (RR.*sin(Ttheta));
% z = RR.^2+1;
% mesh(x,y,z)

% %b)
% v = linspace(-1,1,100);
% u = linspace (0,2*pi,100);
% [U,V] = meshgrid(u,v);
% x = sqrt(1+4.*V.^2).*cos(U);
% y = V;
% z = sqrt(1+4.*V.^2).*sin(U);
% mesh (x,y,z);

% %bai 7
% syms x y
% f = x^2 +x*y +y^2 +y;
% fx = diff(f,x)
% fxx = diff(f,x,2)
% fy = diff(f,y)
% fxy = diff(diff(f,y),x)
% fyy = diff(f,y,2)

%bai 8
%f = sqrt(1-x^2)
%intf = int(f,x);

% f = cos(y^2);
% g = int(int(f,x,y,1),x,0,1);
% %8d
% f = y*exp(x^2)/x^3;
% g1 = int(int(f,x,sqrt(y),1),y,0,1)

%bai 10
% x1 = linspace(-2,2,100)
% y1 = 2*x1.^2;
% y2 = x1.^2+1;
% plot(x1,y1,x1,y2);

syms x y
f = 1;
f1 = 2*x^2;
f2 = x^2 + 1;
g11 = int(int(f,x,f1,f2),x,-1,1)