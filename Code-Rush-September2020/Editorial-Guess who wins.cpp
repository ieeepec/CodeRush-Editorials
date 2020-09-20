#include <cmath> 
#include <cstdio> 
#include <vector> 
#include <iostream> #include <algorithm> 
using namespace std; 
int main() {
 int T; 
cin >> T;
 int n; 
int balls; 
string result[2] = {"Lauren\n", "Susan\n"};
while(T--) 
{ 
cin >> n; 
int Xor = 0; 
for(int i = 0; i < n; ++i)
{ 
cin >> balls; 
if(balls & 1) { 
Xor ^= i; } 
}
cout << result[Xor == 0]; 
} 
return 0; 
}