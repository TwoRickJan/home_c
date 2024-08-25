#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include "numeric.h"



float calcIntegral(float a, float b, function f, float eps,unsigned int *i)
{
    size_t n = 1000;
    float sumi1 = calcIntegralSimpson(a,b,n,f);
    float sumi = 0;
    while(fabs(sumi-sumi1) > eps)
    {
        sumi = sumi1;
        n+=1000;
        sumi1 = calcIntegralSimpson(a,b,n,f);
        (*i)++;
    }
    return sumi;
}
float calcIntegralSimpson(float a, float b, size_t n, function f) 
{
	float sum = 0;
	float h = (b-a)/n;
	
	for(float x=a+h; x<b-h; x+=h) {
		sum += h/6.0*(f(x) + 4.0*f(0.5*(x+x+h)) + f(x+h));
	}
	return sum;
}

float rootFindCombine(float a, float b, float eps, function f,function g, function df,function dg,function ddf,function ddg,unsigned int *i)
{
	//*i = 0;
	while(fabs(a-b) > 2*eps) {
		if( (f(a)-g(a))*(ddf(a)-ddg(a))<0 )
			a = a - ((f(a)-g(a))*(a - b))/((f(a)-g(a)) - (f(b)-g(b)));
		else
			a = a - (f(a)-g(a))/(df(a)-dg(a));
		if( (f(b)-g(b))*(ddf(b)-ddg(b))<0 )
			b = b - ((f(b)-g(b))*(b - a))/((f(b)-g(b)) - (f(a)-g(a)));
		else
			b = b - (f(b)-g(b))/(df(b)-dg(b));
			
		(*i)++;

	}
	return (a+b)/2;

}
// function f0 - 0
float f0(float x) {
	return  0;
}

float df0(float x) {
	return 0;
}

float ddf0(float x) {
	return 0;
}


// function f - 1
float f(float x) {
	return  0.6*x + 3;
}

float df(float x) {
	return 0.6;
}

float ddf(float x) {
	return 0;
}


// function g - 1
float g(float x) {
	return  (x-2)*(x-2)*(x-2)-1;
}
float dg(float x) {
	return 3*(x-2)*(x-2);
}

float ddg(float x) {
	return 6*(x-2);
}


// function u - 1
float u(float x) {
	return  3/x;
}

float du(float x) {
	return -3/(x*x);
}

float ddu(float x) {
	return 6/(x*x*x);
}


