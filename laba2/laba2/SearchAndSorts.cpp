#include "SearchAndSorts.h"

int GetRandomNumber(int max)//max of type long long so that there is no overflow
{
    //finds a random number from 0 to max
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * ((double)max + 1.0));
}

int* RandomArray(int size, int max)
{
    if (max >= 0 && size > 0)
    {
        int* arrnum = new int[size];
        int i = 0;
        //each element of the array is equal to a random number
        for (i; i < size; i++)
        {
            arrnum[i] = GetRandomNumber(max);
        }
        return arrnum;
    }
    else if(size <= 0) throw underflow_error("size must be > 0");// error message
    else throw underflow_error("max must be > -1");// error message
}

int BinarySearch(int* arrnum, int left, int right, int number)
{
    int middle;
    if (left > -1 && right > -1 && right > left && arrnum)
    {
        if (CorrectArray(arrnum, right))
        {
            while (true)
            {
                middle = (left + right) / 2;//finding the center of an array
                if (number < arrnum[middle]) right = middle - 1;
                else if (number > arrnum[middle]) left = middle + 1;
                else return middle;
                if (right < left) throw invalid_argument("number is entered incorrectly"); // error message
            }
        }
        else throw logic_error("array is not sorted"); // error message 
    }
    else if(!arrnum) 
        throw invalid_argument("array is empty"); // error message
    else if(!(left > -1 && right > -1 && right > left))
        throw underflow_error("range is entered incorrectly"); // error message
}

void QuickSort(int* arrnum, int left, int right)
{
    if (left >= 0 && right >= 0 && arrnum)
    {
        int permit = arrnum[left], //permiting element
            left_border = left,
            right_border = right;
        //if there is room in the range
        while (left_border < right_border)
        {
            //if the right number is greater than the left, then shift the right border to the left
            while ((arrnum[right_border] >= permit) && (left_border < right_border)) right_border--;
            if (left_border != right_border)
            {
                arrnum[left_border] = arrnum[right_border];
                left_border++;
            }
            //if the left number is greater than the right, then shift the left border to the right
            while ((arrnum[left_border] <= permit) && (left_border < right_border))
                left_border++;
            if (left_border != right_border)
            {
                arrnum[right_border] = arrnum[left_border];
                right_border--;
            }
        }
        //replace the repeating element with the lost one
        arrnum[left_border] = permit;
        if (left < left_border)
            QuickSort(arrnum, left, left_border - 1);
        if (right > left_border)
            QuickSort(arrnum, left_border + 1, right);
    }
    else if (!arrnum)
        throw invalid_argument("array is empty"); // error message
    else throw out_of_range("range is entered incorrectly"); // error message
}

void InsertionSort(int* arrnum, int size)
{
    int save;
    //move in a double loop through the entire
    //array and replace the elements if the left is greater than the right
    if (arrnum && size > 0)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i; j > 0 && arrnum[j - 1] > arrnum[j]; j--)
            {
                save = arrnum[j];
                arrnum[j] = arrnum[j - 1];
                arrnum[j - 1] = save;
            }
        }
    }
    else if(!arrnum) throw invalid_argument("array is empty"); // error message
    else throw underflow_error("range is entered incorrectly"); // error message
}

bool CorrectArray(int* arrnum, int size)
{
    //true-sorted, false-not sorted
    if (size > 0 && arrnum)
    {
        while (--size > 0)
            if (arrnum[size - 1] > arrnum[size])
                return false;
    }
    else if (!arrnum) throw invalid_argument("array is empty"); // error message
    else throw underflow_error("range is entered incorrectly"); // error message
    return true;
}

void Shuffle(int* arrnum, int size)
{
    int save, randomindex;
    //bogosort
    for (int i = 0; i < size; i++)
    {
        save = arrnum[i];
        randomindex = rand() % size;
        arrnum[i] = arrnum[randomindex];
        arrnum[randomindex] = save;
    }
}

void BogoSort(int* arrnum, int size)
{
    if (size > 0 && arrnum)while (!CorrectArray(arrnum, size))
        Shuffle(arrnum, size);
    else if (!arrnum) throw invalid_argument("array is empty"); // error message
    else throw underflow_error("range is entered incorrectly"); // error message
}

void CountingSort(char* string, int size) {
    if (string && size > 0)
    {
        int max;
        max = MaxChar(string, size);
        char* newarr = new char[max + 1];
        // fills the array with 0
        memset(newarr, 0, sizeof(*string) * (max + 1));
        // each string [i] element of the array is increased by 1
        for (int i = 0; i < size; ++i)
        {
            ++newarr[string[i]];
        }
        int index = 0;
        //if j <newarr [i] then replace string [index] with i and increase index
        for (int i = 0; i < max + 1; ++i) {
            for (int j = 0; j < newarr[i]; ++j)
            {
                string[index++] = i;
            }
        }
        delete[] newarr;
        newarr = nullptr;
    }
    else if (!string) throw invalid_argument("array is empty"); // error message
    else throw underflow_error("range is entered incorrectly"); // error message
}

int MaxChar(char* string, int size)
{
    if (string && size > 0)
    {
        int maximum = string[0];
        //finds the maximum number in a character array
        for (int i = 1; i < size; i++)
        {
            if (maximum < string[i])maximum = (int)string[i];
        }
        return maximum;
    }
    else if (!string) throw invalid_argument("array is empty"); // error message
    else throw underflow_error("range is entered incorrectly"); // error message
}