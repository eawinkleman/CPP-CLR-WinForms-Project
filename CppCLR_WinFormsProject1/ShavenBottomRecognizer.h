#pragma once
#include "Recognizer.h"

ref class ShavenBottomRecognizer : public Recognizer {
public:
	//default constructor
	ShavenBottomRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "ShavenBottom";
	}
	//constructor with parameters
	ShavenBottomRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is shaven bottom
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isShavenBottom;
	}
};