#include <iostream>
#include "import.h"

struct data
{
	double l1, l2, l3, w;
	double Sb[13], Vb[13], ab[13];
	double o_2, h;
}in_data;

int main()
{
	in_data.l1 = -0,010;
	in_data.l2 = 0.045;
	in_data.l3 = 0.200;
	in_data.w = 4.090;
	calculation(&in_data);

	for (int i = 0; i <= 12; ++i)
	{
		//std::cout << i <<"   " << in_data.Sb[i] << "   " << in_data.Vb[i] << "   " << in_data.ab[i] << std::endl;
		printf("%3.1d\t%8.5f\t%8.5f\t%8.5f\n", i, in_data.Sb[i], in_data.Vb[i], in_data.ab[i]);
	}
	printf("%8.5f\t%8.5f\n", in_data.o_2, in_data.h);
	return 0;
}