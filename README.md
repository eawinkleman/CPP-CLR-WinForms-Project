# CppCLR_WinFormsProject1

Created a Visual Studio Windows Form Project in C++ to read a CSV file from Yahoo Finance and place  them into a candlestick chart, representing the Open, High, Low, and Close values, and a bar graph underneath representing the Volume. 
The project will prompt the user to open files, and for each file opened, a new Form will open with the information above. 
The user can customize the graphs by specifying Start and End Dates for the data, which candlestick patterns the user wants to see, including: 
Bearish, Bullish, Neutral, Marubozu, Doji, Dragonfly Doji, Gravestone, Hangman, Hammer, Inverted Hammer, Shooting Star, Shaven Bottom, Shaven Head, Bearish Harami, Bullish Harami, Engulfing Bearish, Engulfing Bullish, Peak, and Valley. 
The program works with any CSV file in the format: “Ticker”,“Period”,“Date”,“Open”,“High”,“Low”,“Close”,“Volume.”
