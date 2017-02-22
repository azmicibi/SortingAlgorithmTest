//#include <iostream>
//#include <time.h>
//#include <iomanip>
//using namespace std;
//void BubbleSort(int **);
//void SelectionSort(int **);
//void InsertionSort(int **);
//void QuickSort(int **);
//void Recursive(int **A, int p, int q, int index);
//void RandomArrayCreator(int **);
//void TempArray(int **, int **);
//void ArrayCreator(int**);
//void Print();
//int Partition(int **Arrays, int p, int q, int index);
//double durations[4][3];
//clock_t TimeStart, TimeEnd;
//void main() {
//	srand(time(NULL));
//	int **Arrays = new int *[3];
//	int **TempArrays = new int *[3];
//	ArrayCreator(Arrays);
//	ArrayCreator(TempArrays);
//	RandomArrayCreator(Arrays);
//	TempArray(TempArrays, Arrays);
//	BubbleSort(TempArrays);
//	TempArray(TempArrays, Arrays);
//	SelectionSort(TempArrays);
//	TempArray(TempArrays, Arrays);
//	InsertionSort(TempArrays);
//	TempArray(TempArrays, Arrays);
//	QuickSort(TempArrays);
//	Print();
//	system("pause");
//}
//
//void ArrayCreator(int**array) {
//	array[0] = new int[1000];
//	array[1] = new int[10000];
//	array[2] = new int[100000];
//	cout << "SUCCESS:Memory Allocated For The Arrays" << endl;
//}
//void RandomArrayCreator(int **Array) {
//	int n = 1000;
//	for (int j = 0; j < 3; j++) {
//		for (int i = 0; i < n; i++) {
//			Array[j][i] = rand();
//		}
//		n *= 10;
//	}
//	cout << "SUCCESS:Arrays Filled With Random Values" << endl;
//}
//void TempArray(int **Temp, int **Array) {
//	int n = 1000;
//	for (int j = 0; j < 3; j++) {
//		for (int i = 0; i < n; i++) {
//			Temp[j][i] = Array[j][i];
//		}
//		n *= 10;
//	}
//	cout << "SUCCESS:Original Arrays Copied To The Temp Arrays" << endl;
//}
//void BubbleSort(int **Array)
//{
//	int n = 1000;
//	int temp;
//	for (int k = 0; k < 3; k++) {
//		TimeStart = clock();
//		for (int i = 1; i < n; i++)
//		{
//			if (i % 1000 == 0)
//				cout << "\r%" << i / 1000 << " Percentage of Array Have Been Sorted";
//			for (int j = 0; j < n - i; j++)
//			{
//				if (Array[k][j] > Array[k][j + 1])
//				{
//					temp = Array[k][j];
//					Array[k][j] = Array[k][j + 1];
//					Array[k][j + 1] = temp;
//				}
//			}
//		}
//		TimeEnd = clock();
//		durations[0][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;
//		cout << "\rSUCCESS:Array[" << n << "] Sorted with Bubble Sort in " << durations[0][k] << "seconds" << endl;
//		n *= 10;
//	}
//}
//void SelectionSort(int **Array)
//{
//	int n = 1000;
//	int temp, minimum;
//	for (int k = 0; k < 3; k++) {
//		TimeStart = clock();
//		for (int i = 0; i<n - 1; i++)
//		{
//			if (i % 1000 == 0)
//				cout << "\r%" << i / 1000 << " Percentage of Array Have Been Sorted";
//			minimum = i;
//			for (int j = i + 1; j<n; j++)
//			{
//				if (Array[k][j] < Array[k][minimum])
//					minimum = j;
//			}
//			temp = Array[k][i];
//			Array[k][i] = Array[k][minimum];
//			Array[k][minimum] = temp;
//		}
//		TimeEnd = clock();
//		durations[1][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;
//		cout << "\rSUCCESS:Array[" << n << "] Sorted with Selection Sort in " << durations[1][k] << "seconds" << endl;
//		n *= 10;
//	}
//}
//void InsertionSort(int **Arrays) {
//	int n = 1000;
//	int j, temp;
//	for (int k = 0; k < 3; k++) {
//		TimeStart = clock();
//		for (int i = 0; i < n; i++) {
//			j = i;
//			if (i % 1000 == 0)
//				cout << "\r%" << i / 1000 << " Percentage of Array Have Been Sorted";
//			while (j > 0 && Arrays[k][j] < Arrays[k][j - 1]) {
//				temp = Arrays[k][j];
//				Arrays[k][j] = Arrays[k][j - 1];
//				Arrays[k][j - 1] = temp;
//				j--;
//			}
//		}
//		TimeEnd = clock();
//		durations[2][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;
//		cout << "\rSUCCESS:Array[" << n << "] Sorted with Insertion Sort in " << durations[2][k] << "seconds" << endl;
//		n *= 10;
//	}
//}
//void QuickSort(int **Arrays) {
//	int n = 1000;
//	for (int k = 0; k < 3; k++) {
//		TimeStart = clock();
//		Recursive(Arrays, 0, n, k);
//		TimeEnd = clock();
//		durations[3][k] = ((double)(TimeEnd - TimeStart)) / CLOCKS_PER_SEC;
//		cout << "SUCCESS:Array[" << n << "] Sorted with Quick Sort in " << durations[3][k] << "seconds" << endl;
//		n *= 10;
//	}
//}
//void Recursive(int **A, int p, int q, int index)
//{
//	int r;
//	if (p<q)
//	{
//		r = Partition(A, p, q, index);
//		Recursive(A, p, r, index);
//		Recursive(A, r + 1, q, index);
//	}
//}
//int Partition(int **Arrays, int p, int q, int index)
//{
//	int x = Arrays[index][p];
//	int i = p;
//	int j;
//	for (j = p + 1; j<q; j++)
//	{
//		if (Arrays[index][j] <= x)
//		{
//			i = i + 1;
//			swap(Arrays[index][i], Arrays[index][j]);
//		}
//	}
//	swap(Arrays[index][i], Arrays[index][p]);
//	return i;
//}
//void Print() {
//	setfill(' ');
//	cout << "                1000     10000    100000" << endl;
//	cout << "BubbleSort     " << setw(3) << durations[0][0] << setw(10) << durations[0][1] << setw(10) << durations[0][2] << endl;
//	cout << "SelectionSort  " << setw(3) << durations[1][0] << setw(10) << durations[1][1] << setw(10) << durations[1][2] << endl;
//	cout << "InsertionSort  " << setw(3) << durations[2][0] << setw(10) << durations[2][1] << setw(10) << durations[2][2] << endl;
//	cout << "QuickSort      " << setw(3) << durations[3][0] << setw(10) << durations[3][1] << setw(10) << durations[3][2] << endl;
//}