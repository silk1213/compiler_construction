int square (int a) {
	if (a == 0) {
		a++;
	} else {
		a--;
	}
	double y = 0.1;
	int b = 0;
        b = a - b;
	return a*b;
}

void test(int a, int b) {
	a++;
	
	return ;
}

int main () {
	int a = 1;
	int b = 2;
	
	{
		int a;
		a++;
		int c;
		test(a,b);
	}
	{
		int a1;
		int b;
		int c;
	}
	a++;

	
	return a;
}
