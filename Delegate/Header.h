#pragma once
#include <stdio.h>
#include <stdlib.h>
int Sum(int, int);
int Substract(int, int);
int Amp(int, int);
typedef int (*f) (int, int);
typedef f* delegat;
void RemoveFunc(delegat, f);
void AddFunc(delegat, f);
void ExecFuncs(delegat, int, int);
void RemoveRepeating(delegat d);
void ElemOffset(delegat d, size_t i);