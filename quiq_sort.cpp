/**
@author ������� ������� ��8-21 2012/13
*/


#include <iostream>
#include <time.h>
using namespace std;

#define arraySize 100/// ������ �������. ������� � define ��� �������� � ���������� ������ ����������� ������
#define lineLenght 15/// ���������� �����, ������� ���������� �� ����� � ����� ������.

/**
@function printArray
������� ��� ������ ������� ����� �����

@param *a ������ �����
@param size ������ �������
@param lenght ����� ������, ���������� � ���������� ��������� ���������
*/

void printArray(int *a, int size, int lenght)
{
	lenght++;
	for (int i = 0; i < size; i++)
	{
		cout << a[i];
		///����, ������� ����������� �������� ������� ��� ������
		if ((a[i]>=0)&&(a[i]<1000))
		{
			cout <<' ';
		}
		if ((a[i]>=0)&&(a[i]<100))
		{
			cout <<' ';
		}
		if ((a[i]>=0)&&(a[i]<10))
		{
			cout <<' ';
		}
		
		///������� ������
		if (!((i+1) % lenght))
			cout << "\n";
	}
	///����� ������
	cout << "\n\n";

}
/**
@function quiq_sort
������� ���������� �������. ������� ����������

@param s[] ������ �����
@param left ������� ����� ������� ������������ �����
@param right ������� ������ ������� ������������ �����
*/
void quiq_sort(int s[], int left, int right)
{
	int i = left, j = right;
	///����� ������������ ��������
	int middle = s[(left+right)/2];
	
	do
	{
		///���������� � ������/����� ��������� ������/������ ������������
		while (s[i] < middle) i++;
		while (s[j] > middle) j--;
		///����� ��������� ������� ������, ������ ������� ��������� ����� ��� ��������.
		if (i <= j)
		{
			int temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++; j--;
		}
	} while(i < j);
	///�������� ��� ���������: �������� ������� ������������ � �������� ������� ������������. ������ ���������� ������������� ��.
	if (left < j) quiq_sort(s, left, j);
	if (i < right) quiq_sort(s, i, right);
}

void main()
{
	int *a = new int[arraySize];

	srand(time(NULL));

	for (int i = 0; i < arraySize; i++)
	{
		a[i] = rand() % 1000;
	}

	printArray(a, arraySize, lineLenght);

	quiq_sort(a, 0, arraySize-1);

	printArray(a, arraySize, lineLenght);


	delete a;



}