int main () {
	int a = 1;
	int b = 0;
	bool g = true;
	
	if (g) {
		a = 7;
		g = false;
	} else {}

	if (a<1 && b == 0) {
		a++;
	} else {
		a--;
	}
	
	return a;
}
