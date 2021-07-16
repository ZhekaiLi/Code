'''
Name: Tansition02(value list -> kmap)
Vertion: 1.0
Author: Li
Function: (1)将输入的真值表转化成表达式输出
          (2)针对FSM问题，每组abc都对应d=1&d=0两种情况
'''
#body
def main():
    # initial the value of kmap and positions
    kmap = [[5,5,5,5],
           [5,5,5,5],
           [5,5,5,5],
           [5,5,5,5]]
    # ab lines, cd lists
    a = [0,0,0,1,1,1]
    b = [0,1,0,0,0,1]
    c = [0,1,1,1,0,1]
    d1 = [0] * len(a)
    d2 = [1] * len(a)
    # values come from abcd
    value1 = [0,1,1,0,0,0]
    value2 = [0,0,0,1,0,0]

    for i in range(len(value1)):
        px = pfind(a[i], b[i])
        py = pfind(c[i], d1[i])
        kmap[px][py] = value1[i]
        
    for i in range(len(value2)):
        px = pfind(a[i], b[i])
        py = pfind(c[i], d2[i])
        kmap[px][py] = value2[i]       


    print(kmap)

#find the position in one direction
def pfind(p1, p2):
    if p1==0 and p2==0:
        p = 0
    elif p1==0 and p2==1:
        p = 1
    elif p1==1 and p2==1:
        p = 2
    else:
        p = 3
    return p


if __name__ == '__main__':
    main()