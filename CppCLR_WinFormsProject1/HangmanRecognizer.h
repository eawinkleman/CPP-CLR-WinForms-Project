#pragma once
#include "Recognizer.h"

ref class HangmanRecognizer : public Recognizer {
public:
	//default constructor
	HangmanRecognizer() : Recognizer() {
		numCandle = 1;
		patternName = "Hangman";
	}
	//constructor with parameters
	HangmanRecognizer(String^ patname, int patnum) : Recognizer(patname, patnum) {
	}
public:
	//overriden function that checks if candlestick is hangman
	bool recognizePattern(List<aSmartCandlestick^>^ sc) override {
		aSmartCandlestick^ stick = sc[0];
		return stick->isHangman;
	}
};
