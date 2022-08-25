print("Hello... haizzz")
x = 5
print("x = ", x)
print(type(x))
x = 'teo'
print("x = ", x)
print(type(x))
x = True
print("x = ", x)
print(type(x))
x = 5.5
print("x = ", x)
print(type(x))
x = complex(113, 114)
print("x = ", x)
print(type(x))
"""
Toán tử số học cơ bản
và các phép toán cơ bản
"""
x = 5
y = 2
print("x = ", x, "và y = ", y)
print("x + y =", x + y)  # Cộng
print("x - y =", x - y)  # trừ
print("x * y =", x * y)  # Nhân
print("x / y =", x / y)  # Chia
print("x // y =", x // y)  # Lấy Phần Nguyên
print("x % y =", x % y)  # Lấy Phần Du
print("x ** y =", x ** y)  # Lũy Thùa

x = 5
y = 2
z = x
z += y  # Cộng và gán, tuơng tự ta có -=, *=, /=, //=, §=, **=
print("x = ", x, "y = ", y, "z = ", z)
sosanhl = z > x  # So sánh trả về kiểu bool là True và False
sosanh2 = z is x  # So sánh trả về kiểu bool là True và False
sosanh3 = z is not x  # So sánh trả về kiểu bool là True và False

sosanh4 = x % 2 == 30 and y % 2 != 0
print("z > x = ", sosanhl)
print("z = x = ", sosanh2)
print("z == x = ", sosanh3)
print("x%2==0 and y%2!=0 = ", sosanh4)
if (not x >= 5):
    print("Đúng x > 5")
else:
    print("x > 5 Sai")

x = "Nani"
print(x)
del x

# Nhap thong tin co ban
print(end="Mòi bạn nhập một số a:")
a = input()
print("Mời bạn nhập một số b", end=':')
b = int(input())
c = float(input("Mòi bạn nhập một số c:"))
print("*"*30)
print("Số bạn vùa nhập a = ", a)
print("Kiểu dữ liệu là : ", type(a))
print("Số bạn vùa nhập b = ", b)
print("Kiểu dữ liệu là : ", type(b))
print("Số bạn vùa nhập c = ", c)
print("Kiểu dữ liệu là : ", type(c))
print("*"*30)

# Nhap kieu boolean


def StrToBool(s):
    return s.lower() in ("yes", "true", "t", "1")
print("Mòi nhập bool:")
x = StrToBool(input())
print("Bạn nhập:", x)
print("Kiểu đữ liệu:", type(x))

'''
Đây là lệnh kiểm tra năm nhuận year
Năm nhuận là năm chia hết cho 4 nhưng không chia hết cho 100 hoặc chia hết cho 400
'''
year = int(input("Xin nhập năm để kiểm tra :"))
if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
    print(year, " là năm nhuận")
else:
    print(year, " không là năm nhuận")

"""
Giải phương trình bậc 1: ax+b=D0
Có 3 trường hợp để biện luận
Nếu hệ số a =0 và hệ số b=0 >vô số nghiệm
Nếu hệ số a =0 và hệ số b !=0 ==>vô nghiệm
Nếu hệ số a !=0 => có nghiệm -b/a
"""
a = int(input("Nhập a : "))
b = int(input("Nhập b : "))
if a == 0 and b == 0:
    print("Vô số nghiệm")
elif a == 0 and b != 0:
    print("Vô nghiệm")
else:
    print("Có No X=", -b/a)
