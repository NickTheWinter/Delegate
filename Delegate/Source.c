#include "Header.h"
int n = 0;
int main()
{
	delegat d = calloc(n + 1, sizeof(f));

	AddFunc(d, Sum);
	AddFunc(d, Substract);
	AddFunc(d, Substract);
	AddFunc(d, Substract);
	AddFunc(d, Substract);
	AddFunc(d, Amp);
	AddFunc(d, Amp);
	AddFunc(d, Amp);

	ExecFuncs(d, 2, 2);

	RemoveFunc(d, Substract);
	ExecFuncs(d, 2, 2);

	RemoveRepeating(d);
	ExecFuncs(d, 2, 2);

	system("pause");
}
int Sum(int a, int b)
{
	return a + b;
}
int Substract(int a, int b)
{
	return a - b;
}
int Amp(int a, int b)
{
	return a * b;
}
void RemoveRepeating(delegat d)
{
	for (size_t i = 0; i <= n; i++)
	{
		if (d[i] == d[i + 1] || d[i] == d[i - 1])
		{
			ElemOffset(d, i);
		}
	}
}
void ElemOffset(delegat d, size_t i)
{
	for (size_t j = i; j < n - 1; j++)
	{
		d[j] = d[j + 1];
		d[j + 1] = NULL;
	}
	n--;
	d = (delegat)realloc(d, n * sizeof(f));
}
void RemoveFunc(delegat d, f func)
{
	for (size_t i = 0; i < n; i++)
	{
		if (d[i] == func)
		{
			ElemOffset(d, i);
			break;
		}
	}
}
void AddFunc(delegat d, f func)
{
	n++;
	d = (delegat)realloc(d, n * sizeof(f));
	d[n - 1] = func;
}
void ExecFuncs(delegat d, int a, int b)
{
	for (size_t i = 0; i < n; i++)
	{
		if (d[i] != NULL)
			printf("%d ", d[i](a, b));
	}
	printf("\n");
}