#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "Calculations.h"



class Testing :public ::testing::Test {



protected:
    Calculations *calc;
    int primesNumbers[5] = { 3,5,7,11,13 };
    int nonPrimeNumbers[5] = { 4,8,16,24,26 };
    int i_A_Vector[3] = { 3,4,5 };
    int i_b_Vector[3] = {3,4,5};
    int i_Dot_Product_Result = 50;
    int i_a;
    int i_b;
    std::string s_Array_of_Strings[4] = {"aa","bb", "cc", "dd"};
    Testing() {
        calc = new Calculations();

      
    }

    void t_Testing() {
        // You can do set-up work for each test here.
       
    }

    ~Testing() override {
        delete calc;
    }

};
/// <summary>
/// Because the code reaseambles different mathematical operations,
/// in order to test the correctness of the code I tested the properties of each operation
/// The name of each test is pretty much descriptive but as requested I added the comments for extra clarity
/// </summary>
TEST_F(Testing, Add_of_2_positive_numbers_is_always_a_positive_number)
{
    i_a = 120;
    i_b = 320;
    // For a valid test the input variables has to be greater than 0
    ASSERT_TRUE(i_a > 0) << "Expected i_a variable as a positive number, for a valid test of a+b>0 in test above";
    ASSERT_TRUE(i_b > 0) << "Expected i_b variable a positive number , for a valid test of a+b>0 in test above";
    // if the sum calculated through this function is greater than zero then the code is partially correct
    EXPECT_GT(calc->addition(i_a, i_b), 0) << "The function addition calculates wrongly the sum of 2 positive numbers";
}

TEST_F(Testing, Add_of_2_negative_numbers_is_always_a_negative_number)
{
   i_a = -120;
   i_b = -320;
   // for a valid test, the input variables for the test has to be less than zero
   ASSERT_FALSE(i_a > 0) << "Expected i_a variable as a negative number, for a valid test of a+b<0 in test above";
   ASSERT_FALSE(i_b > 0) << "Expected i_b variable as a negative number, for a valid test of a+b<0 in test above";
  // I expect that sum calculated through this test to be less than 0
   EXPECT_LT(calc->addition(i_a, i_b), 0) << "The function addition calculates wrongly the sum of 2 negative numbers";
}

TEST_F(Testing, Add_of_2_opposite_numbers_is_always_0)
{
    i_a = 120;
    i_b = -120;
    // for a valid test the numbers has to be opposite
    ASSERT_TRUE(i_a == -i_b) << "Expected ui_a and ui_b 2 oppositive values, for a valid test of a+b==0 where a==-b in test above";
    // is expected that the sum to be 0.
    EXPECT_EQ(calc->addition(i_a, i_b), 0)<<"Function doesn't calculates correctly addition of 2 opposite numbers";

}
TEST_F(Testing, Adding_precision)
{
    // tests the precision of the function
    i_a = 10;
    i_b = 20;
    EXPECT_EQ(calc->addition(i_a, i_b), i_a + i_b);
}
// sum of 2 float numbers

TEST_F(Testing, Add_of_2_float_numbers)
{
    // tests if the function is capable of precise sum of two float numbers
    float f_a = 120.1f;
    float f_b = 320.1f;
    ASSERT_EQ(calc->addition(f_a, f_b), 440.2f) << std::setprecision(1) << "Function cannot calculate precisely the sum of two float numbers";
}


TEST_F(Testing, Sub_a_minus_b_positive_numbers_where_a_greater_than_b)
{
    // when subtracting from a greater number the result should be positive
    i_a = 120;
    i_b = 60;
    ASSERT_GT(i_a, i_b) << "Expected the value of i_a greater than the value of i_b for a valid test";
    EXPECT_GT(calc->minus(i_a, i_b), 0)<<"The difference between"<< i_a <<"and"<< i_b <<" should be greater than 0";
}
TEST_F(Testing, Sub_a_minus_b_positive_numbers_where_a_smaller_than_b)
{
    // when subtracting from a smaller number the result should be a negative number
     i_a = 60;
     i_b = 120;
    ASSERT_LT(i_a, i_b) << "Expected the value of i_a smaller than the value of i_b for a valid test";
    EXPECT_LT(calc->minus(i_a, i_b), 0)<<"The difference between " << i_a << " and " << i_b << " should be smaller than 0";
}
TEST_F(Testing, Sub_a_minus_b_negative_numbers_where_a_less_than_b)
{
    // the difference between two negative numbers when first number is less than second number, should be smaller than 0
     i_a = -120;
     i_b = -60;
    ASSERT_LT(i_a, i_b) << "Expected the value of i_a less than the value of i_b for a valid test";
    EXPECT_LT(calc->minus(i_a, i_b), 0) << "The difference between " << i_a << " and " << i_b << " should be less than 0";
}
TEST_F(Testing, Sub_a_minus_b_negative_numbers_a_greater_than_b)
{
    // the difference between two negative number when first number is greater than second number, should be greater than 0
     i_a = -60;
     i_b = -120;
    ASSERT_GT(i_a, i_b) << "Expected the value of i_a greater than the value of i_b for a valid test";
    EXPECT_GT(calc->minus(i_a, i_b), 0) << "The difference between " << i_a << " and " << i_b << " should be greater than 0";
}

TEST_F(Testing, Div_when_a_greater_than_b_positive_number)
{
    // the division when first number is greater than second number should be greater than 1
     i_a = 30;
     i_b = 10;
    ASSERT_GT(i_a, i_b) << "Expected the value of i_a greater than the value of i_b for a valid test";
    calc->setRightSide(i_b);
    EXPECT_GT(calc->operator/(i_a), 1);
}
TEST_F(Testing, Div_when_a_less_than_b_positive_numbers)
{
    // the division when first number is less than second number should be less than 1 and greater than 0
     i_a = 10;
     i_b = 30;
    ASSERT_LT(i_a, i_b) << "Expected the value of i_a less than the value of i_b for a valid test";
    calc->setRightSide(i_b);
    EXPECT_GT(calc->operator/(i_a), 0)<< "The resut should be between 0 and 1";
    EXPECT_LT(calc->operator/(i_a), 1)<< "The result should be between 0 and 1";
}
TEST_F(Testing, Div_when_a_eq_to_b_positive_numbers)
{
    // the division between two positive number it is always 1
     i_a = 30;
     i_b = 30;
    ASSERT_EQ(i_a, i_b) << "Expected the value of i_a equal to the value of i_b for a valid test";
    calc->setRightSide(i_b);
    EXPECT_EQ(calc->operator/(i_a), 1) << "The resut should be equal to 1";

}
TEST_F(Testing, Div_when_one_and_only_one_of_the_operands_is_negative)
{
    // when one of the operands is negative the division is negative
     i_a = -10;
     i_b = 30;
    ASSERT_TRUE((i_a < 0 && i_b > 0) || (i_a > 0 && i_b < 0)) << "Expected that one of the variables to be less than 0 for a valid test";
    calc->setRightSide(i_b);
    EXPECT_LT(calc->operator/(i_a), 0) << "The resut should be a negative number";
}
TEST_F(Testing, Div_when_both_operands_are_negative)
{
    // when both operands are negative the sign of the division is plus
     i_a = -10;
     i_b = -30;
    ASSERT_TRUE((i_a < 0)&& (i_b < 0)) << "Expected that both variables to be less than 0 for a valid test";
    calc->setRightSide(i_b);
    EXPECT_GT(calc->operator/(i_a), 0) << "The resut should be a positive number";
}
TEST_F(Testing, Div_when_first_operand_is_0)
{
    // if the first operand of the division is 0 then the result of division is 0
     i_a = 0;
     i_b = -30;
    ASSERT_TRUE(i_a == 0) << "Expected that i_a == 0 for a valid test";
    calc->setRightSide(i_b);
    EXPECT_EQ(calc->operator/(i_a), 0) << "The resut should be 0";
}

TEST_F(Testing, Multiplication_when_one_operand_is_1)
{
    // a number multiplied by 1 is the number itself
     i_a = 1;
     i_b = 10;
    ASSERT_TRUE((i_a==1)||(i_b==1));
    calc->setRightSide(i_b);
    EXPECT_EQ(calc->operator*(i_a), 10);
}
TEST_F(Testing, Multiplication_when_one_operand_is_0)
{
    // if a number is number is multiplied by 0 the result is 0
     i_a = 0;
     i_b = 10;
    ASSERT_TRUE((i_a == 0) || (i_b == 0));
    calc->setRightSide(i_b);
    EXPECT_EQ(calc->operator*(i_a), 0);
}
TEST_F(Testing, Multiplication_when_one_and_only_one_operand_less_than_0)
{
    // if one of the operands is less than 0 then the result is less that 0
     i_a = -10;
     i_b = 10;
    ASSERT_TRUE((i_a < 0 && i_b > 0) || (i_a > 0 && i_b < 0));
    calc->setRightSide(i_b);
    EXPECT_LT(calc->operator*(i_a), 0);
}
TEST_F(Testing, Multiplication_commutative_property)
{
    // A * B should be equal to B * A
     i_a = 230;
     i_b = 420;
    calc->setRightSide(i_b);
    int i_a_times_b = calc->operator*(i_a);
    calc->setRightSide(i_a);
    int i_b_times_a = calc->operator*(i_b);
    EXPECT_EQ(i_a_times_b, i_b_times_a);
}
TEST_F(Testing, DotProduct)
{
    // the dot product of vectors 3i+4j+5K and 3i+4j+5k should be 50

    ASSERT_EQ(calc->dot_product(i_A_Vector, i_A_Vector), i_Dot_Product_Result);
}

// gasit o varianta
TEST_F(Testing, OutPutString_covers_all_values_in_the_array)
{   
   // test if the functions iterates properly the array
    ASSERT_EQ(calc->numberOfIterations, 0)<<"Number of iteration should be initialized with 0 for a valid test";
    calc->outputStrings(s_Array_of_Strings);
    ASSERT_LT(calc->indexValue, 5) << "The index is out of range";
    EXPECT_EQ(calc->numberOfIterations, 4)<<"Function goes through only "<< calc->numberOfIterations << " values instead of "<<4;
}
TEST_F(Testing, OutPutString_index_in_range_of_array_size)
{
    // test if the index generated is in the range of the array
    calc->outputStrings(s_Array_of_Strings);
    EXPECT_LT(calc->indexValue, 5) << "The index is out of range";
}
TEST_F(Testing, OutPutString_printed_values)
{
    // test if the function prints the expected strings
    calc->outputStrings(s_Array_of_Strings);
    ASSERT_LT(calc->indexValue, 5) << "The index is out of range";
    int sizeOF = calc->expectedStrings.size();
    for (int i = 0; i < sizeOF ; i++)
    {
        EXPECT_STREQ(calc->expectedStrings[i].c_str(), s_Array_of_Strings[4 - i].c_str());
    }
}
TEST_F(Testing, Test_PrimeCheker_with_prime_numbers)
{
    // test if the function correctly indentifies prime numbers 
    for (int i = 0; i < 5; i++)
    {
        EXPECT_TRUE(calc->checkPrime(primesNumbers[i]));
    }
}
TEST_F(Testing, Test_PrimeCheker_with_non_prime_numbers)
{
    // test if the function correctly indentifies non prime numbers 
    for (int i = 0; i < 5; i++)
    {
        EXPECT_FALSE(calc->checkPrime(nonPrimeNumbers[i]));
    }
}