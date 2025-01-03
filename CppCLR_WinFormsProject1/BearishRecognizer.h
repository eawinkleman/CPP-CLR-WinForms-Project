#pragma once
#include "Recognizer.h"

ref class BearishRecognizer : public Recognizer {
public:
	//default constructor
	BearishRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Bearish";
	}
	//constructor with parameters
	BearishRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function checking if candlestick is bearish
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isBearish;
	}
};

