#pragma once
#include "Recognizer.h"

ref class EngulfingBullishRecognizer : public Recognizer {
public:
	//default constructor
	EngulfingBullishRecognizer() : Recognizer() {
		numCandle = 2;
		patternName = "Engulfing Bullish";
	}
	//constructor with parameters
	EngulfingBullishRecognizer(String^ patname, int patnum) : 
		Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if left is bearish, right is bullish, left top and
	//bottom is between right top and bottom, and left high and low are between right
	//high and low
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		return (sc[0]->isBearish && sc[1]->isBullish && (sc[1]->topPrice > sc[0]->topPrice
			&& sc[1]->bottomPrice < sc[0]->bottomPrice && sc[1]->high > sc[0]->high &&
			sc[1]->low < sc[0]->low));
	}
};