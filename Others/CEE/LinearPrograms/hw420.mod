# material(cement, sand, gravel) from supplier(a, b)
var ca >= 0;
var sa >= 0;
var ga >= 0;
var cb >= 0;
var sb >= 0;
var gb >= 0;

minimize total_cost:
	150*ca + 10*sa + 17*ga + 175*cb + 7*sb + 15*gb;

subject to cement:
	ca + cb >= 2;
subject to sand:
	sa + sb >= 5;
subject to gravel:
	ga + gb >=10;

subject to ca_supply:
	ca <= 3;
subject to sa_supply:
	sa <= 4;
subject to ga_supply:
	ga <= 4;
subject to cb_supply:
	cb <= 6;
subject to sb_supply:
	sb <= 5;
subject to gb_supply:
	gb <= 6;