#pragma once
#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
#include <iostream>
#include <stdexcept>
using namespace std;

//Creates a random number
int GetRandomNumber(int max);
//creates an array of numbers of length size and range from 0 to max
int* RandomArray(int size, int max);
int BinarySearch(int *arrnum, int left, int right, int number);
void QuickSort(int *arrnum, int left, int right);
void InsertionSort(int *arrnum, int size);
//swaps random and specific elements of an array
void Shuffle(int* arrnum, int size);
//checks if the array is sorted correctly
bool CorrectArray(int* arrnum, int size);
void BogoSort(int* arrnum, int size);
//finds the maximum number in an array
int MaxChar(char* string, int size);
void CountingSort(char* string, int size);