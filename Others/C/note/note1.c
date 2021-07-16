1.
int/0 >> 中止程序 
double/0 >> Inf(若分母为0) or NaN(若分母不为0)
		 >> %lf
2.11/3 = 3; -11/3 = -3
	so -11%3 = -2
3.~:Not ^:XOR
4.在引号中, "//"与"/n"均表示换行

5.
%c int/char as ASCII characters
%e double as decimal scientific notation 
%% one percent sign
%u unsigned int as decimal 
%x int as lower-case hexadecimal 
%X int as upper-case hexadecimal
6.scanf("%d=%d", &a, &b) 输入的格式必须为"n=m"
	(1)令a,b初值均为1, 若输入"2=3", 则a==2, b==3;
	若输入"2 =3", 则a==2, b==1
	(2)判断读取失败:if(n != scanf()){
		printf("Failed");
		return 3;
	}(n的值对应scanf所读取的数据个数)防止读取失败时，程序进入死循环
7.sqrt(double) sqrtf(float) sqrtl(long double)
8.IEEE 754
如果阶码0且尾数为0, 则该数真值为+-0(却决于符号位)
如果解码255且尾数为0, 则该数的真值为+=oo(却决于符号位)
9.AND: & OR: | NOT: ~ XOR: ^
10.对于一个变量A, 仅有4种表现形式: A, A', 1, 0
