#pragma once
#include "Recognizer.h"

ref class BullishRecognizer : public Recognizer {
public:
	//default constructor
	BullishRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Bullish";
	}
	//constructor with parameters
	BullishRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is bullish
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isBullish;
	}
};
