#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream File("input.txt");
	ofstream FileOut("output.txt");

	vector <int> a;
	int n;
	File >> n;
	while (!File.eof())
	{
		int x;
		File >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int sum = 0, max = 0, i = 0, j = 1;
	while (j < a.size())
	{
		sum = 0;
		for (int k = i; k < j; k++)
			sum += a.at(k);
		if (a.at(j) <= (a.at(i) + a.at(i + 1)))
		{
			sum += a.at(j);
			j++;
			if (sum > max)
				max = sum;
		}
		else
		{
			sum -= a.at(i);
			i++;
			if (sum > max)
				max = sum;
		}
	}
	FileOut << max;

	return 0;
}