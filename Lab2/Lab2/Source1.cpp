#include <iostream>
using namespace std;

int main(void) {
	int tab[80];
	int* p;
	for (i = 0; i < 80; i++)tab[i] = i * i;
	tab[2] = tab[1];
	tab[2] = *(tab + 1);
	*(tab + 2) = tab[1];
	*(tab + 2) = *(tab[1]);
	p = &tab[0];
	p = tab + 1;
	tab[4] = *p;
}