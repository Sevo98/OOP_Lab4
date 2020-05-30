#pragma once
static class DoubleValidator
{
	static bool IsValuePositive(double value);
	static bool IsValueInRange(double value, double min, double max);
public:
	static void AssertPositiveValue(double value);
	static void AssertValueInRange(double value, double min, double max);
};