#pragma once
#include "Recognizer.h"

ref class DragonflyRecognizer : public Recognizer {
public:
	//default constructor
	DragonflyRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Dragonfly";
	}
	//constructor with parameters
	DragonflyRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is dragonfly
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isDragonfly;
	}
};