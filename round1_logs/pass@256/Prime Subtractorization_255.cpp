
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

const int MX = 10000001;
vector<int> isprime(MX);

vector<int> primes;
void SieveOfEratosthenes(int N) {
  for(int i = 2; i <= N; i++) isprime[i] = true;

  for(int i = 2; i * i <= N; i++) {
    if(isprime[i] == true) {
      for(int j = i * i; j <= N; j += i) isprime[j] = false;
    }
  }

  for(int i = 2; i <= N; i++) 
    if(isprime[i]) primes.push_back(i);
}

int main() {
  int T;
  cin >> T;
  SieveOfEratosthenes(MX);
  
  vector<int> differences;
  for(int i = 1; i < primes.size(); i++){
    differences.push_back(primes[i] - primes[i - 1]);
  }
  int sz = differences.size();
  int additional_differences[] = {-2,-1,0,1};
  for(int i : additional_differences) differences.push_back(i);

  for (int t = 1; t <= T; t++) {
    long long N;
    cin >> N;
    int count = 0;
    for(int i = 1; i <= sz && primes[i] <= N; i++) {
      if(primes[i] <= N && isprime[N - primes[i]] && binary_search(differences.begin(), differences.end(), N-primes[i]-primes[i-1]))
        count++;
    } 
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
