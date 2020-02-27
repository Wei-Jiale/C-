//4µÄÃÝ
class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num == 1){
			return true;
		}
		long min = 4;
		while (min <= num){
			if (min == num){
				return true;
			}

			min *= 4;

		}
		return false;
	}
};