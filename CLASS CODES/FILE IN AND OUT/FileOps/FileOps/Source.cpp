#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::runtime_error;
using std::istringstream;

void WriteToFile()
{
	//name of the output file
	string filename = "greetings.txt";
	
	//open output file for writing
	ofstream outfile(filename);
	
	if (outfile) //check if file is open
	{
		outfile << "hello " << endl;
		outfile << "world" << endl;
		//closes automatically when outfile goes out of scope
		//but, we can close it too..
		outfile.close();
	}
	else //couldn’t open open the file
	{
		cerr << "Unable to open file " << filename << endl;
	}
}

void ReadFromFile()
{
	//name of the input file
	string filename = "greetings.txt";
	
	//open file for reading
	ifstream infile(filename);
	
	if (!infile) //check if file is open
	{
		cerr << "Unable to open file " << filename << endl;
		return;
	}
	//read the file
	string data;
	while (infile.good())
	{
		getline(infile, data);
		cout << data << endl;
	}
}

void ReadExchangeRatesFromFile()
{
	//name of the input file
	//reading the file from desktop. Replace xyz with your login name
	string filename = "C:\\Users\\xyz\\Desktop\\CurrencyRates.txt";
	
	//open file for reading
	ifstream infile(filename);
	
	if (!infile) //check if file is open
	{		
		cerr << "Unable to open file " << filename << endl;
		return;
	}
	//read the file
	
	string data;
	while (infile.good())
	{
		getline(infile, data);
		
		string symbol;
		double rate = 0.0;
		istringstream iss(data);

		iss >> symbol >> rate;

		cout << symbol << " " << rate << endl;
	}
}

int main()
{
	//Write to a file, uncomment line below to run
	//WriteToFile();

	//Read from the file, uncomment line below to run 
	//ReadFromFile();

	//Read from Exchange Rates file
	ReadExchangeRatesFromFile();
}