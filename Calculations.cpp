#include"Calculations.h"
#include<vector>

///Function for addition
///Need to check.
int Calculations::addition(int x, int y) {
    return x + y;
}


///Function for addition
///Check to see if this works.
unsigned int Calculations::minus(unsigned int x, unsigned int y) {
    return x + y;
}

///Set the right side of the equation.
void Calculations::setRightSide(float rSide) {
    r_Side = rSide;
}

///Function for division.
///Need to check.
float Calculations::operator/(float l_Side) {
    return l_Side / r_Side;
}

///Function for division.
///Need to check.
float Calculations::operator*(float l_Side) {
    return l_Side * r_Side;
}

///Function to calculate dot product of two vectors
///Need to check. 
int Calculations::dot_product(int vector_a[], int vector_b[]) {
    int product = 0;
    for (int i = 0; i < size; i++)
        product = product + vector_a[i] * vector_b[i];
    return product;
}

///Print out a vector of strings.
///Need to check.
void Calculations::outputStrings(std::string strings[]) {
    for (int i = sizeof(strings); i > sizeof(strings) - 1; i--) {
        //expectedStrings.resize(expectedStrings.size() + 1);
        //expectedStrings.push_back(strings[i]);
        strings[i];
        if(bGetIndex) indexValue = i;
        numberOfIterations++;
    }
}

bool Calculations::checkPrime(int n)
{
    /// Create a boolean array
    /// "prime[0..n]" and initialize
    /// all entries as true.
    std::vector<bool> prime(n + 1);
    std::fill(prime.begin(), prime.end(), n + 1);

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            /// Update all multiples of p greater than or
            /// equal to the square of it numbers which are multiple
            /// of p and are less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    //Return prime
    return prime[n];

}