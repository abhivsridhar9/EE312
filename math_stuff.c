#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "math_stuff.h"

int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    
    if (isPrime(testNum))  
       printf("%d is prime\n",testNum);
    else
       printf("%d is not prime.\n", testNum);
    
    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    
    printPrimes(testNum);
    
    printf("\n");
    
    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);
   
    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum)); 
    
    printf("\n");
    
    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    printf("\n");
    return 0;
}



bool  primeCheck(int START_DIV, int number){
	if(number<=2)
		return true;
	if((number%START_DIV==0))
		return false;

	if(START_DIV*START_DIV>number)
		return true;
	primeCheck(START_DIV+1,number);
}


//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime(int number){
	
	const int  START_DIV=2;
	return primeCheck(START_DIV,number);
	
}



void primeOutput(int START_DIV, int n){

	
	if(START_DIV>n/2){
		return;
	}
	if((n%START_DIV==0)){
		
		if(isPrime(START_DIV)){	

		printf("%d, ",START_DIV);

		
		
        }
		
		}
	
	
	primeOutput(START_DIV+1,n);
		
}

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {

   //YOUR CODE GOES HERE
	const int START_DIV=2;
	
	return primeOutput(START_DIV,n);
	
} 



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return (findFibo(n-1)+findFibo(n-2));
}

void factorCheck (int START_DIV, int number) {
 
	if(number<=1)
        	return;
	if((number%START_DIV==0)){
	
                printf("*%d",START_DIV);

             
	
		number=number/START_DIV;
		
                factorCheck(START_DIV,number);
        }
	else{
		
        factorCheck(START_DIV+1,number);   
	}
}
   

//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output 
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIV = 2;
    printf("%d",number);
    printf("=1"); 
    return factorCheck(START_DIV,number);    
   

}
    
	
