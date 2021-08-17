#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

// 10자리 비트로 이루어진 수 N을 선언한다.
bitset<10> N, M;

/*
 bitset<>
 all()
 any()
 none()
 set()
 set(n)
 reset()
 reset(n)
 flip()
 flip(n)
 cin <<
 = & | ^ ~(1의 보수) << >> []
 to_string()
 to_ulong()
*/

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    // reset() : set all bit 0
    // reset(n) : set n bit 0
    N.reset();
    cout << N << endl;
    N.set(3);
    cout << N << endl;
    
    // all() : 모두 1?
    cout << N.all() << endl;
    
    // any() : 1 존재?
    cout << N.any() << endl;
    
    // none() : 모두 0?
    cout << N.none() << endl;
    
    // set() : set all bit 1
    // set(n) : set n bit 1
    N.set();
    cout << N << endl;
    N.reset(4);
    cout << N << endl;
    
    // flip() : flip all bit (0 -> 1, 1 -> 0)
    // flip(n) : flip n bit (0 -> 1, 1 -> 0)
    N.flip(8); N.flip(4);
    cout << N << endl;
    
    // test(n) : n 번째 bit 1 이면 true(1), 0 이면 false(0)
    cout << N.test(8) << " " << N.test(2) << endl;
    
    // cin >> : 2진수 형식으로 입력한다 + n자리 bitset이라면, n자리 이내의 2진수 형식으로 입력해야 한다.
    cin >> N;
    cout << N << endl;
    
    // = 연산 : n진수 형식으로 입력한다 + n자리 bitset이라면, n자리 2진수로 표현가능한 범위 내의 값을 대입해야 한다.
    N = 0x3;
    cout << N << endl;
    cout << ~N << endl;
    cout << N.to_ulong() << endl;
    
    return 0;
}
