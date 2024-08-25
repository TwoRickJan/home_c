typedef float(*function)(float);
/**/
float f0(float x);
float df0(float x);
float ddf0(float x);
/**/
float f(float x);
float df(float x);
float ddf(float x);
/**/
float g(float x);
float dg(float x);
float ddg(float x);
/**/
float u(float x);
float du(float x);
float ddu(float x);


float calcIntegralSimpson(float a, float b, size_t n, function f);
float rootFindCombine(float a, float b, float eps, function f,function g, function df,function dg,function ddf,function ddg,unsigned int *i);
float initial_guesses();
float calcIntegral(float a, float b, function f, float eps,unsigned int *i);
