#include <iostream>;
#include <ctime>;
#include <cstdlib>;
using namespace std;

void output(int a[], int size);
void headlargest(int a[], int n, int i);
void pyramidSort(int a[], int n);
void Merge(int A[], int l, int m, int r, int size);
void MergeSort(int A[], int left, int right, int size);
void insertionSort(int *, int size);
void quickSort(int arr[], int left, int right);
void bubbleSort(int arr[], int n);


void main()
{
	int menu, n;
	int *A = new int[0];
	int *R = new int[0];
	double start_time, end_time;
	srand(time(NULL));

	cout << "Menu:" << endl;
	cout << "1.Merge sort" << endl;
	cout << "2.Quick sort" << endl;
	cout << "3.Insertion sort" << endl;
	cout << "4.Bubble sort" << endl;
	cout << "5.Pyramid sort" << endl;
	cout << "6.End of work" << endl;

	int check;
	cout << "Size of your vector ";
	cin >> n;

	cout << "Enter 1 , to randomize vector ";
	cin >> check;
	A = new int[n];

	if (check != 1)
	{
		cout << "Please input your vector " << endl;
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			A[i] = rand();
		}
	}

	R = new int[n];

	do
	{
		cout << "Choose Menu item ";
		cin >> menu;

		if (menu <= 5 && menu >= 1)
		{
			for (int i = 0; i < n; ++i)
			{
				R[i] = A[i];
			}

			cout << "Before sorting : ";
			output(A, n);
			start_time = clock();
		}
		switch (menu)
		{
		case 1:
		{
			cout << "Merge sort" << endl;
			MergeSort(R, 0, n - 1, n);
			break;
		}
		case 2:
		{
			cout << "Quick sort" << endl;
			quickSort(R, 0, n - 1);
			break;
		}
		case 3:
		{
			cout << "Insertion sort" << endl;
			insertionSort(R, n);
			break;
		}
		case 4:
		{
			cout << "Bubble sort" << endl;
			bubbleSort(R, n);
			break;
		}
		case 5:
		{
			cout << "Pyramid sort" << endl;
			pyramidSort(R, n);
			break;
		}
		case 6:
		{
			delete[] A; delete[] R;
			cout << "Thanks for choosing our product. ^==^" << endl;
			break;
		}
		default:
		{
			cout << "Please input proper value" << endl;
			break;
		}
		}
		if (menu <= 5 && menu >= 1)
		{
			end_time = clock();
			cout << "After sorting : ";
			output(R, n);
			cout << "And it was done in " << end_time / CLOCKS_PER_SEC - start_time / CLOCKS_PER_SEC << endl;
		}
	} while (menu != 6);

	system("pause");
}

void output(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void headlargest(int a[], int n, int i)
{
	int larg = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<n && a[l]>a[larg])
	{
		larg = l;
	}
	if (r<n && a[r]>a[larg])
	{
		larg = r;
	}
	if (larg != i)
	{
		swap(a[i], a[larg]);
		headlargest(a, n, larg);
	}
}
void pyramidSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		headlargest(a, n, i);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		headlargest(a, i, 0);
	}
}
void Merge(int A[], int l, int m, int r, int size)
{
	int *B = new int[size];
	int i = l, j = m + 1, k = l;

	while (i <= m &&j <= r)
	{
		if (A[i] <= A[j])
		{
			B[k] = A[i];
			++i;
		}
		else
		{
			B[k] = A[j];
			++j;
		}
		++k;
	}

	while (i <= m)
	{
		B[k] = A[i];
		++i;
		++k;
	}

	while (j <= r)
	{
		B[k] = A[j];
		++j;
		++k;
	}

	for (int z = l; z <= r; ++z)
	{
		A[z] = B[z];
	}

	delete[] B;
}
void MergeSort(int A[], int left, int right, int size)
{
	if (right - left < 1)
	{
		return;
	}
	int mid = (right + left) / 2;
	if (right - left > 1)
	{
		MergeSort(A, left, mid, size);
		MergeSort(A, mid + 1, right, size);
	}
	Merge(A, left, mid, right, size);
}
void insertionSort(int *array, int size)
{
	int temp, item;
	for (int i = 1; i < size; i++)
	{
		temp = array[i];
		item = i - 1;
		while (item >= 0 && array[item] > temp)
		{
			array[item + 1] = array[item];
			array[item] = temp;
			item--;
		}
	}
}
void quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int mid = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < mid)
			i++;
		while (arr[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
		if (left < j)
		{
			quickSort(arr, left, j);
		}
		if (i < right)
		{
			quickSort(arr, i, right);
		}
	}
}
void bubbleSort(int arr[], int n)
{
	bool change = true;
	int j = 0;
	int i = 0;
	int tmp;
	while (change)
	{
		change = false;
		j++;
		for (i = 0; i < n - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				change = true;
			}
		}
	}
}
