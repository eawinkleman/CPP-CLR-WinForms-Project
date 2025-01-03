#pragma once
#include "Recognizer.h"

ref class GravestoneRecognizer : public Recognizer {
public:
	//default constructor
	GravestoneRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Gravestone";
	}
	//constructor with parameters
	GravestoneRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is gravestone
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isGravestone;
	}
};