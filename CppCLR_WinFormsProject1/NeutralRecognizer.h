#pragma once
#include "Recognizer.h"

ref class NeutralRecognizer : public Recognizer {
public:
	//default constructor
	NeutralRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Neutral";
	}
	//constructor with parameters
	NeutralRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is neutral
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isNeutral;
	}
};