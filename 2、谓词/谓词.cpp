#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Than
{
public:
	bool operator()(int val)//一元谓词
	{
		return val > 20;
	}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	vector<int>::iterator pos = find_if(v.begin(), v.end(), Than());
	if (pos != v.end())
	{
		cout << "找到了大于20的数字" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

class mysort
{
public:
	bool operator()(int v1, int v2)//二元谓词
	{
		return v1 > v2;
	}
};
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	sort(v.begin(),v.end(),mysort());
	//lambda表达式 匿名函数  []代表lanmda表达式标志
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
	cout << endl;
}
int main()
{
	test1();
	return 0;
}