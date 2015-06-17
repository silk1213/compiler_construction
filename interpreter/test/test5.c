int test (int a) {
	int b = a*a;
	return b;
}

void test2 (int a) {

}


int main (){
	int b = 2;
	int a = test(b);
	test2(b);
	double f = 0.0;
	f = 0.0;

	while (b > 0) {
		test(b);
		int c = b--;
		b = c;
	}
	return a;
}
