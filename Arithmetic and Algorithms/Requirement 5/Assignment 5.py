import imp
from typing import Counter, MutableSequence
from sympy import frac
import sys

class Fraction:
    def __init__(self,tu = 1,mau = 1):
        self.tu = tu
        self.mau = mau

    def setPS(self,tu,mau = 1):
        self.tu = tu
        self.mau = mau

    def output(self):
        if(self.mau != 1):
            file_output.write('%s/%s'% (self.tu,self.mau))
        else:
            file_output.write('%s'% (self.tu))
    def daops(self):
        temp = self.tu
        self.tu = self.mau
        self.mau = temp

file_input = open ("D:\HCMUS\Computer Science\Số học và thuật toán\Requirement 5\input.txt","r")
file_output = open ("D:\HCMUS\Computer Science\Số học và thuật toán\Requirement 5\output.txt","w+")

# tu = int(input("Nhap tu: "))
# mau = int(input("Nhap mau: "))
# ps = Fraction(tu,mau)
# ps.output()
# n = int(input("Nhap so lan thuong so: "))
count_x=1
count_intput = 0
for line in file_input:
    if(count_intput % 2 == 0):
        p = int(line)
        count_intput+=1

    else:
        n = int(line)
        count_intput+=1
        break

ml = [Fraction() for i in range(p)]
for obj in ml:
    for line in file_input:
        if(count_intput % 2 == 0):
            obj.tu = int(line)
            # file_output.write("test: ",obj.tu)
            count_intput+=1
        else:
            obj.mau = int(line)
            # file_output.write("test: ",obj.mau)
            count_intput+=1
            break
        
    x = 1
    first = 1
    file_output.write('x%s'%(count_x) )
    file_output.write('=')
    obj.output()
    file_output.write('=[')
    for i in range(0,n+1):
        temp_tu = obj.tu
        temp_mau = obj.mau
        i = obj.tu//obj.mau #2 3 
        check = obj.tu - i * obj.mau 
        if(check != 0):
            obj.tu -= i * obj.mau # tu = tu - i*mau (7-2*3) (3-3*1)
            if(first == 1):
                file_output.write('%s;'%(i))
                first+=1
            else:
                file_output.write('%s,'%(i))
                

        else:
            i-=1
            obj.mau = 1
            obj.tu = 1
            if(x==n+1):
                file_output.write('%s]\n'%(i+1))
            else:
                file_output.write('%s,'%(i))
        # obj.output() #1/3 0...?
        obj.daops() 
        # obj.output() #3/1
        x+=1
    count_x+=1

# for line in file_input:
#         aa=line
#         file_output.write(aa)
#         file_output.write(aa)



file_input.close()
file_output.close()