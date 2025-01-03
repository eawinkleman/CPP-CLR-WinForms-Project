#pragma once
#include "Recognizer.h"

ref class MarubozuRecognizer : public Recognizer {
public:
	//default constructor
	MarubozuRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Marubozu";
	}
	//constructor with parameters
	MarubozuRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is marubozu
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isMarubozu;
	}
};
