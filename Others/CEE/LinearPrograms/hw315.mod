# cost needed to transfer a unit mass of rubbish
param cost = 1;

# rubbish transformed from city(a, b, c, d) to landfill(1, 2, 3) through transition(1, 2)
var a11 >= 0; var a12 >= 0; var a13 >= 0; var a21 >= 0; var a22 >= 0; var a23 >= 0;
var b11 >= 0; var b12 >= 0; var b13 >= 0; var b21 >= 0; var b22 >= 0; var b23 >= 0;
var c11 >= 0; var c12 >= 0; var c13 >= 0; var c21 >= 0; var c22 >= 0; var c23 >= 0;
var d11 >= 0; var d12 >= 0; var d13 >= 0; var d21 >= 0; var d22 >= 0; var d23 >= 0;
subject to a_total: a11 + a12 + a13 + a21 + a22 + a23 = 205;
subject to b_total: b11 + b12 + b13 + b21 + b22 + b23 = 369;
subject to c_total: c11 + c12 + c13 + c21 + c22 + c23 = 340;
subject to d_total: d11 + d12 + d13 + d21 + d22 + d23 = 408;

var costa = a11*(45+157/2) + a12*(45+234/2) + a13*(45+146/2) + a21*(58+175/2) + a22*(58+136/2) + a23*(58+192/2);
var costb = b11*(39+157/2) + b12*(39+234/2) + b13*(39+146/2) + b21*(79+175/2) + b22*(79+136/2) + b23*(79+192/2);
var costc = c11*(74+157/2) + c12*(74+234/2) + c13*(74+146/2) + c21*(93+175/2) + c22*(93+136/2) + c23*(93+192/2);
var costd = d11*(25+157/2) + d12*(25+234/2) + d13*(25+146/2) + d21*(44+175/2) + d22*(44+136/2) + d23*(44+192/2);

minimize total_cost:
	costa + costb + costc + costd;
subject to capacityOfLandfill1:
	a11 + a21 + b11 + b21 + c11 + c21 + d11 + d21 <= 500;
subject to capacityOfLandfill2:
	a12 + a22 + b12 + b22 + c12 + c22 + d12 + d22 <= 420;
subject to capacityOfLandfill3:
	a13 + a23 + b13 + b23 + c13 + c23 + d13 + d23 <= 600;
subject to capacityOfTransition1:
	a11 + a12 + a13 + b11 + b12 + b13 + c11 + c12 + c13 + d11 + d12 + d13 <= 700;
subject to capacityOfTransition2:
	a21 + a22 + a23 + b21 + b22 + b23 + c21 + c22 + c23 + d21 + d22 + d23 <= 700;


