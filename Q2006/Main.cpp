#include <vector>
using namespace std;
int countKDifference(vector<int>& nums, int k) {
  int pairs = 0;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    int pos = nums[i] + k;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] == pos) {
        pairs++;
      }
    }
  }
  return pairs;
}

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> nums{3, 2, 1, 5, 4};
  int k = 2;
  int pairs = countKDifference(nums, k);
  return 0;
}
