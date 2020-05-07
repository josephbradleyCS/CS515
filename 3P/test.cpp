#include <iostream> // cout, cerr
#include <algorithm>
using namespace std;
int main(){

int tmp[9] = {9,8,7,6,5,4,3,2,1};
sort( tmp, tmp+8);

for( int a = 0; a < 9; a++){
  cout << tmp[a];
}


}
