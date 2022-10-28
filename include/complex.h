#pragma once

#include <stdio.h>
#include "math.h"
#include <math.h>

struct complex{
	float a, b;
	float argument, module;
};

inline void convert_to_polar(complex* Z){
	Z->argument = atanf(Z->b/Z->a);
	Z->module   = sqrtf(Z->a * Z->a + Z->b * Z->b);
}

inline void convert_to_rectangular(complex* Z){
	Z->a = Z->module * cosf(Z->argument);
	Z->b = Z->module * sinf(Z->argument);
}

inline complex add_rectangular(complex* x, complex* y){
	complex result;
	
	result.a = x->a + y->a;
	result.b = x->b + y->b;
	
	return result;
}

inline complex add_polar(complex* x, complex* y){
	complex result;

	convert_to_rectangular(x);
	convert_to_rectangular(y);

	result = add_rectangular(x, y);
	convert_to_polar(&result);

	return result;
}

inline complex multiplicate_polar(complex* x, complex* y){
	complex result;
	
	result.argument = x->argument + y->argument;
	result.module   = x->module   * x->module;

	return result;
}

inline complex multiplicate_rectangular(complex *x, complex *y){
	complex result;

	result.a = ( x->a * y->a ) - ( x->b * y->b );
	result.b = ( x->a * y->b ) + ( x->b * y->a );

	return result;
}

inline complex divide_polar(complex* x, complex* y){
	complex result;
	
	result.argument = x->argument - y->argument;
	result.module   = x->module   / x->module;

	return result;
}

inline complex divide_rectangular(complex *x, complex *y){
	complex result;

	convert_to_polar(x);
	convert_to_polar(y);

	result = divide_polar(x, y);
	convert_to_rectangular(&result);

	return result;
}

inline void print_rectangular(complex* Z){
	printf("(%f + %fj)", Z->a, Z->b);
}

inline void print_polar(complex* Z){
	printf("(%f x cos(%f) + %fj x sin(%f))", Z->module, Z->argument, Z->module, Z->argument);
}


