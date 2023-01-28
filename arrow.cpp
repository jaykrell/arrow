// operator-> is applied recursively by the language
//
// This can be useful when operator-> returns something
// that needs to be cleaned up. A temporary.
// This sample does not show that application, just
// that operator-> "automatically recurses".

#include <stdio.h>

struct X
{
void f1() { printf("X::f1\n"); }
};

X x, *px = &x;

struct A { X* operator-> () { printf("A\n"); return px; } };
struct B { A operator-> () { printf("B\n"); return A(); } };

int main()
{
  B b;
  b->f1();
}
