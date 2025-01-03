#pragma once
#include "Recognizer.h"

ref class DojiRecognizer : public Recognizer {
public:
	//default constructor
	DojiRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Doji";
	}
	//constructor with parameters
	DojiRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is doji
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isDoji;
	}
};

