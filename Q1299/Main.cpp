#include <iostream>
#include <vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    arr[i] = *max_element(arr.begin() + i + 1, arr.end());
  }
  arr[arr.size() - 1] = -1;
  return arr;
}

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> arr = {17, 18, 5, 4, 6, 1};
  vector<int> result = replaceElements(arr);
  return 0;
}
