#include <iostream>
#include <vector>
#include <fstream>

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
			Swap(vect, a, i); // su keiciame vietomis ok
			i++;
		}
	}
	Swap(vect, i, end);

	/*for (int a = 0; a < vect.size(); a++) {
	cout << vect[a] << " ";
	}
	cout << endl;*/


	if (i - 1 > begin) { //for cheking
		QuickSort(vect, begin, i - 1);
	}
	if (i < end - 1) { //pakeista is -1 i -2
		QuickSort(vect, i + 1, end); //pakeista is -1 i +1
	}
}


int main()
{
	vector <int> vect;
	int number;
	ifstream input;
	input.open("input.txt");

	while (input >> number) {
		vect.push_back(number);
	}

	input.close();

	//QuickSort

	QuickSort(vect, 0, vect.size() - 1);



	for (int a = 0; a < vect.size(); a++) {
		cout << vect[a] << " ";
	}

	//system("pause");
	return 0;
}