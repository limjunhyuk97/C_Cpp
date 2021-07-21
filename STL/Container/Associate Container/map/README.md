# MAP

<img src="https://user-images.githubusercontent.com/59442344/123595670-22dcfa00-d82c-11eb-9266-74bf71a68eca.png" width=100% height=100%>

  - [출처(https://codecollector.tistory.com/714)](https://codecollector.tistory.com/714)


## 1. Map 이란?
  - key와 value 쌍의 자료구조를 저장하고 있는 트리이다.
  - key 값의 중복을 허용하지 않는다.
  - 내부 구현은 balanced tree인 red-black tree로 구현되어 있다.

## 2. Map 자료구조
  - map<key_type, value_type> map이름

## 3. Map 정렬
  - default : key 기준의 오름차순 정렬이다.
  - 사용자 지정 방식에 따라 다른 순서로 정렬될 수 있다.
    - map<int, int, greater> : 내림차순 정렬

## 4. map, set, list, vector, hash map

### 4.1 map, set : 삽입, 삭제, 탐색 = O(logN)
### 4.2 list : 삽입, 삭제 = O(1), 탐색 = O(N)
### 4.3 vector : 삽입, 삭제, 탐색 = O(N), 임의 원소 접근 = O(1)
### 4.4 map VS hashMap

|Map|Hash Map|
|:---:|:---:|
|BST(red-black tree)|array(hashing)|
|자료가 정렬되어 저장|자료가 정렬되지 않고 저장|
|O(logN) 탐색속도|O(1) 탐색속도|

### 4.5 set VS map

|set|map|
|:---:|:---:|
|key 값만을 저장할 때 사용|key-value 쌍을 저장할 때 사용|

## 5. Map 사용방식

### 5.1 key-value 쌍 추가
  - [] operator 이용 : [key]에 해당하는 value 값을 부여
  - .insert() 이용 : insert( pair 객체 )를 통해서 key, value 쌍을 pair 객체로 추가

```cpp
// key(string) - value(pair<string, int> 쌍)
typedef map<string , pair<string ,int> > profile;

profile parent;
// [] operator의 이용
parent[key] = { name, 1 };
parent[key] = pair<string, int>(name, 1);
parent[key] = make_pair(name , 1);

// .insert()의 이용
parent.insert( name, {name, 1} );
parent.insert( name, pair<string, int>(name, 1) );
parent.insert( pair<string, pair<string, int> >(name, pair<string, int>(name, 1)) );
```

### 5.2 key의 존재여부 확인
  - .count(key) : key가 존재한다면 1 값 반환, key가 존재하지 않으면 0 값 반환
  - .find(key) : key가 존재한다면 key의 iterator 값 반환

```cpp
// 만약 parent에 name이라는 key가 존재하지 않는다면, insert 해라.
profile::iterator iter = parent.find(name);
if (iter == parent.end()) parent.insert(pair<string, pair<string, int> >(name, pair<string, int>(name, 1)));
```
