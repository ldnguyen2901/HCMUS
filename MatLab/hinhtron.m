function [X] = hinhtron(o, r)

% a = o(1);
% b = o(2);
% x = a-r:0.1:a+r;
% y1 = b + sqrt(r^2 - (x-a).^2);
% y2 = b - sqrt(r^2 - (x-a).^2);
% 
% plot(x,y1,'r',x,y2,'r')
% axis equal

 a = o(1);
 b = o(2);
 
 t= -pi:0.01:pi+0.1;
 x = a + r*cos(t);
 y = b + r*sin(t);
 plot(x,y,'r')
 title('Ve Hinh Tron')
 axis equal
