#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
void test()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	int num = accumulate(v.begin(), v.end(),0);//参数3代表累加起始值
	cout << "num =  " << num << endl;
}
int main()
{
	test();
	return 0;
}