int main () {
	bool a, b, c, d, e, f;
	a = b = c = d = e = f = true;
	int h = 0;	

	while (a && b && c && d || e || f ) {
		h++;
	}
	
	return h;
}
