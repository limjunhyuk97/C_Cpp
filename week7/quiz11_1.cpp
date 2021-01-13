#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	void Shot() {
		cout << "BBANG!" << endl;
		--bullet;
	}
	int GetBullet() const { return bullet; }
};

class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int handcuffs, int bnum) :handcuffs(handcuffs) {
		if (bnum > 0) {
			pistol = new Gun(bnum);
		}
		else pistol = NULL;
	}

	// 복사 생성자 정의
	Police(const Police& ref) : handcuffs(ref.handcuffs) {
		if (ref.pistol == NULL)
			pistol = NULL;
		else pistol = new Gun(*(ref.pistol));
		// TNlqkf 복잡하구나..
		// 1. ref.pistol : class Police 바탕의 ref객체의 , 멤버변수인 Gun 바탕의 pistol 객체 포인터
		// 2. *(ref.pistol) : class Police 바탕의 ref객체의 , 멤버변수인 Gun 바탕의 pistol 객체 포인터가 가리키는 Gun 객체
		// 3. new Gun(*(ref.pistol)) : Gun( Gun 객체 )는 복사생성자 호출이다. 결국, ref객체 안의 Gun 객체의 포인터를 new를 통해서 pistol 객체로 할당함.
    // 결론. 굳이, Gun 객체에 GetBullet 같은 함수 추가하지 않아도 된다. 복사생성자의 원리를 차분하게 생각해보자~
    // 예시. AAA *aObj = new AAA(bObj); 과 비슷한 상황 aObj에 bObj와 같은 객체 들어가게 됨.
	}

	// 대입 연산자 정의
	Police& operator=(const Police& ref) {
		
		handcuffs = ref.handcuffs;
		if (pistol == NULL) {
			if(ref.pistol !=NULL) {
				pistol = new Gun(*(ref.pistol));
			}
		}
		else {
			delete pistol;
			if (ref.pistol != NULL) {
				pistol = new Gun(*(ref.pistol));
			}
			else pistol = NULL;
		}
		return *this;
	}

	void PutHandcuff() {
		cout << "SNAP" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "아무것도.." << endl;
		else pistol->Shot();
	}
	void ShowAllInfo() {
		cout << "handcuffs : " << handcuffs << ", bulltes : " << pistol->GetBullet() << endl;
	}
	~Police() {
		delete pistol;
	}

};
