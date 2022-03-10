#pragma once
#include <iostream>
#include <vector>
class Calculations {
private:
	float l_Side, r_Side, divisor = 0.f;
	const int size = 3;

public:
	int numberOfIterations=0;
	std::vector<std::string> expectedStrings;
	int indexValue;
	bool bGetIndex = true;
	/// <summary>
	/// Default comnstructor for the Calculations class.
	/// </summary>
	Calculations() {};

	///Function for addition
	///Need to run through GoogleTest.
	int addition(int x, int y);

	///Function for addition
	///Need to run through GoogleTest.
	unsigned int minus(unsigned int x, unsigned int y);

	///Set the right side of the equation.
	void setRightSide(float rSide);

	///Function for division.
	///Need to run through GoogleTest.
	float operator/(float l_Side);

	///Function for division.
	///Need to run through GoogleTest.
	float operator*(float l_Side);
	
	///Function to calculate dot product of two vectors
	///Need to run through GoogleTest.
	int dot_product(int vector_a[], int vector_b[]);

	///Print out a vector of strings.
	///Need to run through GoogleTest.
	void outputStrings(std::string strings[]);

	/// Check for primes.
	///Need to run through GoogleTest.
	bool checkPrime(int n);

};
