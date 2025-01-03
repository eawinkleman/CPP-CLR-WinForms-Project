#pragma once
#include <vector>
#include <string>
#include <array>
#include <iostream>
using namespace System;
using namespace System::Globalization;

ref class aCandlestick
{
public:
	//The array of delimiters that could be used to parse the strings
	static array<String^>^ delimiter = { "\",\"", "\", " , "\"," , ", " , "," , " " , "-" , "/ " , "/", "\\ " , "\\" , "\""};

	//Date formats that could be used to only allow certain date structures
	static array<String^>^ dateFormats = { "MMM dd, yyyy" , "MMM d, yyyy" , "MMM dd, yy" , "MMM d, yy" , "dd MMM yyyy", "dd MMM yy", "MMM-d-yyyy" , "MMM-d-yy" };

	//Reference string to compare if the appropriate file was loaded
	static String^ referenceString = "\"Ticker\",\"Period\",\"Date\",\"Open\",\"High\",\"Low\",\"Close\",\"Volume\"";

public:
	//values of all the values of the candlestick
	property String^ ticker;
	property String^ period;
	property DateTime date;
	property float open;
	property float high;
	property float low;
	property float close;
	property unsigned long volume;

	//constructor
	aCandlestick()
	{
		open = 0;
		high = 0;
		low = 0;
		close = 0;
		volume = 0;
	}

private:

public:
	//aCandlestick(DateTime a, float b, float c, float d, float e, long f);
	//aCandlestick(System::String^ aCandlestickString);

public:
	//constructor
	aCandlestick::aCandlestick(DateTime a, float b, float c, float d, float e, unsigned long f) {
		date = a;
		open = b;
		high = c;
		low = d;
		close = e;
		volume = f;
	}

	//function to parse strings given
	aCandlestick(System::String^ aCandlestickString)
	{
		//split the string into an array of parts using the delimiters specified above
		array<String^>^ parts = aCandlestickString->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
		
		//Decided to add ticker and period to update the combo boxes later
		ticker = parts[0];
		period = parts[1];

		//for the date, take the second, third, and fourth parts and create the format MMM dd, YYYY
		String^ dateString = parts[2] + " " + parts[3] + ", " + parts[4];
		DateTime parsedDate;
		//add the parsed parts to each variable
		date = DateTime::Parse(dateString);
		open = Double::Parse(parts[5]);
		high = Double::Parse(parts[6]);
		low = Double::Parse(parts[7]);
		close = Double::Parse(parts[8]);
		volume = Int64::Parse(parts[9]);
	}
};

