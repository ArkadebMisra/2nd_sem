#include<stdio.h>
#include<string.h>
#include<math.h>
#define TOL 0.0001
#define PI 3.14159265
/*
double func(double x){
    return x*x-4;	
}
*/
/*
double func(double x){
	double xPx = pow(x, x);
	return xPx + 2*x - 6;
	
}
*/



double func(double x){
   double ret, val;

   //val = PI / 180;
   ret = sin(x);
   
   return pow(10, x) + ret + 2*x;
	
}


void bisection(double a , double b){
	printf("Initial guess is a= %lf b = %lf\n", a, b);
	if (func(a)*func(b)>0){
		printf("you have assume wrong intervals");
		return;
	}
	double c = a;
	while ((b-a)>=TOL){
		c = a+(b-a)/2;
		printf("a =%lf b=%lf c=%lf\n", a, b, c);
		if (func(c) == 0.0){
			break;
		}
		else if ((func(c)*func(a))<0){
			b = c;		
		}
		else{
			a = c;
		}
	}
	printf("the value of root is %.3lf\n", c);
}

int main() 
{ 
    double a='\0', b='\0';
    double i = -100.0;
    while(a == '\0' || b=='\0'){
    	if (func(i)<0){
    		a  = i;
		}
		if(func(i)>0){
			b = i;
		}
		i+= 0.01;
	}
    bisection(a, b); 
    return 0; 
} 

