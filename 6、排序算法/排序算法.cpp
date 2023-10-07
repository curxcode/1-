#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
using namespace std;
void test()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int>v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), [](int val) {cout << val << " ";});
}
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
	cout << endl;
}
void test2()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());//随机调整次序
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
}
int main()
{
	srand((unsigned int)time(NULL));
	//test();
	test2();
	return 0;
}