
#include <stdio.h>
#define SIZE 200    // max size of array
#define upperLimit 183  // N

// PROTOTYPES
void manipulated_seive(int N, int isprime[], int prime[], int SPF[], int *primeIndex, int *counter);

// isPrime[] : isPrime[i] is true(1) if number is prime 
// prime[] : stores all prime numbers less than N
// SPF[] that store smallest prime factor of number

//##############################################################################
//############################ MAIN ############################################
//##############################################################################

int main()
{
    int i;
    int primeIndex = 0;     // current index of prime[] array
    int N = upperLimit;     // Must be less than MAX_SIZE
    int isprime[SIZE], prime[SIZE] , SPF[SIZE];
    int counter = 0;
    
    for ( i = 2; i < SIZE; i++)
    {
        isprime[i] = 1;     // initialize 1(True) to all elements
    }
    isprime[0] = 0;
    isprime[1] = 0;

    // function to find prime numbers
    manipulated_seive(N, isprime, prime, SPF, &primeIndex, &counter);
  
    // print all prime number less than N
    for ( i = 0; i < primeIndex; i++)
    {
        printf("%d /", prime[i]);
    }

    // print counter
    printf("\n\ncounter = %d\n", counter);
   
   return 0;
}
  
//##############################################################################
//############################ FUNCTIONS #######################################
//##############################################################################

// function generates all prime number less then N in O(n)
void manipulated_seive(int N, int isprime[], int prime[], int SPF[], int *primeIndex, int *counter)
{
    // 0 and 1 are not prime
    //isprime[0] = isprime[1] = false = 0 ;
  
    // Fill rest of the entries
    int i, j;

    for (i=2; i<N ; i++)
    {
        (*counter)++;

        // If isPrime[i] == True then i is prime number
        if (isprime[i] == 1)
        {
            // put i into prime[] array
            prime[*primeIndex] = i;
            (*primeIndex)++;
            // A prime number is its own smallest prime factor
            SPF[i] = i;
        }
  
        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for numbers which are not prime
        for (j=0;j < (*primeIndex) && i*prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i*prime[j]]=0;
  
            // put smallest prime factor of i*prime[j]
            SPF[i*prime[j]] = prime[j] ;

            
        }
    }
}
  


