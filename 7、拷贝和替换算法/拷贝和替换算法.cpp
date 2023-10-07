#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>
using namespace std;
void test()
{
	vector<int>v;
	for (int  i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>v1;
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());
	/*for_each(v1.begin(), v1.end(), [](int val) {cout << val << " ";});
	cout << endl;*/
	copy(v1.begin(), v1.end(),ostream_iterator<int>(cout," "));
}
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	replace(v.begin(), v.end(), 3, 3000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
int main()
{
	test1();
	return 0;
}