#

1) 함수 입출력 
 - std::cout
 - std::cin
 - std::enl
 
2) 함수 오버로딩 ( function overloading )
 - 함수 이름과, 전달받는 인자의 자료형과 갯수의 종류에 따라서 함수 구분 가능하다
 
3) 매개변수 디폴트 값 ( default value )
 - 인자가 아무것도 받지 않을 경우 기본적으로 받는 값을 지정할 수 있다.
 - default value는 오른쪽부터 채워넣어주어야 한다.
 - 또한 default value는 함수 선언 부에만 위치시켜주면 된다.
 
4) 인라인 함수 ( inline function )
 - 매크로 함수 진화 -> 복잡한 정의가 가능해지고, 속도가 빨라진다. (함수 오버헤드 현상을 방지한다.)
 - 컴파일러에 의해서 처리 된다. 컴파일러의 판단에 따라, 무시되기도하고, 처리되기도 한다.
 - 템플릿을 사용하지 않으면 자료형 손실이 발생할 수 있다.
 
5) 네임스페이스 ( namespace )
 - 이름의 충돌을 막기 위해 등장하였다.
 - :: 은 범위 지정 연산자이다. (살짝 js에서 객체를 부르는 느낌인 것같다.. 아직까지는!)
 - namespace 사용 시에 선언과 정의는 분리해 주는 것이 좋다.
 - namespace 안에 namespace가 있을 수 있다 - namespace의 중첩
 - 사용
   - using A::B;                    A속의 B를 그냥 앞으로 B라고 써라
   - using namespace A              A속의 것들 그냥 써라 , using namespace std;
   - namespace ABC = A::B::C;       A::B::C::? 를 ABC::?로 써라!
   - ::val                          전역변수에 접근시켜줘라!
