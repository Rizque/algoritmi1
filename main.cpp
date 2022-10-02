#include <ctime>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int bubbleCount = 0;
int quickSortCount = 0;
int mergeCount = 0;

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is
// right index of the sub-array 
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{   mergeCount +=1;
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{   quickSortCount +=1;
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    


}
  
/* Function to print an array */
void printArray(int arr[], int size)
{   

    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}


void augosiSakartots(int arr[], int n, ofstream &fails){
    sort(arr, arr + n);
    cout<<"Sakartots masivs: ";
    fails<<"Sakartots masivs: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
        fails << arr[i] << ", ";
    }
    cout << endl;
    fails << endl;
}
void dilstosiSakartots(int arr[], int n, ofstream &fails){

    sort(arr, arr + n, greater<int>());
    cout<<"Dilstosa seciba sakartots masivs: ";
    fails<<"Dilstosa seciba sakartots masivs: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
        fails << arr[i] << ", ";
    }
    cout << endl;
    fails << endl;

}

void bubbleSort(int arr[], int n, ofstream &fails)
{
    cout << "Bubble algoritms: \n";
    fails << "Bubble algoritms: \n";
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
        bubbleCount +=1;
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
        fails << arr[i] << ", ";
    cout << endl;
    fails << endl;

}
 



int main(){
    unsigned seed = time(0);
    srand(seed);
    bool parbaude1 = true;
    int minn = 100;
    int maxn = 1000;
    int mLength = rand() % (maxn - minn + 1) + minn;
    int ritv[mLength] = {};
    int mini = 1;
    int maxi = 500;
    for (int i = 0; i < mLength; i++){
        ritv[i] = rand() % (maxi - mini + 1) + mini;
    }
    ofstream fails("rezult.txt");
        
    cout << "Sakotnejais masivs: ";
    fails << "Sakotnejais masivs: ";
    for (int i = 0; i < mLength; i++){
        cout << ritv[i] << ", ";
        fails << ritv[i] << ", ";
    }
    cout << endl;
    fails << endl;    
    int N = sizeof(ritv) / sizeof(ritv[0]);
    cout << "Skaitlu skaits masiva: " << N << endl;
    int choice = 0;
    cout<< "Kartosanas algoritmu veidi: \n"
            "1.Izmantojot sort() funkciju \n"
            "2.Izmantojot sort() funkciju (dilstoss) \n"
            "3.Bubble metode \n"
            "4.QuickSort metode \n"
            "5.Merge metode \n";
        
    cout<<"Ievadi kartosanas metodes numuru: ";
    cin >> choice;
    switch (choice){
        case 1:
            augosiSakartots(ritv, N, fails);
            break;
        case 2:
            dilstosiSakartots(ritv, N, fails);
            break;
        case 3:
            bubbleSort(ritv, N, fails);
            cout << "Salidzinasanas reizu skaits: "<< bubbleCount;
            fails << "Salidzinasanas reizu skaits: "<< bubbleCount;
            break;
        case 4:
            cout << "QuickSort algoritms: \n";
            quickSort(ritv, 0, N - 1);
            printArray(ritv, N);
            cout << "Salidzinasanas reizu skaits: "<< quickSortCount;
            break;
        case 5:
            cout << "Merge algoritms: \n";
            mergeSort(ritv, 0, N - 1);
            printArray(ritv, N);
            cout << "Salidzinasanas reizu skaits: "<< mergeCount;

            break;
        default:
            cout << "Kluda";

    }

    fails.close();

    return 0;
}

// Noderīgs materiāls - https://www.programiz.com/dsa/sorting-algorithm