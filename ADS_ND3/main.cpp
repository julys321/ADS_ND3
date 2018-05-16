#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
//#include <ctime>

using namespace std;

void Reverse(vector <int> &vect) {
	reverse(vect.begin(), vect.end());
}


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

	/*for (int a = 0; a < vect.size(); a++) { //test
	cout << vect[a] << " ";
	}
	cout << endl;*/

	if (i - 1 > begin) { //for cheking
		QuickSort(vect, begin, i - 1);
	}
	if (i < end - 1) {
		QuickSort(vect, i + 1, end);
	}
}


bool isCorrect(vector <int> inputData, vector <int> outputData, int type) { //tiesiog checkinimas
	sort(inputData.begin(), inputData.end());
	if (type == 1) {
		Reverse(inputData);
	}

	if (inputData == outputData) {
		return true;
	}
	else return false;
}


int main() {
	clock_t time;
	int number, type;
	bool isRunning = true;
	vector <int> inputData, outputData;

	ifstream input;
	input.open("input.txt");

	while (input >> number) {
		inputData.push_back(number);
	}

	input.close();

	while (isRunning) {
		cout << "Ka norite atlitki?" << endl;
		cout << "0 - Surusiuoti skaiciu seka nuo maziausio iki didziausio." << endl;
		cout << "1 - Surusiuoti skaiciu seka nuo didziausio iki maziausio." << endl;
		cin >> type;

		system("cls");
		switch (type) {
		case 0:
			isRunning = false;
			break;
		case 1:
			isRunning = false;
			break;
		default:
			cout << "Jusu pasirinkimas yra klaidingas." << endl;
		}
	}

	outputData = inputData;
	auto start = chrono::system_clock::now(); //laiko pradzia

	QuickSort(outputData, 0, outputData.size() - 1);

	auto end = chrono::system_clock::now(); //laiko pradzia

	if (type == 1) {
		Reverse(outputData);
	}
	ofstream output;
	output.open("output.txt");

	for (int a = 0; a < outputData.size(); a++) {
		output << outputData[a];
	}

	output.close();

	if (isCorrect(inputData, outputData, type)) { //Tiesiog checkinimas
		cout << "Rusiavimas yra sekmingas." << endl;
	}
	else {
		cout << "Ivyko klaida." << endl;
	}

	chrono::duration<double> elapsed_seconds = end - start; //gl boyz

	cout << "Operacijos atlikimo laikas: " << elapsed_seconds.count();

	system("pause");
	return 0;
}