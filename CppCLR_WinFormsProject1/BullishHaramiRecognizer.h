#pragma once
#include "Recognizer.h"

ref class BullishHaramiRecognizer : public Recognizer {
public:
	//default constructor
	BullishHaramiRecognizer() : Recognizer() {
		numCandle = 2;
		patternName = "Bullish Harami";
	}
	//constructor with parameters
	BullishHaramiRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}

public:
	//overriden function that checks if left is bearish, right is bullish, and
	//left is in between the top and bottom of the right
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		return (sc[0]->isBearish && sc[1]->isBullish && (sc[0]->topPrice > sc[1]->high &&
			sc[0]->bottomPrice < sc[1]->low));
	}
};