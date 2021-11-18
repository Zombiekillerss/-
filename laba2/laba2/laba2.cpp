#include "SearchAndSorts.h"

int main()
{
	int *arrnum1 = nullptr, *arrnum2 = nullptr;
	clock_t begin, end;
	double elapset_sec;
	srand(time(0));
	for (int i = 10; i < 100001; i *= 10)
	{
		begin = clock();
		arrnum2 = RandomArray(i, 20);
		InsertionSort(arrnum2, i);
		end = clock();
		elapset_sec = ((double)end - (double)begin) / CLOCKS_PER_SEC;
		cout << "Time InsertionSort(" << i << " elements): " << elapset_sec << "sec" << endl;
		begin = clock();
		arrnum1 = RandomArray(i, 20);
		QuickSort(arrnum1, 0, i - 1);
		end = clock();
		elapset_sec = ((double)end - (double)begin) / CLOCKS_PER_SEC;
		cout << "Time QuickSort(" << i << " elements): " << elapset_sec << "sec" << endl;
		delete[] arrnum1;
		delete[] arrnum2;
		arrnum1 = nullptr;
		arrnum2 = nullptr;
	}
    return 0;
}
