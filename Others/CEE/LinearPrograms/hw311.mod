var x1 >= 0;
var x2 >= 0;

minimize total:
	10*x1 + 4*x2;
subject to condi1:
	5*x1 - 6*x2 <= 30;
subject to condi2:
	5*x1 + 2*x2 >= 30;
subject to x1a:
	x1 >= 5;
subject to x2a:
	x2 >= 2;