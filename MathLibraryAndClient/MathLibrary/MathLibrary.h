#pragma once
#ifdef MATHLIBRARY_EXPORTS  
#define MATHLIBRARY_API extern "C" __declspec(dllexport)   
#else  
#define MATHLIBRARY_API extern "C" __declspec(dllimport)   
#endif  

MATHLIBRARY_API double Add(double a, double b);

// Returns a * b  
MATHLIBRARY_API double Multiply(double a, double b);

// Returns a + (a * b)  
MATHLIBRARY_API double AddMultiply(double a, double b);