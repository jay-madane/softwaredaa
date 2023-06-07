#include <iostream>
#include<time.h>
using namespace std;

// A NON-tail recursive function
long double fact_nontail(unsigned int n) {
	if (n <= 0)
		return 1;
	return n * fact_nontail(n - 1);
}

// A tail recursive function
long double factTR(unsigned int n, unsigned int a) {
    if (n <= 1)
        return a;
    return factTR(n - 1, n * a);
}
 
long double fact_tail(unsigned int n) { 
    return factTR(n, 1); 
}

double fib(int n){
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

double fib_tail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib_tail(n - 1, b, a + b);
}

int main() {
    int choice, fact_num, fib_num;
    clock_t start, end;
    double cpu_time_used;
    
    cout << "Welcome to Algorithm Analysis\n"
         << "Enter your choice: \n"
         << "1)Factorial\n"
         << "2)Fibonacci\n";
    cin>>choice;
    
    if(choice==1){
        cout << "Enter the number: ";
        cin>>fact_num;
        start = clock();
        cout<<fact_nontail(fact_num)<<"\n";
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "Time required for non-tail recursion: "<<cpu_time_used<<"\n";
        
        start = clock();
        cout<<fact_tail(fact_num)<<"\n";
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "Time required for tail recursion: "<<cpu_time_used<<"\n";
    }
    
    else if(choice==2){
        cout << "Enter the number to find in the series: ";
        cin>>fib_num;
        start = clock();
        cout<<fib(fib_num)<<"\n";
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "Time required for non-tail recursion: "<<cpu_time_used<<"\n";
        
        start = clock();
        cout<<fib_tail(fib_num)<<"\n";
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout << "Time required for tail recursion: "<<cpu_time_used<<"\n";
    }
    
    else{
        cout<<"Enter correct choice."<<endl;
    }
    
	return 0;
}
