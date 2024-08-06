bool CanMake(int num, int target) {
  if (target < 0 || num < target) {
    return false;
  }
  if (num == target) {
    return true;
  }
  return CanMake(num / 10, target - num % 10) || CanMake(num / 100, target - num % 100) ||
      CanMake(num / 1000, target - num % 1000);
}

class Solution {
public:
  int punishmentNumber(int n) {
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
      int num = i * i;
      if (CanMake(num, i)) {
        answer += num;
      }
    }
    return answer;
  }
};