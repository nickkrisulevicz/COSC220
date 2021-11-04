//Nick Krisulevicz
//Lab 2 part 3, findline.cpp
//09/21/2021

#include <iostream>
#include <cmath>
using namespace std;

class Point{
	private:
		float x;
		float y;
	public:
		Point(){
			x = 0;
			y = 0;
		}
		Point(float x1, float y1){
			x = x1;
			y = y1;
		}
		void setX(float xc){
			x = xc;
		}
		void setY(float yc){
			y = yc;
		}
		float getX()const{
			return x;
		}
		float getY()const{
			return y;
		}
		float operator+ (const Point p)const{
			float dist = 0;
			dist = sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
			return dist;
		}

};

class Line{
	private:
		Point b;
		Point e;
	public:
		Line();
		Line(Point& begin, Point& end){
			b = begin;
			e = end; 
		}
		void setBegin(Point& b){
			float xb;
			float yb;
			cout << "Enter X coordinate for begin point: " << endl;
			cin >> xb;
			cout << "Enter Y coordinate for end point: " << endl;
			cin >> yb;
			this->b.setX(xb);
			this->b.setY(yb);	
		}
		void setEnd(Point& e){
			float xe;
			float ye;
			cout << "Enter X coordinate for end point: " << endl;
			cin >> xe;
			cout << "Enter Y coordinate for end point: " << endl;
			cin >> ye;
			this->e.setX(xe);
			this->e.setY(ye);
		}
		float getLength() const{
			float distance = 0;
			distance = b + e;
			return distance;
		}
		float showCoordinate(){
			cout << "Begin point coordinates: " << endl;
			cout << b.getX() << ", " << b.getY() << endl;
			cout << "End point coordinates: " << endl;
			cout << e.getX() << ", " << e.getY() << endl;
			return 0;
		}
		
		 Line * makeLineArray(int size){
		 	cout << "You have called MakeLineArray function. " << endl;	 
			Line linearr[size];
			return linearr;
		 }
		 
};


int main(){
	Point start;
	Point finish;

	Line myline(start, finish);

	myline.setBegin(start);
	myline.setEnd(finish);

	myline.showCoordinate();

	cout << "Length from begin to end is: " << myline.getLength() << endl;
	
	int arrsize;
	cout << "Enter the size of the point array: " << endl;
	cin >> arrsize;

	Line linearray;
	linearray.makeLineArray(arrsize);
	for (int i = 0; i < arrsize; i++){
		linearray[i].setBegin(start);
		linearray[i].setEnd(finish);
	}
	for(int j = 0; j < arrsize; j++){
		linearray[j].showCoordinate();
	}



	return 0;
}
