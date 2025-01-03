#pragma once
#include "Recognizer.h"

ref class InvertedHammerRecognizer : public Recognizer {
public:
	//default constructor
	InvertedHammerRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Inverted Hammer";
	}
	//constructor with parameters
	InvertedHammerRecognizer(String^ patname, int patnum) : 
		Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is inverted hammer
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isInvertedHammer;
	}
};

