#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

//for_each
//���ڱ���
//�з���ֵ
//���԰󶨲����������
//transform  ��ָ����������Ԫ�ذ��˵���һ������
//����
//ע�⣺Ŀ������Ҫ������
using namespace std;
class print :public binary_function<int,int,void>
{
public:
	void operator()(int val,int num)const
	{
		cout << val+num << " ";
	}
};
void test()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(print(),1000));
	cout << endl;
}
class trans
{
public:
	int operator()(int val)
	{
		return val;
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>v1;
	v1.resize(v.size());
	transform(v.begin(), v.end(), v1.begin(), trans());
	for_each(v1.begin(), v1.end(),[](int val) {cout << val << " ";});
}
int main()
{
	test1();
	return 0;
}