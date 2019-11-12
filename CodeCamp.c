#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Abhishek Sridhar, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Abhishek Sridhar
 * email address: sridhar.abhishek@utexas.edu
 * UTEID: as83788
 * Section 5 digit ID:
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
  
  // EE 312 Students: put your code here
  int hamCount=0;

  /* checks whether or not the ith index of the arrays are the same are not*/

  for(int i=0;i<len;i++)
  {
   if(aList[i]!=bList[i])
   {
       hamCount++;
   }

  }

  return hamCount;
}


/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
 
  // EE 312 Students: put your code here

  /*uses modulus to determine if the absolute number of the ones digit, also known as the last digit, are the same*/
  if(abs(num1%10)==abs(num2%10))
  {
      return true;
  }

  return false;


}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {

  // EE 312 Students: put your code here
  int sum=0;

  /*uses a for loop to add all multiples of 3 and or 5 to the overall sum*/
  for(int i=0;i<1000;i++)
  {
      if(((i%5)==0)||((i%3)==0))
      {
          sum+=i;
      }

  }
  return sum;

}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {

  // EE 312 Students: put your code here
  int tempNum=0;
  int sum=0;
  int multiplier=1;
  int numCopy=0;
  int numLength=1;

  numCopy=num;



  /*determines the length of the number*/
  while(abs(numCopy)>9)
  {
      numCopy/=10;
      numLength++;
  }

  /*creates the multiplier with a for loop used to put each number in the appropriate digits place*/
  for(int i=0;i<numLength;i++)
  {
      multiplier*=10;
  }

  /*isolates each number and multiplies by the appropriate factor of ten to ultimately flip the number*/
  while(abs(num)>0)
  {

      tempNum=num%10;
      tempNum=multiplier*tempNum;
      sum+=tempNum;
      multiplier/=10;
      num/=10;

  }

  return sum/10;
}

  

