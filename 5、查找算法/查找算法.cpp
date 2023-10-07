#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void test()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	/*vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << "找到元素: " << *pos << endl;
	}*/
}
class Person
{
public:
	Person(string name, int age)
	{
		this->mname = name;
		this->mage = age;
	}
	bool operator==(const Person& p)
	{
		return this->mname == p.mname && this->mage == p.mage;
	}
	string mname;
	int mage;
};
void test1()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos != v.end())
	{
		cout << "找到了成员 姓名为： " << pos->mname << " 年龄为： " << pos->mage << endl;
	}
}
class mycompare:public binary_function< Person*, Person*, bool>
{
public:
	bool operator()(Person* p1, Person* p2)const
	{
		return p1->mage == p2->mage && p1->mname == p2->mname;
	}
};
void test2()
{
	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	Person* p = new Person("bbb", 21);
	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(mycompare(),p));
	if (pos != v.end())
	{
		cout << "找到了元素 姓名： " << (*pos)->mname << " 年龄为: " << (*pos)->mage << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}
}
void test3()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << "找到了相邻的重复元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
void test4()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 100);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
int main()
{
	test4();
	return 0;
}