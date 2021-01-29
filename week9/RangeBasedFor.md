# range-based-for (범위 기반 for)

## range-based-for
  - 시작과 끝점을 알려주지 않아도 처음부터 끝까지 알아서 순회하는 반복문

```cpp
/*
for( 데이터 타입(or auto) elem : 배열명){
  elem을 이용한 연산
}
*/

// 기존의 for문 연산
int arr[10] = {1, 2, 3, 4 ,5 ,6 ,7, 8, 9, 10};

for(int i=0; i<10; ++i){
  cout << arr[i] << endl;
}

// ranged-based-for 문 연산
for(auto it : arr){
  cout << it << endl; 
}
```

## range-based-for문의 특징
  - 특정 인덱스에 대한 연산을 수행하기 어려울 수도 있다.
  - **배열 내부의 값을 변경할 수 없다.(단순한 값의 복사가 일어난다.)**
    - 배열 속 원래 주소에 접근할 수 없다.
    - 복사비용이 발생한다.

```cpp
for(auto it : arr){

  cout << it << endl;
  // 배열 내부의 값 변경이 불가능한 이유는 arr의 각 index의 값들을 순회하면서 it이 받아오는 것이기 때문이다.
  // it = arr[0], it = arr[1], it = arr[2] ... 의 연산들이 진행되는 것이다.
  
}
```

## 값 변경이 필요한 경우 해결방법
  - **데이터타입& elem 의 형식 사용**
    - 주소로 배열 내부에 직접 접근할 수 있다.
    - 복사비용이 발생하지 않는다.

```cpp
for(auto& it : arr){
  
  it += 10;
  cout << it << endl;
   
}
```

## 값 변경이 필요하지 않지만, 복사비용을 줄이고 싶은 경우 해결방법
  - **const 데이터타입 &elem 의 형식 사용**
    - 주소로 배열 내부에 직접 접근할 수 있지만, 값의 변경은 불가하다.
    - 복사비용이 발생하지 않는다.

```cpp
for(auto it : arr){

  // it += 10;
  // const 선언을 했기에 불가능하다.
  cout << it << endl;
  
}
```









