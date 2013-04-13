/**
@author Морозов Николай ИУ8-21 2012/13
*/


#include <iostream>
#include <time.h>
using namespace std;

#define arraySize 100/// длинна массива. внесена в define для простоты и уменьшения объема оперативной памяти
#define lineLenght 15/// количество чисел, которые выведуться на экран в одной строке.

/**
@function printArray
Функция для печати массива целых чисел

@param *a массив чисел
@param size размер массива
@param lenght длина строки, измеряемая в количестве выеденных элементов
*/

void printArray(int *a, int size, int lenght)
{
	lenght++;
	for (int i = 0; i < size; i++)
	{
		cout << a[i];
		///Блок, который выравнивает элементы массива при выводе
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
		
		///перенос строки
		if (!((i+1) % lenght))
			cout << "\n";
	}
	///конец печати
	cout << "\n\n";

}
/**
@function quiq_sort
Быстрая сортировка массива. Функция рекурсивна

@param s[] массив чисел
@param left крайний левый элемент сортируемого блока
@param right крайний правый элемент сортируемого блока
*/
void quiq_sort(int s[], int left, int right)
{
	int i = left, j = right;
	///выбор контрольного элемента
	int middle = s[(left+right)/2];
	
	do
	{
		///нахождение в начале/конце элементов меньше/больше контрольного
		while (s[i] < middle) i++;
		while (s[j] > middle) j--;
		///нашли последний элемент блоков, меняем местами следующие после них элементы.
		if (i <= j)
		{
			int temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++; j--;
		}
	} while(i < j);
	///получили два множества: элементы меньшие контрольного и элементы меньшие контрольного. Теперь необходимо отсортировать их.
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