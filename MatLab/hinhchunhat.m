function [x] = hinhchunhat(X0, dai, rong)

B(1) = X0(1);
B(2) = X0(2) - dai;

D(1) = X0(1) - rong;
D(2) = X0(2);

C(1) = X0(1) - rong;
C(2) = X0(2)- dai;

plot([X0(1) B(1)], [ X0(2) B(2)],'r', ...
    [X0(1) D(1)], [ X0(2) D(2)], 'r',...
    [B(1) C(1)], [ B(2) C(2)], 'r',...
    [D(1) C(1)], [ D(2) C(2)], 'r')
hold on
text(X0(1)-0.2,X0(2),'A')
text(B(1)-0.2,B(2),'B')
text(C(1)+0.2,C(2),'C')
text(D(1)+0.2,D(2),'D')

axis([-8 -2 -8 -2])

