clc
close all
clear
% %bai 7
% %a
% x = -2:0.2:2;
% y = -2:0.2:2;
% [X,Y] = meshgrid(x,y);
% Z = 3*X - X^3 - 2*Y^2 + Y^4;
% subplot(1,2,1);
% mesh(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh mesh')
% subplot(1,2,2);
% surf(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh surf')
% 
% %b
% x = -2:0.2:2;
% y = -2:0.2:2;
% [X,Y] = meshgrid(x,y);
% Z = sin(pi*X) + sin(pi*Y) + sin((pi*X + pi*Y));
% subplot(1,2,1);
% mesh(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh mesh')
% subplot(1,2,2);
% surf(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh surf')
% 
% %c
% x = -2:0.2:2;
% y = -2:0.2:2;
% [X,Y] = meshgrid(x,y);
% Z = exp(X) + Y.^4 - X.^3 + 4 * cos(pi * Y);
% subplot(1,2,1);
% mesh(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh mesh')
% subplot(1,2,2);
% surf(X,Y,Z)
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat voi lenh surf')

% %bai 8
% x = -3:0.1:3;
% y = -3:0.1:3;
% [X,Y] = meshgrid(x,y);
% Z1 = exp(-X.^2);
% Z2 = exp(-(X.^2+Y.^2));
% subplot(1,2,1);
% surf(X,Y,Z1);
% % hold on;
% % surf(X,Y,Z2);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat f(x,y) = exp(-x^2) voi lenh Surf')
% % hold on;
% subplot(1,2,2);
% surf(X,Y,Z2);
% xlabel('x');
% ylabel('y');
% zlabel('z');
% title('Ve mat f(x,y) = exp(-(x^2+y^2)) voi lenh Surf')

% %bai 9
% A=[-3 -3];
% a = 5;
% b = 4;
% tamgiacvuong(A,a,b )

% %bai 10
% A=[-3 -3];
% a = 5;
% b = 4;
% hinhchunhat(A,a,b )

% %bai 11
% r=4;
% o=[0 0];
% hinhtron(o,r)

%bai 14
%a
% x=-5:0.01:5;
% y=x./(3 + x.^4);
% plot(x,y,'-. r','LineWidth',2)

%b
x = -2*pi:0.01:2*pi;
y1=sin(x);
y2=cos(x + pi/2);
y3=tan(x-pi);
plot(x,y1,'r',x,y2,'y',x,y3,'g');
xlabel('x');
ylabel('y');
legend('sin(x)','cos*x+pi/2','tan(x-pi)')
title('ve do thi ham so');