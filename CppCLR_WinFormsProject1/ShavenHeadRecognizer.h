#pragma once
#include "Recognizer.h"

ref class ShavenHeadRecognizer : public Recognizer {
public:
	//default constructor
	ShavenHeadRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Shaven Head";
	}
	//constructor with parameters
	ShavenHeadRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is shaven head
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isShavenHead;
	}
};