pair <double, double> quadratic(double a, double b, double c) {
	double square_root = sqrt(b * b - 4 * a * c);
	return {(-b + square_root) / 2 / a, (-b - square_root) / 2 / a};
}

double inv_tri(double n) {
	return (sqrt(8 * n + 1) - 1) / 2;
}

