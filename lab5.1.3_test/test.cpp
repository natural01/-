#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../lab5.1.3/Rational.cpp"

SCENARIO("Constructor")
{
	WHEN("without parameter")
	{
		THEN("return 0/1")
		{
			CRational rational;
			CHECK(rational.GetNumerator() == 0);
			CHECK(rational.GetDenominator() == 1);
		}
	}
	WHEN("with one parameter")
	{
		THEN("return value/1")
		{
			CRational rational(4);
			CHECK(rational.GetNumerator() == 4);
			CHECK(rational.GetDenominator() == 1);
		}
	}
	WHEN("with two parameters")
	{
		THEN("return numerator/denominator")
		{
			CRational rational(4, 5);
			CHECK(rational.GetNumerator() == 4);
			CHECK(rational.GetDenominator() == 5);
		}
	}
	WHEN("denominator is zero")
	{
		THEN("return error")
		{
			CRational rational;
			CHECK_THROWS(rational.SetDenominator(0));
		}
	}
	WHEN("denominator < 0")
	{
		THEN("return error")
		{
			CRational rational(4, -1);
			CHECK(rational.GetNumerator() == -4);
			CHECK(rational.GetDenominator() == 1);
		}
	}
	WHEN("correct rational")
	{
		THEN("correct double number")
		{
			CRational rational(3, 10);
			CHECK(rational.ToDouble() == 0.3);
		}
	}
}

SCENARIO("Operator +")
{
	WHEN("operator unary +")
	{
		THEN("return equal number")
		{
			CRational rational(3, 7);
			auto result = +rational;
			CHECK(result.GetNumerator() == 3);
			CHECK(result.GetDenominator() == 7);
		}
	}
	WHEN("operator unary +")
	{
		THEN("return equal negative number")
		{
			CRational rational(-3, 7);
			auto result = +rational;
			CHECK(result.GetNumerator() == -3);
			CHECK(result.GetDenominator() == 7);
		}
	}
	WHEN("operator binary +")
	{
		THEN("return correct rational")
		{
			CRational firstRational(2, 5);
			CRational secondRational(7, 9);
			auto result = firstRational + secondRational;
			CHECK(result.GetNumerator() == 53);
			CHECK(result.GetDenominator() == 45);
		}
	}
}
SCENARIO("Operator -")
{
	WHEN("operator unary -")
	{
		THEN("return opposite number")
		{
			CRational rational(3, 7);
			auto result = -rational;
			CHECK(result.GetNumerator() == -3);
			CHECK(result.GetDenominator() == 7);
		}
	}
	WHEN("operator unary -")
	{
		THEN("return equal number")
		{
			CRational rational(-3, 7);
			auto result = -rational;
			CHECK(result.GetNumerator() == 3);
			CHECK(result.GetDenominator() == 7);
		}
	}
	WHEN("operator binary -")
	{
		THEN("return correct rational")
		{
			CRational firstRational(2, 5);
			CRational secondRational(7, 9);
			auto result = firstRational - secondRational;
			CHECK(result.GetNumerator() == -17);
			CHECK(result.GetDenominator() == 45);
		}
	}
}
SCENARIO("Operator *")
{
	WHEN("operator binary *")
	{
		THEN("return correct rational")
		{
			CRational firstRational(2, 5);
			CRational secondRational(7, 9);
			auto result = firstRational * secondRational;
			CHECK(result.GetNumerator() == 14);
			CHECK(result.GetDenominator() == 45);
		}
	}
}
SCENARIO("Operator /")
{
	WHEN("operator binary /")
	{
		THEN("return correct rational")
		{
			CRational firstRational(2, 5);
			CRational secondRational(7, 9);
			auto result = firstRational / secondRational;
			CHECK(result.GetNumerator() == 18);
			CHECK(result.GetDenominator() == 35);
		}
	}
	WHEN("operator binary / by zero")
	{
		THEN("return error")
		{
			CRational firstRational(2, 5);
			CRational secondRational;
			CHECK_THROWS(firstRational / secondRational);
		}
	}
}
SCENARIO("Operator +=") 
{
	WHEN("second number is rational")
	{
		THEN("return correct rational")
		{
			CRational rational(2, 5);
			CRational secondRational(7, 9);
			rational += secondRational;
			CHECK(rational.GetNumerator() == 53);
			CHECK(rational.GetDenominator() == 45);
		}
	}
}
SCENARIO("Operator -=") 
{
	WHEN("second number is rational")
	{
		THEN("return correct rational")
		{
			CRational rational(2, 5);
			CRational secondRational(7, 9);
			rational -= secondRational;
			CHECK(rational.GetNumerator() == -17);
			CHECK(rational.GetDenominator() == 45);
		}
	}
}
SCENARIO("Operator *=")
{
	WHEN("second number is rational")
	{
		THEN("return correct rational")
		{
			CRational rational(2, 5);
			CRational secondRational(7, 9);
			rational *= secondRational;
			CHECK(rational.GetNumerator() == 14);
			CHECK(rational.GetDenominator() == 45);
		}
	}
	WHEN("second number is int")
	{
		THEN("return correct rational")
		{
			CRational rational(2, 5);
			rational *= 3;
			CHECK(rational.GetNumerator() == 6);
			CHECK(rational.GetDenominator() == 5);
		}
	}
}
SCENARIO("Operator /=")
{
	WHEN("second number is rational")
	{
		THEN("return correct rational")
		{
			CRational rational(2, 5);
			CRational secondRational(7, 9);
			rational /= secondRational;
			CHECK(rational.GetNumerator() == 18);
			CHECK(rational.GetDenominator() == 35);
		}
	}
	WHEN("second number is int")
	{
		THEN("return correct rational")
		{
			CRational rational(2, 5);
			rational /= 3;
			CHECK(rational.GetNumerator() == 2);
			CHECK(rational.GetDenominator() == 15);
		}
	}
	WHEN("second number is zero")
	{
		THEN("return error")
		{
			CRational rational(2, 5);
			CHECK_THROWS(rational /= 0);
		}
	}
}
SCENARIO("Operator ==") 
{
	WHEN("numbers is equar and second number is rational")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			CRational secondRational(2, 5);
			auto result = firstRational == secondRational;
			CHECK(result == true);
		}
	}
	WHEN("numbers is equar and second number is int")
	{
		THEN("return true")
		{
			CRational firstRational(1, 2);
			CRational secondRational(1, 2);
			firstRational += secondRational;
			auto result = firstRational == 1;
			CHECK(result == true);
		}
	}
	WHEN("numbers is equar and first number is int")
	{
		THEN("return true")
		{
			CRational firstRational(7, 2);
			CRational secondRational(1, 2);
			firstRational += secondRational;
			auto result = (4 == firstRational);
			CHECK(result == true);
		}
	}
	WHEN("numbers is not equar and second number is rational")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			CRational secondRational(8, 5);
			auto result = firstRational == secondRational;
			CHECK(result == false);
		}
	}
	WHEN("numbers is not equar and second number is int")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			auto result = firstRational == 5;
			CHECK(result == false);
		}
	}
	WHEN("numbers is not equar and first number is int")
	{
		THEN("return false")
		{
			CRational secondRational(9, 2);
			auto result = (4 == secondRational);
			CHECK(result == false);
		}
	}
}
SCENARIO("Operator !=")
{
	WHEN("numbers is equar and second number is rational")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			CRational secondRational(2, 5);
			auto result = firstRational != secondRational;
			CHECK(result == false);
		}
	}
	WHEN("numbers is equar and second number is int")
	{
		THEN("return false")
		{
			CRational firstRational(1, 2);
			CRational secondRational(1, 2);
			firstRational += secondRational;
			auto result = firstRational != 1;
			CHECK(result == false);
		}
	}
	WHEN("numbers is equar and first number is int")
	{
		THEN("return false")
		{
			CRational firstRational(1, 2);
			CRational secondRational(7, 2);
			firstRational += secondRational;
			auto result = (4 != firstRational);
			CHECK(result == false);
		}
	}
	WHEN("numbers is not equar and second number is rational")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			CRational secondRational(8, 5);
			auto result = firstRational != secondRational;
			CHECK(result == true);
		}
	}
	WHEN("numbers is not equar and second number is int")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			auto result = firstRational != 5;
			CHECK(result == true);
		}
	}
	WHEN("numbers is not equar and first number is int")
	{
		THEN("return true")
		{
			CRational secondRational(9, 2);
			auto result = (4 != secondRational);
			CHECK(result == true);
		}
	}
}
SCENARIO("Operator <") 
{
	WHEN("the first number is less than the second, second number is rational")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			CRational secondRational(3, 5);
			auto result = firstRational < secondRational;
			CHECK(result == true);
		}
	}
	WHEN("the first number is less than the second, second number is int")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			auto result = firstRational < 10;
			CHECK(result == true);
		}
	}
	WHEN("the first number is not less than the second, second number is rational")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			CRational secondRational(1, 5);
			auto result = firstRational < secondRational;
			CHECK(result == false);
		}
	}
	WHEN("the first number is not less than the second, second number is int")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			auto result = firstRational < 0;
			CHECK(result == false);
		}
	}
}
SCENARIO("Operator <=") 
{
	WHEN("the first number is less or equar than the second, second number is rational")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			CRational secondRational(3, 5);
			auto result = firstRational <= secondRational;
			CHECK(result == true);
		
			CRational newFirstRational(2, 5);
			CRational newSecondRational(2, 5);
			result = newFirstRational <= newSecondRational;
			CHECK(result == true);
		}
	}
	WHEN("the first number is less or equar than the second, second number is int")
	{
		THEN("return true")
		{
			CRational firstRational(2, 5);
			auto result = firstRational <= 10;
			CHECK(result == true);
		
			CRational newFirstRational(5, 5);
			result = newFirstRational <= 1;
			CHECK(result == true);
		}
	}
	WHEN("the first number is not less or equar than the second, second number is rational")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			CRational secondRational(1, 5);
			auto result = firstRational <= secondRational;
			CHECK(result == false);
		}
	}
	WHEN("the first number is not less or equar than the second, second number is int")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			auto result = firstRational <= 0;
			CHECK(result == false);
		}
	}
}
SCENARIO("Operator >") 
{
	WHEN("the first number is greater than the second, second number is rational")
	{
		THEN("return true")
		{
			CRational firstRational(4, 5);
			CRational secondRational(3, 5);
			auto result = firstRational > secondRational;
			CHECK(result == true);
		}
	}
	WHEN("the first number is greater than the second, second number is int")
	{
		THEN("return true")
		{
			CRational firstRational(10, 5);
			auto result = firstRational > 1;
			CHECK(result == true);
		}
	}
	WHEN("the first number is not greater than the second, second number is rational")
	{
		THEN("return false")
		{
			CRational firstRational(1, 5);
			CRational secondRational(1, 5);
			auto result = firstRational > secondRational;
			CHECK(result == false);
		}
	}
	WHEN("the first number is not greater than the second, second number is int")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			auto result = firstRational > 5;
			CHECK(result == false);
		}
	}
}
SCENARIO("Operator >=") 
{
	WHEN("the first number is greater or equar than the second, second number is rational")
	{
		THEN("return true")
		{
			CRational firstRational(4, 5);
			CRational secondRational(2, 5);
			auto result = firstRational >= secondRational;
			CHECK(result == true);
		
			CRational newFirstRational(2, 5);
			CRational newSecondRational(2, 5);
			result = newFirstRational >= newSecondRational;
			CHECK(result == true);
		}
	}
	WHEN("the first number is greater or equar than the second, second number is int")
	{
		THEN("return true")
		{
			CRational firstRational(7, 5);
			auto result = firstRational >= 1;
			CHECK(result == true);
		
			CRational newFirstRational(5, 5);
			result = newFirstRational >= 1;
			CHECK(result == true);
		}
	}
	WHEN("the first number is not greater or equar than the second, second number is rational")
	{
		THEN("return false")
		{
			CRational firstRational(1, 5);
			CRational secondRational(5, 5);
			auto result = firstRational >= secondRational;
			CHECK(result == false);
		}
	}
	WHEN("the first number is not greater or equar than the second, second number is int")
	{
		THEN("return false")
		{
			CRational firstRational(2, 5);
			auto result = firstRational >= 5;
			CHECK(result == false);
		}
	}
}

SCENARIO("Interaction - set numerator")
{
	WHEN("normal test")
	{
		CRational rational;
		rational.SetNumerator(5);
		CHECK(rational.GetNumerator() == 5);
	}
	WHEN("numerator is zero")
	{
		CRational rational;
		rational.SetNumerator(0);
		CHECK(rational.GetNumerator() == 0);
	}
}

SCENARIO("Interaction - set denominator")
{
	WHEN("normal test")
	{
		CRational rational;
		rational.SetDenominator(5);
		CHECK(rational.GetDenominator() == 5);
	}
	WHEN("numerator is zero")
	{
		CRational rational;
		CHECK_THROWS(rational.SetDenominator(0));
	}
}

SCENARIO("Operator <<") 
{
	WHEN("correct rational number") 
	{
		std::stringstream result;
		CRational rational(5, 7);
		result << rational;
		CHECK(result.str() == "5/7");
	}
}