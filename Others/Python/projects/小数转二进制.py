# -*- coding: utf-8 -*-
"""
Created on Tue Nov 20 14:02:39 2018

@author: lzk12
"""
'''
该函数可将float类型的十进制数字(负数也行)转化为二进制
(以字符串的形式输出)
x:需要转化的数字
request:小数点后保留的二进制位数
'''
def dec_bin(x, request):
    
    list_dec = [] #储存小数部分转化来的二进制
    boolen = 0 #储存x的正负性，正为0，负为1
    if x < 0:
        x = abs(x)
        boolen = 1
    
    if type(x) == int:
        if boolen == 1:
            return '-' + str(bin(x)) + '.' + '0'*request
        else:
            return str(bin(x)) + '.' + '0'*request
    
    if type(x) == float:
        x_int = int(x)
        x_dec = x - int(x)
        
        for step in range(request):
            x_dec = x_dec * 2
            if x_dec < 1:
                list_dec.append('0')
            else:
                x_dec = x_dec - 1
                list_dec.append('1')
                
        x_dec = ''.join(list_dec)
        if boolen == 1:
            return '-' + str(bin(x_int)) + '.' + x_dec
        else:
            return str(bin(x_int)) + '.' + x_dec
    
    else:
        return '请输入有效的数字'
#例子    
print(dec_bin(0.48779296875, 30))

    
                
            
        