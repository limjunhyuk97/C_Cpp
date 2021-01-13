#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* mytitle, char* myisbn, int myprice) :price(myprice) {
		title = new char[strlen(mytitle) + 1];
		strcpy_s(title, strlen(mytitle) + 1, mytitle);
		isbn = new char[strlen(myisbn) + 1];
		strcpy_s(isbn, strlen(myisbn) + 1, myisbn);
	}
	// 복사 생성자
	Book(const Book& ref) :price(ref.price) {
		int titlelen = strlen(ref.title) + 1;
		int isbnlen = strlen(ref.isbn) + 1;
		title = new char[titlelen];
		strcpy_s(title, titlelen, ref.title);
		isbn = new char[isbnlen];
		strcpy_s(isbn, isbnlen, ref.isbn);
	}
	// 대입 연산자
	Book& operator=(const Book& ref) {
		delete[]title;
		delete[]isbn;
		price = ref.price;
		int titlelen = strlen(ref.title) + 1;
		int isbnlen = strlen(ref.isbn) + 1;
		title = new char[titlelen];
		strcpy_s(title, titlelen, ref.title);
		isbn = new char[isbnlen];
		strcpy_s(isbn, isbnlen, ref.isbn);
		return *this;
	}
	void ShowBookInfo() const {
		cout << "제목 : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "가격 : " << price << endl<<endl;
	}
	~Book() {
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(char* mytitle, char* myisbn, char* myDRMKey, int myprice) : Book(mytitle, myisbn, myprice) {
		DRMKey = new char[strlen(myDRMKey) + 1];
		strcpy_s(DRMKey, strlen(myDRMKey) + 1, myDRMKey);
	}
	// 복사 생성자
	// 어쨌든 Book(ref) 하면 함수 오버로딩 때문에 알아서 복사 생성자로 들어감!
	// Book 에서는 Book의 참조자로 인자를 설정해놨기에, 참조자 자료형 기준으로 연산이 진행되므로 상관없음!
	 EBook(EBook& ref) : Book(ref) {
		int DRMKeylen = strlen(ref.DRMKey) + 1;
		DRMKey = new char[DRMKeylen];
		strcpy_s(DRMKey, DRMKeylen, ref.DRMKey);
	}
	// 대입 연산자
	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[]DRMKey;
		int DRMKeylen = strlen(ref.DRMKey) + 1;
		DRMKey = new char[DRMKeylen];
		strcpy_s(DRMKey, DRMKeylen, ref.DRMKey);
		return *this;
	}

	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "인증키 : " << DRMKey << endl << endl<<endl;
	}
	~EBook() {
		delete[]DRMKey;
	}

};

int main(void) {

	struct BookFeature {
		char name[30];
		char isbn[30];
		int price;
		char drmkey[30];
	};

	BookFeature book1 = { "좋은 C++", "555-12345-890-0", 20000 }
		, book2 = {"에라 모르겠다", "5555-3333-444", 45000}
		, ebook1 = { "좋은 C++ ebook" , "555-12345-890-1" , 10000 , "fdx9w0i8kiw" }
		, ebook2 = { "안좋은 C++ ebook", "5555- 3333-22-11-1", 4000, "whatthe" }
		, ebook3 = { "9만해", "33-44444-222-11-5-3", 40000, "Holy" };
	
		Book Book1(book1.name, book1.isbn, book1.price), Book2(book2.name, book2.isbn, book2.price);
		Book1.ShowBookInfo();
		Book2.ShowBookInfo();
		Book1 = Book2;
		Book1.ShowBookInfo();
		Book2.ShowBookInfo();

		EBook EBook1(ebook1.name, ebook1.isbn, ebook1.drmkey, ebook1.price),
			EBook2(ebook2.name, ebook2.isbn, ebook2.drmkey, ebook2.price),
			EBook3(ebook3.name, ebook3.isbn, ebook3.drmkey, ebook3.price);

		EBook1.ShowEBookInfo();
		EBook2.ShowEBookInfo();
		EBook3.ShowEBookInfo();
		EBook3 = EBook2 = EBook1;

		EBook1.ShowEBookInfo();
		EBook2.ShowEBookInfo();
		EBook3.ShowEBookInfo();


	return 0;
}

/*
상속상황에서, 유도 class에서 기초 class의 멤버들에게 또한 복사한 내용을 할당하기 위해서 기초 class의 복사생성자와, 대입연산자를 호출 방법, 원리.
복사생성자 - 그냥 생성자이므로 호출하면 함수오버로딩에 의해서, 매개인자 종류에 따라 알아서 복사생성자 호출할 것임.
대입연산자 - 범위지정자를 이용해서 기초 class의 대입연산자를 호출.
 + 컴파일러는 포인터나 참조자의 자료형을 기준으로 연산을 진행한다. (virtual 선언이 없는한!)
*/
