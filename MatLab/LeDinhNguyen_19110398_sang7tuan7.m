clc
clear all
close all
% x= -2*pi:pi/100:2*pi;
% plot(x,sin(x))
% hold
% plot(x,cos(x),'r')

% y1=sin(x);
% y2=sin(x+pi/4);
% y3=sin(x+pi/2);
% plot(x,y1,x,y2,x,y3)

% f=50;
% T=1/f;
% t=0:T/100:2*T;
% va=220*sin(2*pi*f*t);
% plot(t,va,'blue');
% hold on;
% vb=220*sin(2*pi*f*t+120*pi/180);
% plot(t,vb,'green');
% hold on;
% vc=220*sin(2*pi*f*t-120*pi/180);
% plot(t,vc,'red');

% t=0:pi/20:2*pi;
% plot(t,sin(t),'--r p','LineWidth',5);

% x=0:0.25:pi/2;
% y=tan(x);
% plot(x,y,'--ro');
% axis([0 pi/2 0 5])
% grid on

% x=0:0.01:20;
% y=0.8*exp(-0.5*x).*sin(10*x);
% plot(x,y);
% xlabel('x');
% ylabel('0y');
% legend('0.8 e^{-0.5x}sin(10x)');
% title('do thi ham y = 0.8 e^{-0.5x}sin(10x)');

% f=50;
% T=1/f;
% t=0:T/100:2*T;
% v=220*sin(2*pi*f*t);
% i=55*sin(2*pi*f*t-90*pi/180);
% subplot(2,1,1);
% plot(t,v);subplot(2,1,2);
% plot(t,i);

% t=0:pi/20:2*pi; [x,y]=meshgrid(t);
% subplot(2,2,1);
% plot(sin(t),cos(t))
% axis equal
% subplot(2,2,2)
% z=sin(x)+cos(y);
% plot(t,z)
% axis([0 2*pi -2 2])
% subplot(2,2,3)
% z= sin(x).*cos(y);
% plot(t,z)
% axis([0 2*pi -1 1])
% subplot(2,2,4)
% z=(sin(x).^2)-(cos(y).^2);
% plot(t,z)
% axis([0 2*pi -1 1])

% x=[1 2 3 4 5 6 7 8 9 10 11 12];
% y=[150 150 300 300 700 800 800 1000 1000 600 600 500];
% bar(x,y)

% x=[15000 35000 75000];
% pie(x)

% x=-2:0.5:2;
% y=-2:1:2;
% [X,Y]=meshgrid(x,y);
% Z=X.*exp(-X.^2-Y.^2);
% subplot(1,2,1);
% mesh(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh mesh');
% subplot(1,2,2)
% meshc(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh meshc');

% x=-2:0.5:2;
% y=-2:1:2;
% [X,Y]=meshgrid(x,y);
% Z=X.*exp(-X.^2-Y.^2);
% subplot(1,2,1);
% meshz(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh meshz');
% subplot(1,2,2)
% waterfall(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh waterfall');

% x=-2:0.5:2;
% y=-2:1:2;
% [X,Y]=meshgrid(x,y);
% Z=X.*exp(-X.^2-Y.^2);
% surf(X,Y,Z);
% colormap('cool');

% %bai1
% x=0:0.5:4;
% y1=x;
% subplot(2,2,1);
% plot(x,y1)
% y2=x.^3;
% subplot(2,2,2);
% plot(x,y2)
% y3=exp(x);
% subplot(2,2,3);
% plot(x,y3)
% y4=exp(x.^2);
% subplot(2,2,4);
% plot(x,y4,'-.b ^')

% %bai3
% x=-5:0.5:5;
% y=x/(1+x.^4);
% plot(x,y,'--ro','LineWidth', 6)

% %bai4
% x=-pi:pi/100:pi;
% plot(x,sin(x),x,cos(x),x,tan(x));   

%bai5
% x=-2:1/100:2
% y=x.^3-3*x
% plot(x,y)
% x1=1;
% y1=x1^3-3*x1;
% plot(x,y,x1,y1,'*');
% x2=-1;
% y2=x2^3-3*x2
% plot(x,y,x1,y1,'*',x2,y2,'*')
% hold on
% text(x1,y1,'cuc tieu')
% hold on
% text(x2,y2,'cuc dai')

%bai6
x=-10:0,2:10
y=abs(x.^2+3.*x)
z=x.^3-x-2
subplot(2,2,2)
plot(x,z)
title('x.^3-x-2');

v=x.^2
t=sqrt(x);
subplot(1,2,1)
plot(x,v)
title('x.^2');
subplot(1,2,2)
plot(x,t)
title('Sqrt(x)');
