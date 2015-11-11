// EuropeanOption.h

#pragma once

#include "DataTypeDefinition.h"
#include "OptionValue.h"
#include "Sensitivity.h"

using namespace std;

class EuropeanOption{
	public:
		EuropeanOption();
		EuropeanOption(const EuropeanOption& source);
		EuropeanOption(const tstring& optionCode, const tstring& underlyingAssetCode, const tstring& optionType, double strikePrice);
		~EuropeanOption();


		//�ɼ��� ��ġ (���簡ġ+�ð���ġ)
		OptionValue& CalculateValue(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility);

		//�ɼ��� �ΰ���
		Sensitivity& CalculateSensitivity(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility);


		bool IsEqual(const EuropeanOption& other);
		bool IsNotEqual(const EuropeanOption& other);

		EuropeanOption& operator=(const EuropeanOption& source);
		bool operator==(const EuropeanOption& other);
		bool operator!=(const EuropeanOption& other);

		tstring& GetOptionCode() const;
		tstring& GetUnderlyingAssetCode() const;
		tstring& GetOptionType() const;
		double GetStrikePrice() const;

		Sensitivity& GetSensitivity() const;
		OptionValue& GetOptionValue() const;

	private:
		tstring optionCode;
		tstring underlyingAssetCode;
		tstring optionType; //call or put
		double strikePrice;

		Sensitivity sensitivity;
		OptionValue optionValue;
};

inline tstring& EuropeanOption::GetOptionCode() const{
	return const_cast<tstring&>(this->optionCode);
}

inline tstring& EuropeanOption::GetUnderlyingAssetCode() const{
	return const_cast<tstring&>(this->underlyingAssetCode);
}
	
inline tstring& EuropeanOption::GetOptionType() const{
	return const_cast<tstring&>(this->optionType);
}


inline double EuropeanOption::GetStrikePrice() const{
	return this->strikePrice;
}


inline Sensitivity& EuropeanOption::GetSensitivity() const{
	return const_cast<Sensitivity&>(this->sensitivity);
}


inline OptionValue& EuropeanOption::GetOptionValue() const{
	return const_cast<OptionValue&>(this->optionValue);
}