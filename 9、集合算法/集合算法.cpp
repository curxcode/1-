#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void test()
{
	vector<int>v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>v3;
	v3.resize(min(v1.size(), v2.size()));
	//容器交集
	vector<int>::iterator pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int val) {cout << val << " ";});
	cout << endl;
}
void test1()
{
	vector<int>v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>v3;
	//容器并集
	v3.resize(v1.size()+v2.size());
	vector<int>::iterator pos = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int val) {cout << val << " ";});
	cout << endl;
}
void test2()
{
	vector<int>v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>v3;
	//容器差集
	v3.resize(max(v1.size(),v2.size()));
	vector<int>::iterator pos = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), pos, [](int val) {cout << val << " ";});
	cout << endl;
}
int main()
{
	test2();
	return 0;
}