#include <iostream>
using namespace std;

class stack
{
private:
	int* arr;
	int top;
	int N = 10;
public:
	class Full {};
	class Empty {};
	stack() //конструктор без параметров
	{
		top = -1;
		arr = new int[N];
	}
	stack(int m) //конструктор с одним параметром
	{
		top = -1;
		arr = new int[m];
		N = m;
	}
	~stack() //деструктор
	{
		delete[] arr;
	}
	void push(int a) //функция добавления элемента
	{
		if (top == N - 1) //значение вершины равно размеру массива(стека)?
			throw Full();
		else
		{
			top++;
			arr[top] = a; //увеличиваем значение вершины и кладем это значение в массив
		}
	}
	int pop() //функция извлечения элемента
	{
		if (top < 0) //переменная вершины больше либо равна 0
			throw Empty();
		return arr[top--];
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int znach, o;
	bool r; //укажем логический тип данных для проверки логических условий
	cout << "Сколько будет элементов в стэке: ";
	cin >> o;
	stack one(o);
	do {
		cout << "Для добавление введите 1, для извлечения 0: ";
		cin >> r;
		if (r)
		{
			cout << "Введите значение: ";
			cin >> znach;
			try
			{
				one.push(znach);
			}
			catch (stack::Full)
			{
				cout << "Ошибка: переполнение стека" << endl;
			}
		}
		else
		{
			cout << "Значение равно: ";
			try
			{
				cout << one.pop();
			}
			catch (stack::Empty)
			{
				cout << "Ошибка: стек пуст" << endl;
			}
			cout << endl;
		}
	} while (true);
	return 0;
}