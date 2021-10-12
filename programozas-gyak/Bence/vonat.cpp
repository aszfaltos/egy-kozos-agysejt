#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  int K;
  cin >> N >> K;
  int M[N];
  int count = 0;
  for (size_t i = 0; i < N; i++) {
    cin>>M[i];
    if (M[i] < K) {
      count++;
    }
  }
  int trains[count+1];
  trains[0] = count;
  count = 1;
  for (size_t i = 0; i < N; i++) {
    if (M[i] < K) {
      trains[count] = i+1;
      count++;
    }
  }

  for (size_t i = 0; i < count; i++) {
    cout<<trains[i]<<" ";
  }



  return 0;
}
