#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_VAL=1000001;
vector<int> prime(MAX_VAL,1);
vector<int> num_divisors(MAX_VAL,0);
vector<int> prefix(MAX_VAL,0);
//-------------------------------------------
void sieve(){
  prime[0]=prime[1]=0;
  for(int i=2;i*i <= MAX_VAL;++i){
    if(prime[i]){
      for(int j=i*i;j <= MAX_VAL;j+=i){
        prime[j]=0;
      }
    }
  }
}
//-------------------------------------------
// sang dem uoc cac so tu 1 den MAX_VAL
void demuoc(){
  for(int i=1;i <= MAX_VAL;++i){
    for(int j=i;j <= MAX_VAL;j+=i){
      num_divisors[j]++;
    }
  }
}
//-------------------------------------------
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("CAU3.inp","r",stdin);
  /* freopen("CAU3.out","w",stdout); */
  int n;
  cin >> n;
  sieve();
  demuoc();
  // tao mang cong don
  for(int i=1;i <= MAX_VAL;++i){
    if(prime[num_divisors[i]]){
      prefix[i]=prefix[i-1]+1;
    }else{
      prefix[i]=prefix[i-1];
    }
  }
  int a,b;
  ll res=0;
  while(n--){
    cin >> a >> b;
    res+=prefix[b]-prefix[a-1];
  }
  cout << res;
  return 0;
}
