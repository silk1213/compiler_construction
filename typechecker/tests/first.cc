//This is just a test

int square(int a) {
	int b = a;
	return a*b;
}

int main()
{
	int a,b,c;
	double x,d;
	{
		int a,b,c;
		b = 9;
		c = 9;
		a = b + c;
	}
	{
		double x,d;
		x = 1.3;
		{
			x = 1.5;
		}
		d = x;
	}

	a = 89;
	a = square(a);
	return 0;
}
