## 개선 요구 사항
 1. 맞는 자료형이 들어오지 않을 경우 무한루프 // 해결O
 2. hash collision 방지를 hash bucket 으로 하기 -> 동적 2차원 배열을 통해서 -> vector 배열을 통해서 구현 // 해결O
 3. 비슷한 역할 하는 코드를 하나의 덩어리로 묶어서 기능 분화 -> 의존도 떨어뜨리기 -> namespace 구성 -> 고객정보 class와, 거래행위 관련 class 따로 묶어서 namespace 구현. // 해결O
 4. 헤더파일을 만들어서 파일을 더 보기 좋게 만들기. -> // 해결O
 5. 없는 계좌 입력 시에 문제 발생 -> // 해결O
 6. \*iterator의 함수 반환 방법 -> 그냥 index를 반환하는 함수로 바꿈 // 우회O

## 새로 알게 된 사항
 1. **'Customer' class 자료형을 반환형으로 쓰려**했더니 **객체의 생성처럼 받아들이는 문제** 발생한 것 같음.
 2. C++는 위에서 아래로 읽어들이기에, **class가 사용되기 전, 위쪽에 정의해주지 않으면 에러 발생.**
    - 전방 선언이라는 것이 있는 것을 알게됨 : 전방 선언은 class 포인터 형태로 사용할 때만 가능하다는 것을 알게됨.
 3. **서로 다른 헤더파일에 있는 class 두개가 서로를 사용**하고 있을 경우, **각각의 헤더파일에 서로의 헤더파일을 선언하면 무한루프**에 빠지게 됨
    - 이때, 전방 선언이라는 것을 사용한다고 함.
    - 근데 **애초에 이렇게 짜는 것이 문제.**
 4. **namespace 안에 특정 class가 정의 되있지 않으면 그 class를 사용자 정의 자료형으로 이용할 수 없더라..**
 5. **class의 헤더파일, cpp 파일 파일 분리법** 알게 됨.
    - 헤더파일에는 class의 멤버변수, 멤버함수에 대한 선언이 들어가야 하고 + 필요한 기본 헤더들도 include(#pragma once 위에)
    - cpp파일에는 class 멤버함수들의 정의가 들어가야 한다. + 헤더파일 ".h" include 해주고 + 필요한 기본 헤더들도 include(#pragma once 위에)
    - 분리된 파일에는 using namespace std; 쓰는 것이 좋지 않다고 함.
      - string , vector 같은 경우 번거롭지만 std::string std::vector처럼 일일이 표현해주는 것이 더 안전함.
 6. **헤더파일이 include 되지 않는 경우!**
    - 헤더파일이 저장되어 있는 위치가 다른 파일들과 같은 위치인가를 확인해준다. (그렇지 않으면 include 되지 않음!)
 7. **cin의 입력에러** 해결 방법
    - **while과 cin 같이 사용**했을 때, **잘못된 자료형이 들어오면 무한루프**에 빠짐!
    - **cin.fail()** / **cin.clear()** / **cin.ignore()** 로 해결 가능하다.
```cpp
int tmp;
cin >> tmp; (문자형이 들어온 경우!)
while(1){
   if(cin.fail()){
      cin.clear();	// 에러비트를 초기화 시킴. cin.fail()의 값을 거짓으로 바꿈.
      cin.ignore(256, '\n');	// 입력 버퍼를 제거함. 버퍼를 비워야 loop 했을 때 cin에 아무것도 들어오지 않으므로 해결됨.
      ...
   }
}
```
   - **cin.fail()**
      - 잘못된 입력이 들어오면 true를 반환
   - **cin.clear()**
      - 에러비트를 초기화 시킨다. cin.fail()을 false로 바꿈
   - **cin.ignore(읽어들일 문자 갯수, '종료지점문자')**
      - 읽어들일 문자 갯수만큼 최대로 읽어들이고, 종료지점 문자가 나오면 포함해서 입력버퍼에서 제거한다.
 8. **namespace의 효력범위**
    - 