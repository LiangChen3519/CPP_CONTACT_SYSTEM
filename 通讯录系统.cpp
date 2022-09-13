// 通讯录系统.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#define MAX 1000 // no '; '

// 菜单界面
void showMenu() {
	std::cout << "****************************" << std::endl;
	std::cout << "***** 1.Add contact    *****" << std::endl;
	std::cout << "***** 2.Show contact   *****" << std::endl;
	std::cout << "***** 3.Del contact    *****" << std::endl;
	std::cout << "***** 4.Query contact  *****" << std::endl;
	std::cout << "***** 5.revise contact *****" << std::endl;
	std::cout << "***** 6.cancel contact *****" << std::endl;
	std::cout << "***** 0.Exit contact   *****" << std::endl;
	std::cout << "****************************" << std::endl;
}

// 联系人struct

struct Person {
	std::string m_Name; // name
	int m_Sex; // 1 m; 2fm
	int m_Age; // age
	std::string m_Phone; // phone number
	std::string m_Addr; // address of a person
};
//通讯录结构
struct AddressBook {
	struct Person personArr[MAX];
	int m_Size = 0; //通讯录中人员个数;
};

// 1.添加联系人
void addPerson(AddressBook* abs) {
	// 添加联系人
	if (abs->m_Size == MAX) {
		std::cout << "CONTACT IS FULL, CAN'T ADD MORE" << std::endl;
	}
	else {
		// 姓名
		std::string name;
		std::cout << "pleas input a name " << std::endl;
		std::cin >> name;
		abs->personArr[abs->m_Size].m_Name = name;
		// 性别
		std::cout << "please input the sexual 1 or 2 please!" << std::endl;
		std::cout << "1 means male" << std::endl;
		std::cout << "2 menas female" << std::endl;
		int sex = 0;
		while (true) {
			std::cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				std::cout << "plese input 1 or 2 only, 1 is male, 2 is female" << std::endl;
			}
		}
		// age
		std::cout << "please input age" << std::endl;
		int age = 0;
		std::cin >> age;
		abs->personArr[abs->m_Size].m_Age = age;

		// phone
		std::cout << "plz input phone " << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personArr[abs->m_Size].m_Phone = phone;

		//address

		std::cout << "plz input address " << std::endl;
		std::string address;
		std::cin >> address;
		abs->personArr[abs->m_Size].m_Addr = address;
		// update the numbers of person 
		abs->m_Size++;
		std::cout << "successfully add a person" << std::endl;

	}
}

// 显示联系人
void showPerson(AddressBook* abs) {
	// 先判断通讯录中有人否，如果为0，则需要先添加pereson
	if (abs->m_Size == 0) {
		std::cout << "no pereon in your contact book" << std::endl;
		std::cout << "add a pereson first plz!" << std::endl;
	}
	else {
		std::cout << "Name\t" << "Sexual\t" << "Age\t" << "Phone\t" << "\t" << "Address" << std::endl;
		for (int i = 0; i < abs->m_Size;i++) {
			std::cout << abs->personArr[i].m_Name << "\t";
			std::cout << (abs->personArr[i].m_Sex == 1 ? "male" : "female") << "\t";
			std::cout << abs->personArr[i].m_Age << "\t";
			std::cout << abs->personArr[i].m_Phone << "\t";
			std::cout << abs->personArr[i].m_Addr << std::endl;
		}
	}
	system("pause");
}
//检查和删除联系人

int checkPerson(AddressBook* abs, std::string name) {
	//检测是否存在该人在通讯录中
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArr[i].m_Name == name) {
			std::cout << "person is found" << std::endl;
			std::cout << "the person is at " << i + 1 << "row" << std::endl;
			// 删除 记录操作
			// 数据前移

			return i;
		}
	}
	return -1;
}

// delPerson
void delPerson(AddressBook* abs) {
	std::cout << "please input the guy your want to delect" << std::endl;
	std::string name;

	std::cin >> name;

	int res = checkPerson(abs, name);

	if (res != -1) {
		for (int i = res; i < abs->m_Size; i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->m_Size--;
		std::cout << "del successful" << std::endl;
	}
	else {
		printf("no such people");
	}
}
//修改联系人

void modifyPerson(AddressBook* abs) {
	std::cout << "please input a person" << std::endl;
	std::string name;
	std::cin >> name;
	int res = checkPerson(abs, name);
	// find the person
	if (res != -1)
	{
		// name
		std::string name;
		std::cout << "please input name" << std::endl;
		std::cin >> name;
		abs->personArr[res].m_Name = name;

		// sexual
		std::cout << "please input sexual " << std::endl;
		std::cout << "1------male " << std::endl;
		std::cout << "2----female" << std::endl;
		int sex = 0;

		while (true)
		{
			if (sex == 1 || sex == 2) {
				abs->personArr[res].m_Sex = sex;
				break;
			}
			std::cout << "wrong input" << std::endl;
		}

		//age
		std::cout << "please input age " << std::endl;
		int age = 0;
		std::cin >> age;
		abs->personArr[res].m_Age = age;

	}
	else
	{
		std::cout << "no people found" << std::endl;
	}

}
// clean databse
void cleanPerson(AddressBook* abs) {
	abs->m_Size = 0;
	std::cout << "now contact has been cleared" << std::endl;
	system("pause");
	system("cls");
}

// main 函数
int main()
{
	//创建通讯录结构体变量
	AddressBook abs;
	abs.m_Size = 0; // 初始化 m_Size = 0
	int select = 0; // 用户输入变量

	while (true)
	{
		system("cls"); //清除终端的输出
		showMenu();

		std::cin >> select;

		switch (select) {
		case 1:
			addPerson(&abs); // 利用地址传递可以修饰实参；
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
			delPerson(&abs);
			system("pause");
		}
		break;
		case 4:
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			std::cout << "welcome to use next time our system" << std::endl;
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");

	return 0;
}

