
#include "std_lib_facilities.h"

// compute mean and median temperature
int main()
{
	vector<double> temps;
	for (double temp; cin >> temp;)
	{
		temps.push_back(temp);
	}
	// compute mean temperature
	double sum = 0;
	for (int x : temps)
		sum += x;
	cout << "Average temparateure: " << sum / temps.size() << "\n";
	// compute median temperature
	sort(temps);
	cout << "Median temprature: " << temps[temps.size() / 2] << "\n";
}