//NIM游戏
//桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
class Solution {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
};