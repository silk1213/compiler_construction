int main () {
	int a = 1;
	int b = 0;
	bool g = true;
	
	while (g) {
		if ( a > 7) {
			g = false;
		} else {
			a++;
		}
	}
	
	return a;
}
