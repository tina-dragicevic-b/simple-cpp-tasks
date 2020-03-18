#include <iostream>
#include <array>
#include <math.h>

//2.Definirati strukturukruznicai strukturupravokutnik. 
//Napisati funkcijukoja prima niz pravokutnika i jednu kruznicu i 
//vraća broj pravokutnika kojisijeku kružnicu. Niz pravokutnika i kružnica 
//šalju se u funkciju pomoćuconstreferenci

#include <iostream>
#include<math.h>
#include<cmath>


struct kruznica
{
	float r = 0;
	float s[2];

};

int compare(const kruznica a, const kruznica* arr_)
{
	float sx = 0;
	float sy = 0;
	float d = 0;
	int intersect = 0;
	float big_r = 0;
	float small_r = 0;
	for (int i = 0; i < 2; i++)
	{
		sx = abs(abs(a.s[0]) - abs(arr_[i].s[0]));
		sy = abs(abs(a.s[1]) - abs(arr_[i].s[1]));
		d = sqrt((sx * sx) + (sy * sy));

		if (a.r >= arr_[i].r)
		{
			big_r = a.r;
			small_r = arr_[i].r;
		}
		else
		{
			big_r = arr_[i].r;
			small_r = a.r;
		}

		if (d == a.r + arr_[i].r || d == abs(a.r - arr_[i].r))
		{
			std::cout << "Kruznice se dodiruju u jednoj tocki\n";
			intersect++;
		}
		else if (abs(a.r - arr_[i].r) < d && a.r + arr_[i].r > d)
		{
			std::cout << "Kruznice se sijeku\n";
			intersect++;
		}
		else if (d == big_r)
		{
			std::cout << "Kruznice se sijeku\n srediste male kruznice je na velikoj kruznici\n";
			intersect++;
		}
		else if (d <= small_r)
		{
			std::cout << "Kruznice se NE sijeku\n srediste male kruznice je unnutar velike kruznici\n";
		}
		else{std::cout << "Kruznice se ne sijeku" << std::endl;}
        std::cout  << i << " ";


	}
	return intersect;
}

int main()
{
	kruznica a;
	kruznica arr_[2];


	a.r = 2;
	a.s[0] = 0;
	a.s[1] = 0;

	arr_[0].r = 3;
	arr_[0].s[0] = 3;
	arr_[0].s[1] = 0;

	arr_[1].r = 3;
	arr_[1].s[0] = 5;
	arr_[1].s[1] = 5;

	std::cout << "Broj kruznica koje se sijeku: "<< compare(a, arr_) << std::endl;
    return 0;
}



