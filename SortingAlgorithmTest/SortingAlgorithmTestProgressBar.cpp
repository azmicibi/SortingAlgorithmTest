#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void BubbleSort(int **);//Runs Bubble Sort for all Arrays
void SelectionSort(int **);//Runs Selection Sort for all Arrays
void InsertionSort(int **);//Runs Insertion Sort for all Arrays
void QuickSort(int **);//Runs Quick Sort for all Arrays
void Recursive(int **A, int p, int q, int index);//Quick Sort Algorithm's recursive function
int Partition(int **Arrays, int p, int q, int index);//Quick Sort Algorithm's Partition Function
void RandomArrayCreator(int **);//Fills "Arrays[][]" with random values
void TempArray(int **, int **);//Copy values from Original Arrays to "TempArrays"
void ArrayCreator(int**);//Allocates memory for Arrays	
void Print();//Prints Durations times
double durations[4][3];//Keeps duration times of Algorithms
clock_t TimeStart, TimeEnd;
void main() {
	srand(time(NULL));
	int **Arrays = new int *[3];//Original Arrays
	int **TempArrays = new int *[3];//Temp Arrays
	ArrayCreator(Arrays);
	ArrayCreator(TempArrays);
	RandomArrayCreator(Arrays);
	TempArray(TempArrays, Arrays);
	BubbleSort(TempArrays);
	TempArray(TempArrays, Arrays);
	SelectionSort(TempArrays);
	TempArray(TempArrays, Arrays);
	InsertionSort(TempArrays);
	QuickSort(Arrays);
	Print();
	system("pause");
}

void ArrayCreator(int**array) {
	array[0] = new int[1000];
	array[1] = new int[10000];
	array[2] = new int[100000];
	cout << "SUCCESS:Memory Allocated For The Arrays" << endl;
}
void RandomArrayCreator(int **Array) {
	int n = 1000;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n; i++) {
			Array[j][i] = rand();
		}
		n *= 10;
	}
	cout << "SUCCESS:Arrays Filled With Random Values" << endl;
}
void TempArray(int **Temp, int **Array) {
	int n = 1000;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n; i++) {
			Temp[j][i] = Array[j][i];
		}
		n *= 10;
	}
	cout << "SUCCESS:Original Arrays Copied To The Temp Arrays" << endl;
}
void BubbleSort(int **Array)
{
	int n = 1000;
	int temp;
	for (int k = 0; k < 3; k++) {
		cout << "%0[---------------------------------------------------]";//Progress bar
		TimeStart = clock();
		for (int i = 1; i < n; i++)//This loop is a part of Bubble Sort Algorithm.You can look over to algorithm from here: https://en.wikipedia.org/wiki/Bubble_sort
		{
			if (i % (n/100) == 0 ) {//This scope is not in Bubble Sort algorithm.This scope is for progress bar percentage calculate
				cout << "\r%" << i / (n/100);
				if ((i /(n/100)) % 2 == 0)
					cout <<"["<< setfill('#')<< setw((i / ((n / 100) *2)+4));//Fills Progress Bar
				
			}
			for (int j = 0; j < n - i; j++)
			{
				if (Array[k][j] > Array[k][j + 1])
				{
					temp = Array[k][j];
					Array[k][j] = Array[k][j + 1];
					Array[k][j + 1] = temp;
				}
			}
		}
		TimeEnd = clock();
		durations[0][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;//Calculates duration time of Algorithm
		cout << "\r%100[" << setfill('#') << setw(50) << "]" << endl;//Shows Progress Bar
		cout << "SUCCESS:Array[" << n << "] Sorted with Bubble Sort in " << durations[0][k] << "seconds" << endl;//Info Message
		n *= 10;
	}
}
void SelectionSort(int **Array)
{
	int n = 1000;
	int temp, minimum;
	for (int k = 0; k < 3; k++) {
		cout << "%0[---------------------------------------------------]";//Progress bar
		TimeStart = clock();
		for (int i = 0; i<n - 1; i++)//This loop is a part of Selection Sort, You can look over to algorithm from here: https://en.wikipedia.org/wiki/Selection_sort
		{
			if (i % (n / 100) == 0) {//This scope is not in Selection Sort algorithm.This scope is for progress bar percentage calculate
				cout << "\r%" << i / (n / 100);
				if ((i / (n / 100)) % 2 == 0)
					cout << "[" << setfill('#') << setw((i / ((n / 100) * 2) + 4));//Fills Progress Bar

			}
			minimum = i;
			for (int j = i + 1; j<n; j++)
			{
				if (Array[k][j] < Array[k][minimum])
					minimum = j;
			}
			temp = Array[k][i];
			Array[k][i] = Array[k][minimum];
			Array[k][minimum] = temp;
		}
		TimeEnd = clock();
		durations[1][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;//Calculates duration time of Algorithm
		cout << "\r%100[" << setfill('#') << setw(50) << "]" << endl;//Shows Progress Bar
		cout << "SUCCESS:Array[" << n << "] Sorted with Selection Sort in " << durations[1][k] << "seconds" << endl;//Info Message
		n *= 10;
	}
}
void InsertionSort(int **Arrays) {
	int n = 1000;
	int j, temp;
	for (int k = 0; k < 3; k++) {
		cout << "%0[---------------------------------------------------]";//Progress bar
		TimeStart = clock();
		for (int i = 0; i < n; i++) {//This loop is a part of Insertion Sort, You can look over to algorithm from here: https://en.wikipedia.org/wiki/Insertion_sort
			j = i;
			if (i % (n / 100) == 0) {//This scope is not in Insertion Sort algorithm.This scope is for progress bar percentage calculate
				cout << "\r%" << i / (n / 100);
				if ((i / (n / 100)) % 2 == 0)
					cout << "[" << setfill('#') << setw((i / ((n / 100) * 2) + 4));//Fills Progress Bar

			}
			while (j > 0 && Arrays[k][j] < Arrays[k][j - 1]) {
				temp = Arrays[k][j];
				Arrays[k][j] = Arrays[k][j - 1];
				Arrays[k][j - 1] = temp;
				j--;
			}
		}
		TimeEnd = clock();
		durations[2][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;//Calculates duration time of Algorithm
		cout << "\r%100[" << setfill('#') << setw(50) << "]" << endl;//Shows Progress Bar
		cout << "SUCCESS:Array[" << n << "] Sorted with Insertion Sort in " << durations[2][k] << "seconds" << endl;//Info Message
		n *= 10;
	}
}
void QuickSort(int **Arrays) {
	int n = 1000;
	for (int k = 0; k < 3; k++) {
		TimeStart = clock();
		Recursive(Arrays, 0, n, k);//This function and "Partition()" function is about Quick Sort Algorithm.You can look over to algorithm from here:
		TimeEnd = clock();
		durations[3][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;
		cout << "\r%100[" << setfill('#') << setw(50) << "]" << endl;//Shows Progress Bar
		cout << "SUCCESS:Array[" << n << "] Sorted with Quick Sort in " << durations[3][k] << "seconds" << endl;//Info Message
		n *= 10;
	}
}
void Recursive(int **A, int p, int q, int index)
{
	int r;
	if (p<q)
	{
		r = Partition(A, p, q, index);
		Recursive(A, p, r, index);
		Recursive(A, r + 1, q, index);
	}
}
int Partition(int **Arrays, int p, int q, int index)
{
	int x = Arrays[index][p];
	int i = p;
	int j;
	for (j = p + 1; j<q; j++)
	{
		if (Arrays[index][j] <= x)
		{
			i = i + 1;
			swap(Arrays[index][i], Arrays[index][j]);
		}
	}
	swap(Arrays[index][i], Arrays[index][p]);
	return i;
}
void Print() {
	
	cout << "                1000     10000    100000" << endl;
	cout << "BubbleSort     " << setfill(' ') << setw(3) << durations[0][0] << setw(10) << durations[0][1] << setw(10) << durations[0][2] << endl;
	cout << "SelectionSort  " << setw(3) << durations[1][0] << setw(10) << durations[1][1] << setw(10) << durations[1][2] << endl;
	cout << "InsertionSort  " << setw(3) << durations[2][0] << setw(10) << durations[2][1] << setw(10) << durations[2][2] << endl;
	cout << "QuickSort      " << setw(3) << durations[3][0] << setw(10) << durations[3][1] << setw(10) << durations[3][2] << endl;
}