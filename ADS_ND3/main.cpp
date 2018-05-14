#include <iostream>
#include <vector>

using namespace std;

void Swap(vector <int> &vect, int i, int j) {
	int temp = vect[j];
	vect[j] = vect[i];
	vect[i] = temp;
}

void QuickSort(vector <int> &vect, int begin, int end) {

	int i = begin;


	for (int a = begin; a < end; a++) {
		if (vect[a] < vect[end]) {// jeigu yra mazesnis, tada swapinam
			Swap(vect, a, i); // su keiciame vietomis
			i++;
		}
	}
	Swap(vect, i, end);

	if (i - 1 > begin) { //for cheking
		QuickSort(vect, begin, i - 1);
	}
	if (i < end - 1) {
		QuickSort(vect, i - 1, end);
	}
}


int main()
{
	vector <int> vect;
	int n, number;
	cin >> n;
	for (int a = 0; a < n; a++) {
		cin >> number;
		vect.push_back(number);
	}

	//QuickSort

	QuickSort(vect, 0, vect.size() - 1);



	for (int a = 0; a < vect.size(); a++) {
		cout << vect[a] << " ";
	}

	system("pause");
	return 0;
}