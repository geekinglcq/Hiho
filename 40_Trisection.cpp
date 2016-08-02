#include<iostream> 
#include<cmath>
using namespace std;

double a,b,c,xx,yy;

double cal(double x){
	return sqrt((x-xx)*(x-xx)+pow(a*x*x+b*x+c-yy,2));	
}
double solve(double l, double r){
	
	while((r-l)>0.0005){
		double ml = l + (r-l)/3;
		double mr = r - (r-l)/3;
		
		if (cal(ml) > cal(mr))
			l = ml;
		else
			r = mr;		
		
	}
	std::cout.precision(3);
	cout.setf(std::ios::fixed);
	cout <<cal(l);
}
int main(){
	cin >> a >> b >> c >> xx >> yy;
	double left,right;
	
	if(a == 0){
		double ans = (b*xx-yy+c)/(b*b+1);
		std::cout.precision(3);
		cout.setf(std::ios::fixed);
		cout << ans;
		return 0;
	}
	if((xx + (b/(2*a))) < 0.00001){
		left = -500;
		right = 500;
	}
	if(xx > -(b/(2*a))){
		left = -(b/(2*a));
		right = xx*2  - left;
	}else if(xx < -(b/(2*a))){
		right = -(b/(2*a));
		left = xx*2 + (b/(2*a));
	}
	
	solve(left,right);
	return 0;
}
