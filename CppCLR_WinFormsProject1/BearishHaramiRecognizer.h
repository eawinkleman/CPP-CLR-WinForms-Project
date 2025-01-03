#pragma once
#include "Recognizer.h"

ref class BearishHaramiRecognizer : public Recognizer {
public:
	//default constructor
	BearishHaramiRecognizer() : Recognizer() {
		numCandle = 2;
		patternName = "Bearish Harami";
	}
	//constructor with parameters
	BearishHaramiRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overridden recognize pattern
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		//check if left is bullish, right is bearish, and left is in between top and bottom of right
		return (sc[0]->isBullish && sc[1]->isBearish && (sc[0]->topPrice > sc[1]->high && 
			sc[0]->bottomPrice < sc[1]->low));
	}
};