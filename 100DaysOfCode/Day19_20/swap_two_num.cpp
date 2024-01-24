void swapNumber(int &a, int &b) {
	// Write your code here.

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}