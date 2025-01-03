#pragma once
#include "aCandlestick.h"
#include <algorithm>

//https://tubeinzero.blogspot.com/2019/11/single-candlestick-patterns.html

ref class aSmartCandlestick : public aCandlestick
{
public:
	//float properties
	property float range;
	property float bodyRange;
	property float topPrice;
	property float bottomPrice;
	property float upperTail;
	property float lowerTail;
	property float bodyPercent;
	property float topPercent;
	property float bottomPercent;

	//boolean properties
	property bool isBullish;
	property bool isBearish;
	property bool isNeutral;
	property bool isMarubozu;
	property bool isDoji;
	property bool isDragonfly;
	property bool isGravestone;
	property bool isHangman;
	property bool isHammer;
	property bool isInvertedHammer;
	property bool isShootingStar;
	property bool isShavenBottom;
	property bool isShavenHead;

public:
	aSmartCandlestick()
	{}
public:
	aSmartCandlestick(DateTime d, float o, float h, float l, float c, unsigned long v) 
		: aCandlestick(d, o, h, l, c, v) {}
public:
	void setSmartProperties()
	{
		range = high - low;
		topPrice = std::max(open, close);
		bottomPrice = std::min(open, close);
		bodyRange = topPrice - bottomPrice;
		upperTail = high - topPrice;
		lowerTail = bottomPrice - low;
		bodyPercent = (bodyRange / range);
		topPercent = (upperTail / range);
		bottomPercent = (lowerTail / range);
	}
public:
	void setPatterns()
	{
		isBullish = (close > open) && (bodyPercent > 0.03);
		isBearish = (open > close) && (bodyPercent > 0.03);
		isNeutral = bodyPercent <= 0.03;
		isMarubozu = bodyPercent + 0.01 >= 1;
		isDoji = bodyPercent <= 0.01;
		isDragonfly = isDoji && (topPrice == high);
		isGravestone = isDoji && (bottomPrice == low);
		isHangman = (bodyPercent <= 0.3) && (topPrice == high);
		isHammer = (bodyPercent <= 0.4) && (topPercent <= 0.02);
		isInvertedHammer = (bodyPercent <= 0.4) && (bottomPercent <= 0.02);
		isShootingStar = (bodyPercent <= 0.1) && (bottomPrice == low);
		isShavenBottom = bottomPrice == low;
		isShavenHead = topPrice == high;
	}
public:
	aSmartCandlestick(System::String^ row) : aCandlestick(row)
	{
		setSmartProperties();
		setPatterns();
	}
};
