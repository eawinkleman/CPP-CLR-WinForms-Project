#pragma once
#include "Recognizer.h"

ref class PeakRecognizer : public Recognizer {
public:
	//default constructor
	PeakRecognizer() : Recognizer() {
		numCandle = 3;
		patternName = "Peak";
	}
	//constructor with parameters
	PeakRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if the middle candlestick's high is greater than the
	//left and right candlestick
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		return (sc[1]->high > sc[0]->high && sc[1]->high > sc[2]->high);
	}
};