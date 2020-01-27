#include <stdio.h>
#include <stdlib.h>	
#include <iostream>
#include <sstream>
#include <map>
#include "currency_converter.h"
using namespace std;
map<CurrencyType, double> conv_rate = { {USD,1} , {EUR,0.9} ,
		{GBP,0.77},{CAD,1.31},{AUD,1.45},{JPY,109},{RMB,6.9} };


double currency_convert(CurrencyType base, CurrencyType output, double amount)
{
	double usd_value, output_value;
	usd_value = amount / conv_rate.at(base);
	output_value = usd_value * conv_rate.at(output);
	/*
	switch (base)
	{
	case USD: usd_value = amount / conv_rate.at(USD);
		break;
	case EUR: usd_value = amount / conv_rate.at(EUR);
		break;
	case GBP: usd_value = amount / conv_rate.at(GBP);
		break;
	case CAD: usd_value = amount / conv_rate.at(CAD);
		break;
	case AUD: usd_value = amount / conv_rate.at(AUD);
		break;
	case JPY: usd_value = amount / conv_rate.at(JPY);
		break;
	case RMB: usd_value = amount / conv_rate.at(RMB);
		break;
	}
	switch (output)
	{
	case USD: output_value = usd_value * conv_rate.at(USD);
		break;
	case EUR: output_value = usd_value * conv_rate.at(EUR);
		break;
	case GBP: output_value = usd_value * conv_rate.at(GBP);
		break;
	case CAD: output_value = usd_value * conv_rate.at(CAD);
		break;
	case AUD: output_value = usd_value * conv_rate.at(AUD);
		break;
	case JPY: output_value = usd_value * conv_rate.at(JPY);
		break;
	case RMB: output_value = usd_value * conv_rate.at(RMB);
		break;
	}
	*/
	return output_value;
}
