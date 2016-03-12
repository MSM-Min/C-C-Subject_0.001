

//project:  GeekBand c++ /the two week homework
//author:   小江71122175 
//file      rectangle.h

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <iostream>
using namespace std;
//-------------------------------------------------
class Shape
{                   
    int no_;
	static int order_;
	static int total_; 
public:
	Shape() { ++total_; no_ = ++order_; } 
	~Shape() { --total_; }
	int getNo() const { return no_; }
	static int ShapeTotal() { return total_; }
};  
int Shape::order_ = 0;
int Shape::total_ = 0;


//-------------------------------------------------            
class Point
{
public:
    Point(int x = 0, int y = 0): x_(x), y_(y) { }
    int getX() const { return x_; }
    int getY() const { return y_; }
private:
    int x_;
    int y_;
};    


//---------------------------------------------------          
class Rectangle: public Shape
{
public:
    Rectangle(int width, int height, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();  
    
    int getWidth() const { return width_; }    
	int getHeight() const { return height_; }    
	Point* getLeftUP() const { return leftUp_; }
	
private:
    int width_;
    int height_;
    Point* leftUp_;        
};

//----------------------------------------------------
//构造函数 
inline
Rectangle::Rectangle(int width = 0, int height = 0, int x = 0, int y = 0)
:width_(width), height_(height)
{
    leftUp_ = new Point(x,y);
}


//---------------------------------------------------  
//拷贝构造函数
inline 
Rectangle::Rectangle(const Rectangle& other): width_(other.width_), height_(other.height_) {
    leftUp_ = new Point(*(other.leftUp_));
	if(other.leftUp_ != NULL)
		leftUp_ = new Point(*(other.leftUp_));
	else{
		leftUp_ = NULL;	
    }
}



//---------------------------------------------------  
//拷贝赋值函数
inline
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if(this == &other)
    {
        return *this;
    }
   	width_ = other.width_;
	height_ = other.height_;
	
    if (leftUp_ != NULL) {
		if (other.leftUp_ != NULL) {  
			*leftUp_ = *(other.leftUp_);
		} else {
			delete leftUp_;
			leftUp_ = NULL;
		}
	} else {
		if (other.leftUp_ != NULL){
			leftUp_ = new Point(*(other.leftUp_));
		}
	}	
	return *this;

}


//---------------------------------------------------  
//赋值操作符 
ostream& operator<<(ostream& os, const Rectangle& rect) {
	os <<(rect.getNo())<<"\t"<<(rect.getLeftUP()->getX())<<"\t"<<(rect.getLeftUP()->getY())<<"\t"<<(rect.getWidth())<<"\t"<< (rect.getHeight())<<endl;
}


//---------------------------------------------------  
//析构函数
inline
Rectangle::~Rectangle() {
    delete leftUp_;
	leftUp_ = NULL;
} 

#endif
