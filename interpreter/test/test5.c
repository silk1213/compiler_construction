int test (int a) {
	int b = a*a;
	return b;
}

void test2 (int a) {

}


int main () {
	int b = 2;
	int a = test(b);
	test2(b);
	return a;
}
