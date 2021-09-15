# std::array<type, size>
  - 클래스 템플릿
  - 메모리를 자동으로 할당, 해제.
  - 각 배열 공간들을 기본적으로 0으로 초기화
  - 변경가능하지 않은 const로 선언할 수 있다.


## 01. 원소 접근
  - [] 연산자를 통한 접근 : 인덱스 밖으로 접근하더라도 오류 발생 안함
  - at() 함수를 통한 접근 : 인덱스 밖으로 접근 시 오류 발생
  - data() 함수를 통한 접근 : data()함수는 배열의 첫번째 메모리 버퍼를 가리킨다. 마치, c에서 배열명이 첫 공간을 가리키는 것처럼 활용할 수 있다.

```cpp
int main(void){

    array<int, 10> arr;
    
    // 오류 발생
    arr.at(12) = 5;
    
    // 오류 발생X
    arr[12] = 5;
    
    // 3번째 공간에 10 넣기
    *(arr.data() + 2) = 10;
  
    for(auto i : arr)
        cout << i << endl;
    
    return 0;
}
```


## 02. 함수 전달
  - 전달받을 배열 크기 고정할 수도 있고, 고정하지 않을 수도 있다.
  - 배열을 배열을 전달할 때는 깊은 복사가 이뤄지도록 설정되어 있다.
  - const를 이용해서 배열에서의 값 변경이 일어나는 것을 방지할 수 있다.

```cpp
// 전달 받을 배열크기 고정
void print(array<int, 10> arr){
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}

// 전달 받을 배열크기 고정X
// <typename T> : 어떤 타입이 오는지 미리 정하지 않는다
// <size_t T> : 어떤 사이즈가 올지 미리 정하지 않는다
template <size_t T>
void print(array<int, T> arr){
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}

// << 연산자 오버로딩
template<size_t T>
ostream& operator<<(ostream &ostm, array<int, T> arr){
    for(auto i :  arr)
        cout << i << " ";
    return ostm;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    array<int, 10> arr;
    arr[2] = 1;
    arr[3] = 5;
    
    print(arr);
    cout << arr << endl;
    
    return 0;
}
```

## 03. 배열 순회
  - auto를 이용한 배열 내 전부 순회
  - 인덱스 기반의 배열 내 순회
  - begin(), end(), rbegin, rend() 반복자를 활용한 배열 내 순회
    - const array에 대해서는 const_iterator가 생성됨
    - reverse_iterator를 사용할 수도 있다.

```cpp
// 연산자 오버로딩 및, reverse_iterator 사용
template<size_t T>
ostream& operator<<(ostream &ostm, array<int, T> arr){
    for(auto i = arr.rbegin(); i != arr.rend(); ++i)
        cout << *i << " ";
    return ostm;
}
```
