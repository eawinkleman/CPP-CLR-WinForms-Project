#pragma once
#include "Recognizer.h"

ref class HammerRecognizer : public Recognizer {
public:
	//default constructor
	HammerRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Hammer";
	}
	//constructor with parameters
	HammerRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is hammer
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isHammer;
	}
};