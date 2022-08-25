import math
import numpy
import pandas
# # yêu cầu 1:
# a = int(input("Nhập a : "))
# b = int(input("Nhập b : "))
# c = int(input("Nhập c : "))
# answer = input("người dùng muốn giải phương trình bậc hai hay không?\n")
# if (answer == '0' or answer == 'no'):
#     print("Have a nice day. BB")
# elif (answer == '1' or answer == 'yes'):
#     if (a == 0):
#         if b == 0 and c == 0:
#             print("Vô số nghiệm")
#         elif b == 0 and c != 0:
#             print("Vô nghiệm")
#         else:
#             print("Có Nghiệm X = ", -c/b)
#     elif(a != 0):
#         delta = b**2-4*a*c
#         print("Delta = ", delta)
#         if(delta < 0):
#             print("Phương trình vô nghiệm")
#         elif(delta == 0):
#             print("Phương trình có nghiệm kép là ", -b/(2*a))
#         elif(delta > 0):
#             print("Phương trình có 2 nghiệm phân biệt")
#             print("x1 = ", (-b+math.sqrt(delta))/(2*a))
#             print("x2 = ", (-b-math.sqrt(delta))/(2*a))
# else:
#     print("Error input")

#yêu cầu 2:
a = float(input("Nhập a : "))
b = float(input("Nhập b : "))
c = float(input("Nhập c : "))
d = float(input("Nhập d : "))
e = float(input("Nhập e : "))
f = float(input("Nhập f : "))
g = float(input("Nhập g : "))
h = float(input("Nhập h : "))
i = float(input("Nhập i : "))
j = float(input("Nhập j : "))
k = float(input("Nhập k : "))
l = float(input("Nhập l : "))
print(str(a)+'x + '+str(b)+'y + '+str(c)+'z = '+str(d))
print(str(e)+'x + '+str(f)+'y + '+str(g)+'z = '+str(h))
print(str(i)+'x + '+str(j)+'y + '+str(k)+'z = '+str(l))


A = numpy.array([[a, b, c], [e, f, g], [i, j, k]])
B = numpy.array([d, h, l])
det = (a*f*k)+(b*g*i)+(c*e*j)-(i*f*c)-(j*g*a)-(k*e*b)

print("\ndet (theo hàm có sẵn) = ", round(numpy.linalg.det(A)))
print("det (Code thủ công) = ", det)
M1 = numpy.array([[d, b, c], [h, f, g], [l, j, k]])
M2 = numpy.array([[a, d, c], [e, h, g], [i, l, k]])
M3 = numpy.array([[a, b, d], [e, f, h], [i, j, l]])

Dx = round(numpy.linalg.det(M1))
Dy = round(numpy.linalg.det(M2))
Dz = round(numpy.linalg.det(M3))

print("Dx = ", Dx)
print("Dy = ", Dy)
print("Dz = ", Dz)

if(det != 0):
    C = numpy.linalg.solve(A, B)  # Tính ra nghiệm
    print("Nghiệm là: ", C)
else:
    if(Dx == 0 and Dy == 0 and Dz == 0):
        print("Vô số nghiệm")
    if(Dx != 0 or Dy != 0 or Dz != 0):
        print("Vô nghiệm")

print("\nHạng của matrix = ", numpy.linalg.matrix_rank(A))
