// 2005111B17-毛文杰-图书管理程序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
class Reader;
class Book;

//-----------------------
class Manager
{
public:
	Manager()
	{
		read();
		main_menu();
	}
	~Manager()
	{
		save();
	}

private:
	void main_menu(); //主界面菜单
	void first();	  //功能一菜单
	void second();
	void third();
	void forth();
	void fifth();
	void print_menu();	//输出主界面
	void first_menu();	//图书管理系统界面
	void second_menu(); //读者管理系统界面
	void third_menu();	//查询系统界面
	void add_book();
	void add_number();
	void delete_book();
	void decrease_number();
	void add_reader();
	void delete_reader();
	void find_book();
	void find_reader();
	void book_all();
	void reader_all();
	void read();
	void save();
	vector<Book> book;
	vector<Reader> reader;
};
//---------------------------------

//---------------------------------
class Book
{
public:
	string book_name;
	int book_num;
	Book()
	{
		book_name = "";
		book_num = 0;
	}
	void book_info()
	{
		cout << "      "
			<< "书名：" << book_name << "          \t"
			<< "数量：" << book_num << endl;
	}
	void book_add()
	{
		cout << "请输入书名:";
		cin >> book_name;
		while (1) {
			cout << "请输入数量:";
			cin >> book_num;
			if (book_num >=0) {
				break;
			}
			cout << "数量不能小于0!!!请重新输入" << endl;
		}
	}
	void book_delete()
	{
		cout << "请输入书名:";
		cin >> book_name;
	}
	void book_add_num()
	{
		cout << "请输入书名:";
		cin >> book_name;
		while (1) {
			cout << "请输入增加的数量:";
			cin >> book_num;
			if (book_num >= 0) {
				break;
			}
			cout << "数量不能小于0!!!请重新输入" << endl;
		}
	}
	void book_decrease()
	{
		cout << "请输入书名:";
		cin >> book_name;
		while (1) {
			cout << "请输入减少的数量:";
			cin >> book_num;
			if (book_num >= 0) {
				break;
			}
			cout << "数量不能小于0!!!请重新输入" << endl;
		}
	}
	void book_back()
	{
		cout << "请输入书名:";
		cin >> book_name;
		while (1) {
			cout << "请输入归还的数量:";
			cin >> book_num;
			if (book_num >= 0) {
				break;
			}
			cout << "数量不能小于0!!!请重新输入" << endl;
		}
	}
	void book_borrow()
	{
		cout << "请输入书名:";
		cin >> book_name;
		while (1) {
			cout << "请输入借出的数量:";
			cin >> book_num;
			if (book_num >= 0) {
				break;
			}
			cout << "数量不能小于0!!!请重新输入" << endl;
		}
	}
};

//---------------------------------------------

//---------------------------------------------
class Reader
{
public:
	string reader_number;
	string reader_name;
	vector<Book> reader_book;
	Reader()
	{
		reader_number = "";
		reader_name = "";
	}
	void reader_info()
	{
		cout << "读者帐号：" << reader_number << endl
			<< "读者姓名：" << reader_name << endl;
		if (reader_book.size() != 0)
		{
			cout << "借书情况：" << endl;
			for (int i = 0; i < reader_book.size(); i++)
			{
				reader_book[i].book_info();
			}
		}
		else
		{
			cout << "未借书" << endl;
		}
	}
	void reader_add()
	{
		cout << "请输入读者帐号:";
		cin >> reader_number;
		cout << "请输入读者姓名:";
		cin >> reader_name;
	}
	void reader_delete()
	{
		cout << "请输入读者帐号:";
		cin >> reader_number;
	}
};

//-----------------------------------

//-----------------------------------
int main()
{
	Manager Lib;
	system("pause");
}
//-----------------------------------

void Manager::print_menu()
{
	system("cls");
	cout << setw(50);
	cout << "******************" << endl;
	cout << setw(58);
	cout << "***欢迎来到xxxx大学图书馆***" << endl;
	cout << setw(50);
	cout << "******************" << endl;
	cout << "    " << setw(10) << "1、图书管理系统"
		<< "   " << setw(10) << "2、读者管理系统"
		<< "     "
		<< "3、查询系统" << setw(10) << "4、借书" << setw(10) << "5、还书" << setw(17) << "6、退出并保存" << endl
		<< "选择功能：";
}
void Manager::first_menu()
{
	system("cls");
	cout << setw(50);
	cout << "******************" << endl;
	cout << setw(51);
	cout << "***图书馆管理程序***" << endl;
	cout << setw(50);
	cout << "******************" << endl;
	cout << "    " << setw(10) << "1、增加图书"
		<< "       " << setw(10) << "2、增加库存"
		<< "   " << setw(10) << "   "
		<< "3、删除图书" << setw(10) << "   "
		<< "4、减少库存"
		<< "   " << setw(10) << setw(10) << "5、退出" << endl;
	book_all();
	cout << "选择功能：";
}
void Manager::second_menu()
{
	system("cls");
	int select;
	char flag;
	cout << setw(30);
	cout << "******************" << endl;
	cout << setw(32);
	cout << "*****读者管理程序*****" << endl;
	cout << setw(30);
	cout << "******************" << endl;
	cout << "    " << setw(10) << "1、添加读者"
		<< "   " << setw(10) << "2、删除读者" << setw(10) << setw(10) << "3、退出" << endl;
	reader_all();
	cout << "选择功能：";
}
void Manager::third_menu()
{
	system("cls");
	int select;
	char flag;
	cout << setw(40);
	cout << "******************" << endl;
	cout << setw(42);
	cout << "*****查询系统程序*****" << endl;
	cout << setw(40);
	cout << "******************" << endl;
	cout << "    " << setw(10) << "1、查询图书库存"
		<< "   " << setw(10) << "2、查询读者借书情况" << setw(10) << setw(10) << "3、退出" << endl;
	book_all();
	reader_all();
	cout << "选择功能：";
}
void Manager::main_menu()
{
	int select;
	print_menu();
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			first();
			break;
		case 2:
			second();
			break;
		case 3:
			third();
			break;
		case 4:
			forth();
			break;
		case 5:
			fifth();
			break;
		case 6:
			return void();
		default:
			cout << "没有功能：" << select << "!!!" << endl
				<< "请重新选择:";
			system("pause");
			break;
		}
		print_menu();
	}
}
void Manager::first()
{
	int select;
	first_menu();
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			add_book();
			break;
		case 2:
			add_number();
			break;
		case 3:
			delete_book();
			break;
		case 4:
			decrease_number();
			break;
		case 5:
			return void();
		default:
			cout << "没有功能：" << select << "!!!" << endl
				<< "请重新选择:";
			system("pause");
			break;
		}
		first_menu();
	}
}
void Manager::second()
{
	int select;
	second_menu();
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			add_reader();
			break;
		case 2:
			delete_reader();
			break;
		case 3:
			return void();
		default:
			cout << "没有功能：" << select << "!!!" << endl
				<< "请重新选择:";
			system("pause");
			break;
		}
		second_menu();
	}
}
void Manager::find_book()
{
	string b1;
	int n = book.size();
	cout << "请输入你要查询的图书名字：";
	cin >> b1;
	for (int i = 0; i < n; i++)
	{
		if (book[i].book_name == b1)
		{
			book[i].book_info();
			system("pause");
			return void();
		}
	}
	cout << "仓库没有这本书!!!" << endl;
	system("pause");
}
void Manager::find_reader()
{
	string r1;
	int n = reader.size();
	cout << "请输入你要查询的读者帐号：";
	cin >> r1;
	for (int i = 0; i < n; i++)
	{
		if (reader[i].reader_number == r1)
		{
			reader[i].reader_info();
			system("pause");
			return void();
		}
	}
	cout << "该校没有该读者!!!" << endl;
	system("pause");
}
void Manager::third()
{
	int select;
	third_menu();
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			find_book();
			break;
		case 2:
			find_reader();
			break;
		case 3:
			return void();
		default:
			cout << "没有功能：" << select << "!!!" << endl
				<< "请重新选择:";
			system("pause");
			break;
		}
		third_menu();
	}
}
void Manager::forth()
{
	string number;
	Book b1;
	cout << "输入你的读者帐号：";
	cin >> number;
	for (int j = 0; j < reader.size(); j++)
	{
		if (reader[j].reader_number == number)
		{
			book_all();
			b1.book_borrow();
			for (int i = 0; i < book.size(); i++)
			{
				if (book[i].book_name == b1.book_name)
				{
					while (1)
					{
						if (book[i].book_num - b1.book_num < 0)
						{
							cout << "库存不足，请重新输入数量：" << endl;
							while (1) {
								cout << "请输入借出的数量:";
								cin >> b1.book_num;
								if (b1.book_num >= 0) {
									break;
								}
								cout << "数量不能小于0!!!请重新输入" << endl;
							}
							continue;
						}
						for (int k = 0; k < reader[j].reader_book.size(); k++)
						{
							if (book[i].book_name == reader[j].reader_book[k].book_name)
							{
								reader[j].reader_book[k].book_num += b1.book_num;
								book[i].book_num -= b1.book_num;
								if (book[i].book_num == 0)
								{
									book.erase(book.begin() + i);
								}
								printf("\n\033[0m\033[1;31m%s\033[0m", "借书成功! (=^▽^=)\n");
								system("pause");
								return void();
							}
						}
						reader[j].reader_book.push_back(b1);
						book[i].book_num -= b1.book_num;
						if (book[i].book_num == 0)
						{
							book.erase(book.begin() + i);
						}
						printf("\n\033[0m\033[1;31m%s\033[0m", "借书成功! (=^▽^=)\n");
						system("pause");
						return void();
						break;
					}
					printf("\n\033[0m\033[1;31m%s\033[0m", "借书成功! (=^▽^=)\n");
					system("pause");
					return void();
				}
			}
			cout << "仓库没有这本书!!!" << endl;
			system("pause");
			return void();
		}
	}
	cout << "该校没有该读者!!!" << endl;
	system("pause");
}
void Manager::fifth()
{
	string number;
	Book b1;
	cout << "输入你的读者帐号：";
	cin >> number;
	for (int i = 0; i < reader.size(); i++)
	{
		if (reader[i].reader_number == number)
		{
			reader[i].reader_info();
			if (reader[i].reader_book.size() == 0)
			{
				cout << "你未借书!!!" << endl;
				system("pause");
				return void();
			}
			b1.book_back();
			for (int j = 0; j < reader[i].reader_book.size(); j++)
			{
				if (reader[i].reader_book[j].book_name == b1.book_name)
				{
					while (1)
					{
						if (reader[i].reader_book[j].book_num - b1.book_num < 0)
						{
							cout << "还书数量输入超过借书数量!!!请重新输入数量：" << endl;
							while (1) {
								cout << "请输入借出的数量:";
								cin >> b1.book_num;
								if (b1.book_num >= 0) {
									break;
								}
								cout << "数量不能小于0!!!请重新输入" << endl;
							}
							continue;
						}
						for (int k = 0; k < book.size(); k++)
						{
							if (book[k].book_name == b1.book_name)
							{
								reader[i].reader_book[j].book_num -= b1.book_num;
								book[k].book_num += b1.book_num;
								if (reader[i].reader_book[j].book_num == 0)
								{
									reader[i].reader_book.erase(reader[i].reader_book.begin() + j);
								}
								printf("\n\033[0m\033[1;31m%s\033[0m", "还书成功! (=^▽^=)\n");
								system("pause");
								return void();
							}
						}
						book.push_back(b1);
						reader[i].reader_book[j].book_num -= b1.book_num;
						if (reader[i].reader_book[j].book_num == 0)
						{
							reader[i].reader_book.erase(reader[i].reader_book.begin() + j);
						}
						printf("\n\033[0m\033[1;31m%s\033[0m", "还书成功! (=^▽^=)\n");
						system("pause");
						return void();
						break;
					}
					printf("\n\033[0m\033[1;31m%s\033[0m", "还书成功! (=^▽^=)\n");
					system("pause");
					return void();
				}
			}
			cout << "你没有借这本书" << endl;
			system("pause");
			return void();
		}
	}
	cout << "该校没有该读者!!!" << endl;
	system("pause");
}
void Manager::add_book()
{
	Book b1;
	b1.book_add();
	int n = book.size();
	for (int i = 0; i < n; i++)
	{
		if (book[i].book_name == b1.book_name)
		{
			cout << "仓库里有这本书，添加失败，请选择功能2 、增加库存" << endl;
			system("pause");
			return void();
		}
	}
	book.push_back(b1);
}
void Manager::add_number()
{
	Book b1;
	b1.book_add_num();
	int n = book.size();
	for (int i = 0; i < n; i++)
	{
		if (book[i].book_name == b1.book_name)
		{
			book[i].book_num += b1.book_num;
			return void();
		}
	}
	cout << "仓库没有这本书!!!" << endl;
	system("pause");
}
void Manager::delete_book()
{
	Book b1;
	b1.book_delete();
	int n = book.size();
	for (int i = 0; i < n; i++)
	{
		if (book[i].book_name == b1.book_name)
		{
			book.erase(book.begin() + i);
			return void();
		}
	}
	cout << "仓库没有这本书!!!" << endl;
	system("pause");
}
void Manager::decrease_number()
{
	Book b1;
	b1.book_decrease();
	int n = book.size();
	for (int i = 0; i < n; i++)
	{
		if (book[i].book_name == b1.book_name)
		{
			while (1)
			{
				if (book[i].book_num - b1.book_num < 0)
				{
					cout << "库存不能小于0，请重新输入：";
					while (1) {
						cout << "请输入减少的数量:";
						cin >> b1.book_num;
						if (b1.book_num >= 0) {
							break;
						}
						cout << "数量不能小于0!!!请重新输入" << endl;
					}

					continue;
				}
				else if (book[i].book_num - b1.book_num == 0)
				{
					book.erase(book.begin() + i);
					return void();
				}
				book[i].book_num -= b1.book_num;
				break;
			}
			return void();
		}
	}
	cout << "仓库没有这本书!!!" << endl;
	system("pause");
}
void Manager::add_reader()
{
	Reader r1;
	r1.reader_add();
	int n = reader.size();
	for (int i = 0; i < n; i++)
	{
		if (reader[i].reader_number == r1.reader_number)
		{
			cout << "与其他读者重复，添加失败" << endl;
			system("pause");
			return void();
		}
	}
	reader.push_back(r1);
}
void Manager::delete_reader()
{
	Reader r1;
	r1.reader_delete();
	int n = reader.size();
	for (int i = 0; i < n; i++)
	{
		if (reader[i].reader_number == r1.reader_number)
		{
			reader.erase(reader.begin() + i);
			return void();
		}
	}
	cout << "该校没有该读者!!!" << endl;
	system("pause");
}
void Manager::book_all()
{
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	if (book.size() > 0)
	{
		for (int i = 0; i < book.size(); i++)
		{
			book[i].book_info();
		}
	}
	else
	{
		cout << "空空如也......." << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}
void Manager::reader_all()
{
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	if (reader.size() > 0)
	{
		for (int i = 0; i < reader.size(); i++)
		{
			reader[i].reader_info();
		}
	}
	else
	{
		cout << "空空如也......." << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}
void Manager::read()
{
	string name;
	int number;
	Book b1;
	ifstream in("book.txt", ios::in);
	if (!in)
	{
		cerr << "文件未找到" << endl;
		system("pause");
		exit(1);
	}
	while (in >> name >> number)
	{
		b1.book_name = name;
		b1.book_num = number;
		book.push_back(b1);
	}
	in.close();
	ifstream in1("reader.txt", ios::in);
	string numbe;
	int size;
	if (!in1)
	{
		cerr << "文件未找到" << endl;
		system("pause");
		exit(1);
	}
	while (in1 >> numbe >> name >> size)
	{
		Reader r1;
		r1.reader_number = numbe;
		r1.reader_name = name;
		for (int i = 0; i < size; i++)
		{
			in1 >> b1.book_name >> b1.book_num;
			r1.reader_book.push_back(b1);
		}
		reader.push_back(r1);
	}
	in1.close();
}
void Manager::save()
{
	ofstream out("book.txt", ios::out);
	int n = book.size();
	if (!out)
	{
		cerr << "文件未找到" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		out << book[i].book_name << ' ' << book[i].book_num << '\n';
	}
	out.close();
	ofstream out1("reader.txt", ios::out);
	n = reader.size();
	if (!out1)
	{
		cerr << "文件未找到" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		out1 << reader[i].reader_number << ' ' << reader[i].reader_name << ' ' << reader[i].reader_book.size() << ' ';
		for (int j = 0; j < reader[i].reader_book.size(); j++)
		{
			out1 << reader[i].reader_book[j].book_name << " " << reader[i].reader_book[j].book_num << " ";
		}
		out1 << '\n';
	}
	out1.close();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
