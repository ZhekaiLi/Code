'''
该函数既可以用于取质数，稍作修改后亦可求出所给范围内每一个数字的因数个数
'''
#求质数 Vol.1
'''
def prime_number_1(a, b):
    list1 = []
    for i in range(a, b+1):
        j = 0
        if i == 1 or i == 0:
            continue
        elif i == 2:
            list1.append(2)
        else:
            for k in range(2, i):
                if i % k == 0:
                    j += 1 
            if j == 0:
                list1.append(a+i)
    return list1
print(prime_number_1(0, 200))
'''

                    


    
import numpy as np
a = np.isclose(1,3)
print(a)