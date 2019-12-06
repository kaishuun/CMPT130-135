using namespace std;

class fraction{

public:
	//constructors
	fraction();
	fraction(int num, int den); 

	//mutators
	void set(int num, int den);

	//assessories
	int getNumerator() const;
	int getDenominator() const;
	double getDouble() const;

	//overloaders
	fraction operator+(fraction fr);
	fraction operator+(int num);
	fraction operator-(fraction fr);
	fraction operator-(int num);
	fraction operator*(fraction fr);
	fraction operator*(int num);
	fraction operator/(fraction fr);
	fraction operator/(int num);
	friend ostream& operator<<(ostream& os, fraction fr);
	friend fraction operator+(int num, fraction fr);
	friend fraction operator-(int number, fraction fr);
	friend fraction operator*( int num, fraction fr);
	friend fraction operator/(int num, fraction fr);


private:
	int numerator;
	int denominator;
	void simplify(int& numerator, int& denominator);
	void neg_den_check(int denominator) const;
};

fraction::fraction(){
		neg_den_check(denominator);
		numerator = 0;
		denominator = 1;
		simplify(numerator, denominator);
	}
fraction::fraction(int num, int den)
	{
		neg_den_check(den);
		numerator = num;
		denominator = den;
		simplify(numerator,denominator);
	}//constructor
void fraction::set(int num, int den)
	{
		neg_den_check(den);
		numerator = num;
		denominator = den;
		simplify(numerator, denominator);
	}//set
//assessories
int fraction::getNumerator() const
	{
		return numerator;
	}
int fraction::getDenominator()const
	{
		return denominator;
	}
double fraction::getDouble() const
	{
		return ((double)numerator/(double)denominator);
	}
//Overloaders
fraction fraction::operator+(fraction fr) 
	{
		fraction result;
		if(this->denominator == fr.denominator)
		{
			result.numerator = (this->numerator + fr.numerator);
			result.denominator = (this-> denominator);
		}else
		{
			result.numerator = (this->numerator * fr.denominator + this->denominator * fr.numerator);
			result.denominator = (this->denominator * fr.denominator);
		}//else
		simplify(result.numerator, result.denominator);
		return result;
	}//operator+
fraction fraction::operator+(int num)
	{
		fraction result;
		if(denominator == 1)
		{
			result.numerator = numerator + num;
			result.denominator = 1;
		}else
		{
			result.numerator = ( num * denominator + numerator);
			result.denominator = denominator;
		}
		simplify(result.numerator, result.denominator);
		return result;
	}//operator+
fraction operator+(int num, fraction fr)
	{
		fraction result;
		if(fr.denominator == 1)
		{
			result.numerator = fr.numerator + num;
			result.denominator = 1;
		}else
		{
			result.numerator = ( num * fr.denominator + fr.numerator);
			result.denominator = fr.denominator;
		}
		int abs_num;
		if (result.numerator < 0)
		{
			abs_num = ((-1 ) * result.numerator);
		}else
		{
			abs_num = result.numerator;
		}
		for(int i = result.denominator * abs_num; i > 1; i-- )
		{
			if((result.denominator % i == 0) && (result.numerator % i == 0))
			{
				result.denominator /= i;
				result.numerator /= i;
			}//if 
		}//for
		return result;
	}//operator+
fraction fraction::operator-(fraction fr)
	{
		fraction result;
		if(this->denominator == fr.denominator)
		{
			result.numerator = (this->numerator - fr.numerator);
			result.denominator = (this-> denominator);
		}else
		{
			result.numerator = ((this->numerator * fr.denominator) - (this->denominator * fr.numerator));
			result.denominator = (this->denominator * fr.denominator);
		}//else
		simplify(result.numerator, result.denominator);
		return result;
	}//operator-
fraction fraction::operator-(int num)
{
	fraction result;
	if(denominator == 1)
	{
		result.numerator = (numerator - num);
		result.denominator = denominator;
	}else
	{
		result.numerator = (numerator - num * denominator);
		result.denominator = denominator;
	}
	simplify(result.numerator, result.denominator);
	return result;
}//operator-
fraction operator-(int number, fraction fr)
	{
		fraction result;
		if(fr.denominator == 1)
		{
			result.numerator = number - fr.numerator;
			result.denominator = fr.denominator;
		}else
		{
			result.numerator = fr.denominator * number - fr.numerator;
			result.denominator = fr.denominator;
		}
		int abs_num;
		if (result.numerator < 0)
		{
			abs_num = ((-1 ) * result.numerator);
		}else
		{
			abs_num = result.numerator;
		}

		for(int i = result.denominator * abs_num; i > 1; i-- )
		{
			if((result.denominator % i == 0) && (result.numerator % i == 0))
			{
				result.denominator /= i;
				result.numerator /= i;
			}//if 
		}//for
		return result;
	}//operator-
fraction fraction::operator*(fraction fr)
{
	fraction result;
	result.numerator = (this->numerator * fr.numerator);
	result.denominator = (this->denominator * fr.denominator);
	simplify(result.numerator, result.denominator);
		return result;
}//operator*
fraction fraction::operator*(int num)
{
	fraction result;
	result.numerator = (numerator * num);
	result.denominator = (denominator);
	simplify(result.numerator, result.denominator);
		return result;
}//operator*
fraction operator*( int num, fraction fr) 
{
	fraction result;
	result.numerator = (num * fr.numerator);
	result.denominator = (fr.denominator);
	int abs_num;
		if (result.numerator < 0)
		{
			abs_num = ((-1 ) * result.numerator);
		}else
		{
			abs_num = result.numerator;
		}

		for(int i = result.denominator * abs_num; i > 1; i-- )
		{
			if((result.denominator % i == 0) && (result.numerator % i == 0))
			{
				result.denominator /= i;
				result.numerator /= i;
			}//if 
		}//for
	return result;
}//friend function operator*
fraction fraction::operator/(fraction fr)
{
	fraction result;
	result.numerator = (this->numerator * fr.denominator);
	result.denominator = (this->denominator * fr.numerator);
	simplify(result.numerator, result.denominator);
		return result;
}//operator/
fraction fraction::operator/(int num)
{
	//set(i, 1);
	//neg_den_check(denominator);
	fraction result;
	if(num < 0){
		result.numerator = (-numerator);
		result.denominator = (denominator * -num);
	}else
	{
		result.numerator = numerator;
		result.denominator = denominator * num;
	}
	simplify(result.numerator, result.denominator);
	return result;
}//operator/
fraction operator/(int num, fraction fr) 
{
	fraction result;
	result.numerator = (num * fr.denominator);
	result.denominator = fr.numerator;
	int abs_num;
		if (result.numerator < 0)
		{
			abs_num = ((-1 ) * result.numerator);
		}else
		{
			abs_num = result.numerator;
		}

		for(int i = result.denominator * abs_num; i > 1; i-- )
		{
			if((result.denominator % i == 0) && (result.numerator % i == 0))
			{
				result.denominator /= i;
				result.numerator /= i;
			}//if 
		}//for
	return result;
}//operator/ overload
ostream& operator<<(ostream& os, fraction fr) 
{
	if(fr.denominator == 0)
	{
		os << "0";
	}else if(fr.denominator == 1)
	{
		os << fr.numerator;
	}else
	{
		os << fr.numerator << "/" << fr.denominator;
	}
	return os;
}//operator <<
void fraction::simplify(int& numerator, int& denominator)//info gathered from cplusplus.com
	{		
		int abs_num;
		if (numerator < 0)
		{
			abs_num = ((-1 ) * numerator);
		}else
		{
			abs_num = numerator;
		}

		for(int i = denominator * abs_num; i > 1; i-- )
		{
			if((denominator % i == 0) && (numerator % i == 0))
			{
				denominator /= i;
				numerator /= i;
			}//if 
		}//for

	}//simplify
void fraction::neg_den_check(int denominator) const
{
	if (denominator < 0)
	{
		throw runtime_error("The denominator can't be negative!");
	}else if(denominator == 0)
	{
		throw runtime_error("The denominator can't be 0!");
	}else {

	}
}//neg denominator check
