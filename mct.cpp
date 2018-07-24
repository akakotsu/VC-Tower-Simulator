#include<iostream>
#include<random>

using namespace std;

double random(int min, int max)
{
	random_device rd;
	mt19937 gn(rd());
	uniform_real_distribution<double> dis(min, max);
	return dis(gn);
}


int main()
{
	int n = 10000;
	vector<int> floors(n,0);
	int c = 4;
	double Prb = 0.35;
	int num1,num2,num3;

	for (int i = 0; i < n; i++)
	{
		int runes = 0;
		int count = 5 * c;
		int rt = 0;
		while (count >= 0)
		{
			count -= 1;
			if (rt > 0) { num1 = 10; rt -= 1; }
			else num1 = 1;
			floors[i] += 20 * (19*num1 + floor(random(0, 1+2*num1)));
			//cout << floors[i] << endl;
			if (Prb > random(0, 1))
			{
				count -= 1;
				if (0.5 < random(0, 1))
				{
					if (rt > 0) { num2 = 16; rt -= -1; }
					else { num2 = 3; runes += floor(random(1, 3)); }
					floors[i] += 20 * (19*num2 + floor(random(0, 1+2*num2)));
				}
				else
				{
					if (rt > 0) { num3 = 16; rt -= -1; }
					else { num3 = 3; runes += 2; }
					floors[i] += 20 *(23*num3+ floor(random(0, 1+2*num3)));
				}
				if (runes > 4) { rt = 15; runes = 0; }
				//cout << floors[i] << "|" << runes << endl;
			}
			
		}
		//std::cout << floors[i] << endl;

	}
	int TF = 0;
	for (auto &i : floors) TF += i;
	std::cout << TF / double(c*n) << endl;
	return 0;
}