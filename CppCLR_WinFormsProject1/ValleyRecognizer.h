#pragma once
#include "Recognizer.h"

ref class ValleyRecognizer : public Recognizer {
public:
	//default constructor
	ValleyRecognizer() : Recognizer() {
		numCandle = 3;
		patternName = "Valley";
	}
	//constructor with parameters
	ValleyRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if the middle candlestick's low is lower than the
	//left and right candlestick
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		return (sc[1]->low < sc[0]->low && sc[1]->low < sc[2]->low);
	}
};