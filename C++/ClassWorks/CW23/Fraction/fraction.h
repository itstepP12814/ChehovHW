#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{
	public:
		Fraction();
		Fraction(int a, int b): numerator(a), denominator(b){};
		Fraction (int a): numerator(a), denominator(1){};
		void print() const;
		const Fraction operator*(const Fraction &second_fract);
		const Fraction operator/(const Fraction &second_fract);
		const Fraction operator+(const Fraction &second_fract);
		const Fraction operator-(const Fraction &second_fract);
		const Fraction operator++();
		const Fraction operator--();
    protected:
        int numerator;
        int denominator;
};

#endif // FRACTION_H
