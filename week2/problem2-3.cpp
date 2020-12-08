#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct __point{
	int xpos;
	int ypos;
} Point;

Point & PntAdder(const Point &p1, const Point &p2){	// 매개변수로 pointer 선언하는 것과, 참조자 선언하는 것 헷갈리지 않기
	
	Point *aP = new Point;
	(*aP).xpos = p1.xpos + p2.xpos;
	(*aP).ypos = p1.ypos + p2.ypos;
	
	return *aP;	// Point struct의 참조자 전달. * pointer로 명시해야 포인터가 지시하는 struct 자체의 값을 가리키는 것.
}

int main(void){
	
	Point *p1 = new Point;
	Point *p2 = new Point;
	Point *p3 = new Point;
	cout << "첫번째 점의 x 값 : ";
	cin >> p1->xpos;
	cout << "첫번째 점의 y 값 : ";
	cin >> p1->ypos;
	cout << "점 1 (x,y) : ("<< p1->xpos <<","<<p1->ypos<<")"<<endl<<endl;  
	
	cout << "두번째 점의 x 값 : ";
	cin >> p2->xpos;
	cout << "두번째 점의 y 값 : ";
	cin >> p2->ypos;
	cout << "점 2 (x,y) : ("<< p2->xpos <<","<<p2->ypos<<")"<<endl<<endl;
	
	*p3 = PntAdder(*p1, *p2);	// 참조자 매개변수의 인자로 전달할때, * pointer를 써서 동적할당된 struct의 내부 값들 전달.
	
	cout << "더해진 점의 x 값 : " << p3->xpos << endl;
	cout << "더해진 점의 y 값 : " << p3->ypos << endl;
	cout << "더해진 점 (x,y) : ("<< p3->xpos <<","<<p3->ypos<<")"<<endl;
	
	delete p1;	// new 로 선언된 것들은 반드시 delete로 해제시켜주기.
	delete p2;
	delete p3;
	
	return 0;
}
