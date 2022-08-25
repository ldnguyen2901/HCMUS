function [X] = tamgiacvuong(X0,a,b)

B(1) = X0(1);
B(2) = X0(2) + a;

C(1) = X0(1) + b;
C(2) = X0(2);

plot([X0(1) B(1)], [ X0(2) B(2)],'r', ...
    [X0(1) C(1)], [ X0(2) C(2)], 'r',...
    [B(1) C(1)], [ B(2) C(2)], 'r')
hold on
text(X0(1)-0.2,X0(2),'A')
text(B(1)-0.2,B(2),'B')
text(C(1)+0.2,C(2),'C')

axis([-4 3 -4 3])
