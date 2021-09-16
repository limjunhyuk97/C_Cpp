#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// 특정 자료형의 동적 배열 생성을 위한 정의
template<typename T>
class dynamic_array{
private:
    T* data;
    size_t n;
    
public:
    // 생성자
    dynamic_array(int n = 0) : n(n){
        data = new T[n];
    }
    
    // 복사 생성자
    dynamic_array(const dynamic_array<T> &other){
        n = other.n;
        data = new T[n];
        
        for(int i=0; i<n; ++i)
            data[i] = other.data[i];
    }
    
    // [] 연산자 오버로딩
    T& operator[](int idx){
        return data[idx];
    }
    
    // const dynamic_array에 대한 [] 연산자 오버로딩
    const T& operator[](int idx) const{
        return data[idx];
    }
    
    // size() 반환
    size_t size() const{
        return n;
    }
    
    // 반복자를 위한 함수들 정의
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n;}
    
    // dynamic_array 합치는 + 연산자 정의 (friend를 사용해서 외부에서 정의하는 것처럼 정의 가능)
    friend dynamic_array<T> operator+(const dynamic_array<T> & arr1, const dynamic_array<T> & arr2){
        dynamic_array<T> new_array(arr1.size() + arr2.size());
        copy(arr1.begin(), arr1.end(), new_array.begin());
        copy(arr2.begin(), arr2.end(), new_array.begin() + arr1.size());
        return new_array;
    }
    
    // 배열 내의 원소들을 특별한 구분자를 통해 구분하여 string으로 반환해주는 to_string() 멤버 함수를 작성
    string to_string(const string& sep = ", "){
        
        if(n == 0) return "";
        
        // ostringstream ss
        ostringstream oss;
        oss << data[0];
        
        for(int i=1; i<n; ++i)
            oss << sep << data[i];
        
        return oss.str();
        
    }
    
    ~dynamic_array(){
        delete []data;
    }
};
