#pragma once
#include "Recognizer.h"

ref class ShootingStarRecognizer : public Recognizer {
public:
	//default constructor
	ShootingStarRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Shooting Star";
	}
	//constructor with parameters
	ShootingStarRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is shooting star
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isShootingStar;
	}
};

