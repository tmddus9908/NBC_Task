#include <iostream>
#include <vector>
using namespace std;

void getSum(int& sum,vector<int> nums)
{
	for (size_t i = 0; i < nums.size(); i++)
		sum += nums[i];
}
void getAvg(float& avg, float num1, float num2)
{
	avg = num1 / num2;
}
void swap(int& num1, int& num2)
{
	int temp = 0;
	temp = num1;
	num1 = num2;
	num2 = temp;
}
void bubbleSort(vector<int> v, int n)
{
	for (size_t i = 0; i < v.size() - 1; i++) // 버블 정렬 방식 이용
	{
		for (size_t j = 0; j < v.size() - 1 - i; j++) {
			if (n == 1) {
				if (v[j] > v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
			}
			else if (n == 2)
			{
				if (v[j] < v[j + 1])
					swap(v[j], v[j + 1]);
			}
		}
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
int main()
{
	vector<int> numbers;
	int times = 0;
	int sum = 0;
	float avg = 0;
	int choice = 0;

	cout << "몇개의 수를 입력하시겠습니까? ";
	cin >> times;


	for (int i = 0; i < times; i++) {
		int input;
		cout << i+1 << "번째 수 입력 : ";
		cin >> input;
		numbers.push_back(input);
	}

	getSum(sum, numbers);

	getAvg(avg, sum, numbers.size());
	
	cout << "sum : " << sum << endl;
	cout << "avg : " << avg << endl;

	cout << "오름차순은 1번 내림 차순은 2번을 눌러주세요" << endl;
	cin >> choice;

	if (choice == 1)
	{
		bubbleSort(numbers, 1);
	}
	else if (choice == 2)
	{
		bubbleSort(numbers, 2);
	}
	else
		cout << "잘못된 수를 누르셨습니다." << endl;

	return 0;
}
