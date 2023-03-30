#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang elemnt array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nmaksimum panjang arrayadalah 20" << endl;
	}
	cout << "\n---------------------" << endl;
	cout << "\nEnter Array Elemnt 20" << endl;
	cout << "\n---------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
	//swaps the element at index x with the element at index y 
	void swap(int x, int y)
	{
		int temp;

		temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}

	void q_short(int low, int high)
	{
		int pivot, i, j;
		if (low > high)
			return;

		//partition the list int two parts:
		//one containing elements less that equal to pivot
		//outher conntaining element greather than pivot

		pivot = arr[low];

		i = low + 1;
		j = high;

		while (i <= j)

		{
			//search for an element greater than pivot
			while ((arr[i] <= pivot) && (i <= high))
			{
				i++;
				cmp_count++;
			}
			cmp_count++;
			//search for an elemnt less than or equal to pivot
			while ((arr[j] > pivot) && (j >= low))
			{
				j--;
				cmp_count++;
			}
			cmp_count++;


			if (i < j) // if the greater element is on the left of the element
			{
				//swap the element at index i whit the elemnt at index j
				swap(i, j);
				mov_count++;
			}
		}
		//j now containt the index of the last elemnt in the sorted list
		if (low < j)
		{
			//move the pivot to its correct position in yhe list
			swap(low, j);
			mov_count++;

		}
		//sort the list on the left of pivot using quick sort
		q_short(low, j - 1);

		//short the list on the right of pivot using quick sort
		q_short(j + 1, high);

	}



	void display() {
		cout << "\n---------------------" << endl;
		cout << "sorted array" << endl;
		cout << "\n---------------------" << endl;
	
		for (int i = 0; 1 < n; i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << "\n\nnumber of comparasions; " << cmp_count << endl;
		cout << "number of data movement" << mov_count << endl;
	}


	int main()
	{

		input();
		//sort the array using quick sort
		q_short(0, n - 1);
		display();
		system("pause");

		return 0;
	}