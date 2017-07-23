/******************************************************************************************
**project:  为 Rectangle 类实现构造函数,拷贝构造函数,赋值操作符,析构函数.
**author:   Joel Jiang  
**file      main.c
******************************************************************************************/
#include "rectangle.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{ 
    Rectangle r1(3,3,2,3);
	Rectangle r2; 
	Rectangle r3(r1);
	Rectangle r4;
	r4 = r2;
	
	cout << "Current total of shapes: " << Shape::ShapeTotal() << endl;
	cout << "No\tX\tY\tWidth\tHight" << endl;
	cout << r1 << r2;
	cout << r3;
	cout << r4;
	cout << "**************************************************" << endl;
	{
		Rectangle r5 = Rectangle(2,2,3,4);
		Rectangle r6 = r3;
		Rectangle r7(r2);
		Rectangle r8;
		r8 = r1;
		cout << "The total of shapes: " << Shape::ShapeTotal() << endl;
		cout << "No\tX\tY\tWidth\tHight" << endl;
		cout << r1 << r2 << r3 << r4 << r5 << r6 << r7 << r8;
	}
	cout << "**************************************************" << endl;
	Rectangle r9(3,3,4,5);
	cout << "The total of shapes: " << Shape::ShapeTotal() << endl;
	cout << "No\tX\tY\tWidth\tHight" << endl;
	cout << r1 << r2 << r3 << r4 << r9;
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
//end file main.c
