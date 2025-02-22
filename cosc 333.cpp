#include <iostream>
#include <ctime>

using namespace std;

typedef long long ll;

ll factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

ll fibonacci(int n) {
    if (n <= 0)
        return -1;
    else if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

double measure_runtime(ll (*func)(int), int n) {
    clock_t start = clock();
    ll result = func(n);
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Result: " << result << ", Time taken: " << elapsed << " seconds" << endl;
    return elapsed;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Factorial(" << n << ")" << endl;
    measure_runtime(factorial, n);
    
    cout << "Fibonacci(" << n << ")" << endl;
    measure_runtime(fibonacci, n);
    
    return 0;
}