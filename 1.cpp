#include <iostream>
#include <fstream>
using namespace std;

void ReadFile(double*&, double*&, int&);//Read file
double in(double*, double*, bool*, int);//Profit from the sale of bamboo
double Greedy(double*, double*, int);//Greedy algorithm
int DayMaxPriceAfter(double*, int, int);//The highest price after k-day

void ReadFile(double *&Price, double *&Growth, int &n) {
	ifstream in("input.txt");
	if (!in) { cout << "There is no input data file!\n"; exit(0); }
	in >> n;
	Price = new double[n];
	Growth = new double[n];
	for (int i = 0; i < n; i++)
		in >> Price[i] >> Growth[i];
	in.close();
}

double in(double *Price, double *Growth, bool *x, int n) {
	double s = 0, S = 0;
	for (int i = 0; i < n; i++) {
		if (!x[i]) s = s + Growth[i];
		else {
			S = S + (s + Growth[i])*Price[i];
			s = 0;
		}
	}
	return S;
}

int DayMaxPriceAfter(double *Price, int n, int k) {
	double max = Price[k]; int maxk = k;
	for (int i = k + 1; i < n; i++)
		if (Price[i] >= max) {
			max = Price[i];
			maxk = i;
		}
	return maxk;
}


double Greedy(double *Price, double *Growth, int n) {
	bool *x = new bool[n];
	memset(x, 0, sizeof(bool)*n);
	int k = -1;
	while (k < n - 1) {
		k = DayMaxPriceAfter(Price, n, k + 1);
		cout << k << endl;
		x[k] = true;
	}
	return in(Price, Growth, x, n);
}

int main() {
	int n;
	double *Price, *Growth;
	double w;
	ReadFile(Price, Growth, n);
	w = Greedy(Price, Growth, n);
	cout << w << endl;
	system("pause");
}
