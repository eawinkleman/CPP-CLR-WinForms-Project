#pragma once
#include <string>
#include "aSmartCandlestick.h"

using namespace System;
using namespace System::Collections::Generic;

ref class Recognizer
{
public:
	//values of the number of candlestick in the pattern and the pattern name
	int numCandle;
	String^ patternName;
public:
	//recognize function
	List<int>^ Recognize(List<aSmartCandlestick^>^ smartStick) {
		//an integer list that will contain the index of all candlestick with the specified pattern
		List<int>^ result = gcnew List<int>(smartStick->Count);
		//iterate through the candlestick list
		for (int i = numCandle - 1; i < smartStick->Count; ++i) {
			//create a list of candlesticks based on the number of candesticks in the pattern
			List<aSmartCandlestick^>^ sublist = smartStick->GetRange(i - numCandle + 1,
				numCandle);
			//call recognize pattern, if the candlestick is the specified pattern, add the index
			if (recognizePattern(sublist)) 
				result->Add(i);
		}
		return result;
	}
public:
	//default constructor
	Recognizer() {
		numCandle = 0;
		patternName = "";
	}
public:
	//constructor with parameters
	Recognizer(String^ patname, int patnum) {
		numCandle = patnum;
		patternName = patname;
	}
public:
	//virtual function to allow the specific recognizer classes to override
	virtual bool recognizePattern(List<aSmartCandlestick^>^ cs) = 0;

};
/*
List<Recognizer*> LR = gcnew List<Recognizer*>;

LR.Add(gcnew DojiRecognizer);
LR.Add(gcnew HammerRecognizer);

//Multiple Candlestick Patterns
Peak

Valley

List<int> recognizeDoji(List<sc> smartStick)
{
	List<int> result = gcnew LIst<int> (smartStick.Count);
	for (int i = 0; i < smartStick.Count; i++) {
		if (smartStick[i].isDoji) result.Add(i);	
	}
	return result;
*/