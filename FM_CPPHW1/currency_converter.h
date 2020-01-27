#pragma once

#include <string>
using namespace std;
enum CurrencyType { USD = 0, EUR = 1, GBP = 2, CAD = 3, AUD = 4, JPY = 5, RMB = 6 };
double currency_convert(CurrencyType base, CurrencyType output, double amount);
