#include <iostream>


void printArray(int n, int m, int *ptr)
{
	for(int i = 0; i < n; i++){
		std::cout << "[";
		for(int j = 0; j < m; j++){
			std::cout << " " << *ptr;
			ptr += 1;
		}
		std::cout << " ]" << std::endl;
	}
}

double getDeterminant(int n, int *p)
{
	double result = 0;
	if(n == 1 || n == 2)
	{
		if(n == 1)
			result = *p;

		else
		{
			int a, b, c, d;
			a = *p;
			b = *(p + 1);
			c = *(p + 2);
			d = *(p + 3);
			result = (a * d) - (b * c);
		}
	}
	else
	{
		int l, m, sign, basic, element, inner_solution;
		m = 0;
		sign = 1;
		int *q;
		q = new int[(n - 1) * (n - 1)];

		for(int i = 0; i < n; i++)
		{
			basic = *(p + i);
			l = 0;
			m = 0;
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					element = *(p + l);
					//std::cout << element << " ";
					if(j == 0 || i == k);
					else
					{
						*(q + m) = element;
						m += 1;
					}
					l += 1;
				}
			}
			std::cout << std::endl << basic << " x " << std::endl;
			printArray(n - 1, n - 1, q);

			double inner_determinant = getDeterminant(n - 1, q);
			inner_solution = sign * basic * inner_determinant;

			std::cout << "(Sign: " << sign << " * Basic: " << basic << " * Determinant: " << inner_determinant << ") = " << inner_solution << std::endl;
			result += inner_solution;
			sign *= -1;
		}
		delete [] q;
	}
	return result;
}

void initializeArray(int n, int m, int *ptr){
	int k;
	std::cout << "Enter matrix: " << std::endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			std::cin >> k;
			*(ptr + i * m + j) = k;
		}
		std::cout << std::endl;
	}
}

int main()
{
	int *p, r;
	std::cout << "Enter number of rows and columns: " << std::endl;
	std::cin >> r;

	p = new int [r * r];

	initializeArray(r, r, p);
	printArray(r, r, p);
	double result  = getDeterminant(r, p);
	std::cout << std::endl;
	std::cout << "Determinant: " << result << std::endl;
	delete [] p;

	return 0;
}
