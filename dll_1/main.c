#include <math.h>
#include "export.h"

#define M_PI acos(-1.0)

extern struct data
{
	double l1, l2, l3, w;
	double Sb[13], Vb[13], ab[13];
	double o_2, h;
}in_data;

int calculation(struct data* p)
{
	double fi_2_0, x_b_0, fi_2, fi_3, x_b, fi_hatch_32, x_hatch_b_2, fi_2_hatch_32, x_2_hatch_b_2, fi_3_k, fi_2_k, x_b_k;
	fi_2_0 = asin(p->l1 / (p->l2 + p->l3)); // 3.1
	x_b_0 = (p->l2 + p->l3) * cos(fi_2_0); // 3.2
	//printf("out_l1 = %5.3f\t out_l2 = % 5.3f\t out_l3 = %5.3f\t out_lw = %5.3f\n", p->l1, p->l2, p->l3, p->w);
	for (int i = 0; i <= 12; ++i)
	{
		fi_2 = fi_2_0 + ((M_PI * p->w * i) / (6 * fabs(p->w))); //3.3
		fi_3 = asin(((p->l1 - (p->l2 * sin(fi_2))) / p->l3)); // 3.4
		x_b = (p->l2 * cos(fi_2)) + (p->l3 * cos(fi_3)); // 3.5
		p->Sb[i] = x_b - x_b_0; // 3.6
		fi_hatch_32 = (-p->l2 * cos(fi_2)) / (p->l3 * cos(fi_3)); // 3.7
		x_hatch_b_2 = (-p->l2 * sin(fi_2)) - (p->l3 * fi_hatch_32 * sin(fi_3)); // 3.8
		p->Vb[i] = x_hatch_b_2 * p->w; // 3.9
		fi_2_hatch_32 = ((p->l2 / p->l3) * (sin(fi_2) / cos(fi_3))) + ((pow(fi_hatch_32, 2)) * (sin(fi_3) / cos(fi_3))); // 3.10
		x_2_hatch_b_2 = ((-p->l2) * cos(fi_2)) - (p->l3 * ((fi_2_hatch_32 * sin(fi_3)) + (pow(fi_hatch_32, 2) * cos(fi_3)))); // 3.11
		p->ab[i] = x_2_hatch_b_2 * (pow(p->w, 2)); // 3.12
		//printf("%3.1d\t%8.5f\t%8.5f\t%8.5f\n", i, p->Sb[i], p->Vb[i], p->ab[i]);
	}
	fi_3_k = asin(p->l1 / (p->l3 - p->l2)); // 3.13
	fi_2_k = fi_3_k + (M_PI * (p->w / fabs(p->w))); // 3.14
	p->o_2 = fi_2_k - fi_2_0;  // 3.15
	x_b_k = (p->l3 - p->l2) * cos(fi_3_k); // 3.16
	p->h = x_b_k - x_b_0; // 3.16
	//printf("%8.5f\t%8.5f\n", p->o_2, p->h);
	return 0;
}