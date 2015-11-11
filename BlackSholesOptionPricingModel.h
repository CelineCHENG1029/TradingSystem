// BlackSholesOptionPricingModel.h

#pragma  once

#include "EuropeanOption.h"
#include "OptionValue.h"
#include "Sensitivity.h"

class BlackSholesOptionPricingModel{
	public:
		BlackSholesOptionPricingModel();
		BlackSholesOptionPricingModel(const BlackSholesOptionPricingModel& source);
		~BlackSholesOptionPricingModel();

		void SetParameters(const tstring& optionType, double strikePrice, double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility);
		OptionValue CalculateValue();
		Sensitivity CalculateSensitivity();

		bool IsEqual(const BlackSholesOptionPricingModel& other);
		bool IsNotEqual(const BlackSholesOptionPricingModel& other);

		BlackSholesOptionPricingModel& operator=(const BlackSholesOptionPricingModel& source);
		bool operator==(const BlackSholesOptionPricingModel& other);
		bool operator!=(const BlackSholesOptionPricingModel& other);


		tstring& GetOptionType() const; 
		double GetS() const;			
		double GetK() const;			
		double GetT() const;			
		double GetR() const;			
		double GetV() const;			
	
	private:
		double CalculateDelta();
		double CalculateGamma();
		double CalculateVega();
		double CalculateTheta();
		double CalculateRho();

	private:
		tstring optionType;         // call or put
		double s;					// �����ڻ����簡
		double k;					// ��簡
		double t;					// ��������   0 ~ 1
		double r;					// riskFreeRate ������
		double v;					// ������
};


inline tstring& BlackSholesOptionPricingModel::GetOptionType() const{
	return const_cast<tstring&>(this->optionType);
} 


inline double BlackSholesOptionPricingModel::GetS() const{
	return this->s;
}			


inline double BlackSholesOptionPricingModel::GetK() const{
	return this->k;
}			


inline double BlackSholesOptionPricingModel::GetT() const{
	return this->t;
}


inline double BlackSholesOptionPricingModel::GetR() const{
	return this->r;
}


inline double BlackSholesOptionPricingModel::GetV() const{
	return this->v;
}			