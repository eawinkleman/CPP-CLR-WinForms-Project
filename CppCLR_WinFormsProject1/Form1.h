#pragma once
#include "aCandlestick.h"
#include "aSmartCandlestick.h"
#include "Recognizer.h"
#include "BearishHaramiRecognizer.h"
#include "BearishRecognizer.h"
#include "BullishHaramiRecognizer.h"
#include "BullishRecognizer.h"
#include "DojiRecognizer.h"
#include "DragonflyRecognizer.h"
#include "EngulfingBearishRecognizer.h"
#include "EngulfingBullishRecognizer.h"
#include "GravestoneRecognizer.h"
#include "HammerRecognizer.h"
#include "HangmanRecognizer.h"
#include "InvertedHammerRecognizer.h"
#include "MarubozuRecognizer.h"
#include "NeutralRecognizer.h"
#include "PeakRecognizer.h"
#include "ShavenBottomRecognizer.h"
#include "ShavenHeadRecognizer.h"
#include "ShootingStarRecognizer.h"
#include "ValleyRecognizer.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		//initialize the binding list for the dataGridView
		BindingList<aSmartCandlestick^>^ aCandlestickList = gcnew BindingList<aSmartCandlestick^>();
		//initialize the list for the dataChart
		List<aSmartCandlestick^>^ tempList = gcnew List<aSmartCandlestick^>(aCandlestickList);
	private:
		//a boolean for update data that allows clicking the update button to also apply to properties
		bool updating = false;
	private: System::Windows::Forms::Label^ label_creator;


	private: System::Windows::Forms::Label^ label_properties;

	private: System::Windows::Forms::Label^ label_selectFile;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox_properties;



	private: System::Windows::Forms::Button^ button_creator;
	public:
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox_ticker;
	protected:

	private: System::Windows::Forms::Label^ label_ticker;
	private: System::Windows::Forms::Label^ label_MWD;


	private: System::Windows::Forms::ComboBox^ comboBox_period;
	private: System::Windows::Forms::Button^ button_file;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;












	private: System::Windows::Forms::Button^ button_update;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ dataChart;
	private: System::Windows::Forms::DateTimePicker^ dateTime_start;
	private: System::Windows::Forms::DateTimePicker^ dateTime_end;


	private: System::Windows::Forms::Label^ label_start;
	private: System::Windows::Forms::Label^ label_end;




	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ArrowAnnotation^ arrowAnnotation1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ArrowAnnotation());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->comboBox_ticker = (gcnew System::Windows::Forms::ComboBox());
			this->label_ticker = (gcnew System::Windows::Forms::Label());
			this->label_MWD = (gcnew System::Windows::Forms::Label());
			this->comboBox_period = (gcnew System::Windows::Forms::ComboBox());
			this->button_file = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->dataChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dateTime_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTime_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_start = (gcnew System::Windows::Forms::Label());
			this->label_end = (gcnew System::Windows::Forms::Label());
			this->label_creator = (gcnew System::Windows::Forms::Label());
			this->button_creator = (gcnew System::Windows::Forms::Button());
			this->label_properties = (gcnew System::Windows::Forms::Label());
			this->checkedListBox_properties = (gcnew System::Windows::Forms::CheckedListBox());
			this->label_selectFile = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataChart))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox_ticker
			// 
			this->comboBox_ticker->FormattingEnabled = true;
			this->comboBox_ticker->Items->AddRange(gcnew cli::array< System::Object^  >(23) {
				L"None", L"AAL", L"AAPL", L"AAP", L"ABBV",
					L"ABC", L"ABMD", L"ABT", L"ACN", L"ADBE", L"IBM", L"LUV", L"MSFT", L"NVDA", L"ORCL", L"ORLY", L"WMT", L"XYL", L"YUM", L"ZBH",
					L"ZBRA", L"ZION", L"ZTS"
			});
			this->comboBox_ticker->Location = System::Drawing::Point(55, 7);
			this->comboBox_ticker->Name = L"comboBox_ticker";
			this->comboBox_ticker->Size = System::Drawing::Size(135, 21);
			this->comboBox_ticker->TabIndex = 0;
			this->comboBox_ticker->Text = L"-choose option below-";
			// 
			// label_ticker
			// 
			this->label_ticker->AutoSize = true;
			this->label_ticker->Location = System::Drawing::Point(12, 12);
			this->label_ticker->Name = L"label_ticker";
			this->label_ticker->Size = System::Drawing::Size(37, 13);
			this->label_ticker->TabIndex = 1;
			this->label_ticker->Text = L"Ticker";
			// 
			// label_MWD
			// 
			this->label_MWD->AutoSize = true;
			this->label_MWD->Location = System::Drawing::Point(12, 38);
			this->label_MWD->Name = L"label_MWD";
			this->label_MWD->Size = System::Drawing::Size(37, 13);
			this->label_MWD->TabIndex = 2;
			this->label_MWD->Text = L"Period";
			// 
			// comboBox_period
			// 
			this->comboBox_period->FormattingEnabled = true;
			this->comboBox_period->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"None", L"Month", L"Week", L"Day" });
			this->comboBox_period->Location = System::Drawing::Point(55, 32);
			this->comboBox_period->Name = L"comboBox_period";
			this->comboBox_period->Size = System::Drawing::Size(135, 21);
			this->comboBox_period->TabIndex = 5;
			this->comboBox_period->Text = L"-choose period here-";
			// 
			// button_file
			// 
			this->button_file->Location = System::Drawing::Point(521, 28);
			this->button_file->Name = L"button_file";
			this->button_file->Size = System::Drawing::Size(123, 23);
			this->button_file->TabIndex = 8;
			this->button_file->Text = L"Open";
			this->button_file->UseVisualStyleBackColor = true;
			this->button_file->Click += gcnew System::EventHandler(this, &Form1::button_file_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"*.csv";
			this->openFileDialog->Filter = L"All Stock files (*.csv)| *.csv|Daily Stocks|*.Day.csv|Weekly Stocks|*.Week.csv|Mo"
				L"nthly Stocks(*.Month.csv)|*.Month.csv";
			this->openFileDialog->InitialDirectory = L"..\\..\\..\\..\\";
			this->openFileDialog->Multiselect = true;
			this->openFileDialog->Title = L"C:\\Users\\ericw\\source\\repos\\CppCLR_WinFormsProject1\\Stock Data";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog_FileOk);
			// 
			// button_update
			// 
			this->button_update->AutoSize = true;
			this->button_update->Enabled = false;
			this->button_update->Location = System::Drawing::Point(522, 28);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(124, 23);
			this->button_update->TabIndex = 10;
			this->button_update->Text = L"Update Chart";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Visible = false;
			this->button_update->Click += gcnew System::EventHandler(this, &Form1::button_update_Click);
			// 
			// dataChart
			// 
			arrowAnnotation1->AnchorX = 10;
			arrowAnnotation1->AnchorY = 10;
			arrowAnnotation1->ArrowSize = 2;
			arrowAnnotation1->ClipToChartArea = L"ChartArea_Candle";
			arrowAnnotation1->Name = L"ArrowAnnotation1";
			this->dataChart->Annotations->Add(arrowAnnotation1);
			chartArea1->AlignWithChartArea = L"ChartArea_Volume";
			chartArea1->Name = L"ChartArea_Candle";
			chartArea2->AlignWithChartArea = L"ChartArea_Candle";
			chartArea2->Name = L"ChartArea_Volume";
			this->dataChart->ChartAreas->Add(chartArea1);
			this->dataChart->ChartAreas->Add(chartArea2);
			legend1->Name = L"Legend1";
			this->dataChart->Legends->Add(legend1);
			this->dataChart->Location = System::Drawing::Point(12, 57);
			this->dataChart->Name = L"dataChart";
			series1->ChartArea = L"ChartArea_Candle";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series1->Legend = L"Legend1";
			series1->Name = L"SeriesCandle";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series1->YValueMembers = L"High,Low,Open,Close";
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"ChartArea_Volume";
			series2->Legend = L"Legend1";
			series2->Name = L"SeriesVolume";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series2->YValueMembers = L"Volume";
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int64;
			this->dataChart->Series->Add(series1);
			this->dataChart->Series->Add(series2);
			this->dataChart->Size = System::Drawing::Size(790, 428);
			this->dataChart->TabIndex = 11;
			this->dataChart->Text = L"dataChart";
			title1->Name = L"Title1";
			this->dataChart->Titles->Add(title1);
			this->dataChart->Visible = false;
			// 
			// dateTime_start
			// 
			this->dateTime_start->Location = System::Drawing::Point(273, 8);
			this->dateTime_start->Name = L"dateTime_start";
			this->dateTime_start->Size = System::Drawing::Size(220, 20);
			this->dateTime_start->TabIndex = 12;
			this->dateTime_start->Value = System::DateTime(2021, 1, 1, 0, 0, 0, 0);
			// 
			// dateTime_end
			// 
			this->dateTime_end->Location = System::Drawing::Point(273, 31);
			this->dateTime_end->Name = L"dateTime_end";
			this->dateTime_end->Size = System::Drawing::Size(220, 20);
			this->dateTime_end->TabIndex = 13;
			this->dateTime_end->Value = System::DateTime(2023, 10, 14, 16, 52, 57, 0);
			// 
			// label_start
			// 
			this->label_start->AutoSize = true;
			this->label_start->Location = System::Drawing::Point(212, 12);
			this->label_start->Name = L"label_start";
			this->label_start->Size = System::Drawing::Size(55, 13);
			this->label_start->TabIndex = 15;
			this->label_start->Text = L"Start Date";
			// 
			// label_end
			// 
			this->label_end->AutoSize = true;
			this->label_end->Location = System::Drawing::Point(215, 35);
			this->label_end->Name = L"label_end";
			this->label_end->Size = System::Drawing::Size(52, 13);
			this->label_end->TabIndex = 16;
			this->label_end->Text = L"End Date";
			// 
			// label_creator
			// 
			this->label_creator->AutoSize = true;
			this->label_creator->Location = System::Drawing::Point(707, 12);
			this->label_creator->Name = L"label_creator";
			this->label_creator->Size = System::Drawing::Size(47, 13);
			this->label_creator->TabIndex = 17;
			this->label_creator->Text = L"-Creator-";
			// 
			// button_creator
			// 
			this->button_creator->Location = System::Drawing::Point(669, 28);
			this->button_creator->Name = L"button_creator";
			this->button_creator->Size = System::Drawing::Size(119, 23);
			this->button_creator->TabIndex = 18;
			this->button_creator->Text = L"Name";
			this->button_creator->UseVisualStyleBackColor = true;
			this->button_creator->Click += gcnew System::EventHandler(this, &Form1::button_creator_Click);
			// 
			// label_properties
			// 
			this->label_properties->AutoSize = true;
			this->label_properties->Location = System::Drawing::Point(679, 162);
			this->label_properties->Name = L"label_properties";
			this->label_properties->Size = System::Drawing::Size(90, 13);
			this->label_properties->TabIndex = 20;
			this->label_properties->Text = L"-Show Properties-";
			this->label_properties->Visible = false;
			// 
			// checkedListBox_properties
			// 
			this->checkedListBox_properties->CheckOnClick = true;
			this->checkedListBox_properties->Enabled = false;
			this->checkedListBox_properties->FormattingEnabled = true;
			this->checkedListBox_properties->Items->AddRange(gcnew cli::array< System::Object^  >(20) {
				L"Bullish", L"Bearish", L"Neutral",
					L"Marubozu", L"Doji", L"Dragonfly", L"Gravestone", L"Hangman", L"Hammer", L"Inverted Hammer", L"Shooting Star", L"Shaven Bottom",
					L"Shaven Head", L"Engulfing Bearish", L"Engulfing Bullish", L"Bearish Harami", L"Bullish Harami", L"Peak", L"Valley", L"Select All"
			});
			this->checkedListBox_properties->Location = System::Drawing::Point(669, 178);
			this->checkedListBox_properties->Name = L"checkedListBox_properties";
			this->checkedListBox_properties->Size = System::Drawing::Size(108, 304);
			this->checkedListBox_properties->TabIndex = 21;
			this->checkedListBox_properties->Visible = false;
			this->checkedListBox_properties->Click += gcnew System::EventHandler(this, &Form1::checkedListBox_properties_Click);
			// 
			// label_selectFile
			// 
			this->label_selectFile->AutoSize = true;
			this->label_selectFile->Location = System::Drawing::Point(554, 12);
			this->label_selectFile->Name = L"label_selectFile";
			this->label_selectFile->Size = System::Drawing::Size(62, 13);
			this->label_selectFile->TabIndex = 3;
			this->label_selectFile->Text = L"-Select File-";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 497);
			this->Controls->Add(this->checkedListBox_properties);
			this->Controls->Add(this->label_properties);
			this->Controls->Add(this->button_creator);
			this->Controls->Add(this->label_creator);
			this->Controls->Add(this->label_end);
			this->Controls->Add(this->label_start);
			this->Controls->Add(this->dateTime_end);
			this->Controls->Add(this->dateTime_start);
			this->Controls->Add(this->dataChart);
			this->Controls->Add(this->button_update);
			this->Controls->Add(this->button_file);
			this->Controls->Add(this->comboBox_period);
			this->Controls->Add(this->label_selectFile);
			this->Controls->Add(this->label_MWD);
			this->Controls->Add(this->label_ticker);
			this->Controls->Add(this->comboBox_ticker);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//On startup
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		//Set the X and Y Axis Titles for both Candle and Volume Charts on Form load
		dataChart->ChartAreas["ChartArea_Candle"]->AxisX->Title = "Date";
		dataChart->ChartAreas["ChartArea_Candle"]->AxisY->Title = "Price";

		dataChart->ChartAreas["ChartArea_Volume"]->AxisX->Title = "Date";
		dataChart->ChartAreas["ChartArea_Volume"]->AxisY->Title = "Volume";

		//Resize the form
		Height = 110;
		Text = "Load Stock";
	}
	//Show the Open File Dialog when button_file is clicked
private: System::Void button_file_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Create a string based on what the user chose in the ticker and period combo box
	String^ newName;

	//creating the \file name with search parameters
	if (comboBox_ticker->SelectedItem == "None" && comboBox_period->SelectedItem == "None")
		newName = "\*.csv";
	else if (comboBox_ticker->SelectedItem == "None")
		newName = "\*" + comboBox_period->SelectedItem + "\*.csv";
	else if (comboBox_period->SelectedItem == "None")
		newName = "\*" + comboBox_ticker->SelectedItem + "\*.csv";
	else
		newName = "\*" + comboBox_ticker->SelectedItem + "\*" + comboBox_period->SelectedItem + "\*.csv";
	
	openFileDialog->FileName = newName;
	System::Windows::Forms::DialogResult result = openFileDialog->ShowDialog();
}
	//If a File was sucessfully opened in OpenFileDialog
private: System::Void openFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) 
{

	//Clear the Candlesticks, TempList, and dataChart Titles, as a precaution
	aCandlestickList->Clear();
	tempList->Clear();
	dataChart->Titles->Clear();

	//Clear the points in the series areas, as a precaution
	dataChart->Series["SeriesCandle"]->Points->Clear();
	dataChart->Series["SeriesVolume"]->Points->Clear();

	//get the start and end dateTime values based on the dateTimePickers
	DateTime start = dateTime_start->Value;
	DateTime end = dateTime_end->Value;

	//Get the filename and filenames for the file chosen in OpenFileDialog
	String^ filename = openFileDialog->FileName;
	array<String^>^ filenames = openFileDialog->FileNames;
	Text = filename;

	//create max variable to find maximum
	int max = 0;

	//iterate through the filenames, as multiselect is on
	for each (String^ fname in filenames)
	{
		//create a new form1 instance for each new file
		Form1^ extraForm = gcnew Form1();
		extraForm->Show();

		//disable and hide the file button, to be replaced with the update button
		extraForm->button_file->Enabled = false;
		extraForm->button_file->Visible = false;

		extraForm->button_update->Enabled = true;
		extraForm->button_update->Visible = true;

		//lock the comboBoxes
		extraForm->comboBox_period->Enabled = false;
		extraForm->comboBox_ticker->Enabled = false;

		//make the dataChart and checkedListBox visible and enabled
		extraForm->dataChart->Visible = true;
		extraForm->label_properties->Visible = true;

		extraForm->checkedListBox_properties->Enabled = true;
		extraForm->checkedListBox_properties->Visible = true;

		//Change the label above the button's text
		extraForm->label_selectFile->Text = "-Refresh-";

		//Resize the Form
		extraForm->Width = 830;
		extraForm->Height = 536;
		

		//Create a new instance of streamReader, reading from fname 
		StreamReader^ reader = gcnew StreamReader(fname);
		
		//set header to the first line in the fname
		String^ header = reader->ReadLine();
		extraForm->Text = fname;

		//Compare the first line to the reference string in aSmartCandlestick
		if (header == aSmartCandlestick::referenceString)
		{
			//While not the end of the file
			while (!reader->EndOfStream)
			{
				//read line by line
				String^ oneLine = reader->ReadLine();

				//try to add the candlesticks to the binding list
				try {
					aSmartCandlestick^ candlestick = gcnew aSmartCandlestick(oneLine);
					extraForm->aCandlestickList->Add(candlestick);

					//Update extraForm's ticker and period accordingly
					extraForm->comboBox_ticker->Text = candlestick->ticker;
					extraForm->comboBox_period->Text = candlestick->period;

					//If the candlestick is after or equal to the start date and equal or before the end date
					if (candlestick->date >= start && candlestick->date <= end)
					{
						//add the candlestick to to the extraForm's templist and add the points to the extraForm's dataChart areas
						extraForm->tempList->Add(candlestick);
						if (candlestick->high > max)
							max = candlestick->high;
						//extraForm->dataChart->Series["SeriesCandle"]->Points->AddXY(candlestick->date, candlestick->high, candlestick->low, candlestick->open, candlestick->close);
						//extraForm->dataChart->Series["SeriesVolume"]->Points->AddXY(candlestick->date, candlestick->volume);
					}
				}
				//send a error message if there is an error (try-catch was used mainly during testing)
				catch (FormatException^ ex) {
					MessageBox::Show("Error parsing date in the following line: " + oneLine + "\nError Message: " + ex->Message, "Date Parsing Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}


			}

			//close the reader
			reader->Close();

			//Set a chart title for the extaForm using the ticker and period
			String^ chartTitle = extraForm->comboBox_ticker->Text + "-" + extraForm->comboBox_period->Text;
			extraForm->dataChart->Titles->Add(chartTitle);

			//Project 1's DataGridView code
			/*
			//link the binding list to the dataGridView
			dataGridView->DataSource = aCandlestickList;

			//Split the header to get the names for the columns in dataGridView
			array<String^>^ columnNames = header->Split(aSmartCandlestick::delimiter, StringSplitOptions::RemoveEmptyEntries);

			//start at 2, and iterate until end of the array

			for (int i = 2; i < columnNames->Length; i++)
			{
				dataGridView->Columns[i - 2]->HeaderText = columnNames[columnNames->Length + 1 - i];
			}
			*/

			//set the time of extraForm's dateTime
			extraForm->dateTime_start->Value = dateTime_start->Value;
			extraForm->dateTime_end->Value = dateTime_end->Value;

			//set the value of the y-axis maximum to be 20 higher
			
			extraForm->dataChart->ChartAreas["ChartArea_Candle"]->AxisY->Maximum = max + 20;

			//set the DataSource of extraForm's datachart to the list
			extraForm->dataChart->DataSource = extraForm->tempList;
			extraForm->dataChart->DataBind();
			Text = "Load Stock";
		}
		//If the wrong file was loaded
		else
		{
			//Send a message
			MessageBox::Show("Wrong File Loaded, please try again", "Error");
		}
	}

}
	//When the button_update is clicked (updates the data)
private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e) {

	//set the bool to true, since you're updating
	updating = true;
	
	//call updateData
	updateData();
	
	//Set the event arguments to allow checkedListBox_properties_Click to be called
	System::EventArgs^ eventArgs = gcnew System::EventArgs();

	// Call the checkedListBox_properties_Click method
	checkedListBox_properties_Click(checkedListBox_properties, eventArgs);

	//check if a file was opened before
	if (aCandlestickList->Count > 0)
	{
		//Send a message to tell the user the chart was updated
		MessageBox::Show("Chart Updated!", "Success");
	}
	else
	{
		//Send a message to tell the user no data was available, so nothing was updated
		MessageBox::Show("No Data Available.", "Failure");
	}
	//reset the bool to false, as you are no longer updating
	updating = false;
}
	//Tell the name of the creator
private: System::Void button_creator_Click(System::Object^ sender, System::EventArgs^ e) {
	//Send a message of my name and UID
	MessageBox::Show("Created By Eric Winkleman, U82198361", "Yes, that's my name");
}
private: void updateData(){
	
	//Clear the templist
	tempList->Clear();

	//set the start and end values based on the dateTimePickers
	DateTime start = dateTime_start->Value;
	DateTime end = dateTime_end->Value;

	int max = 0;

	//Use the binding list to get the new values of tempList
	for each (aSmartCandlestick^ candlestick in aCandlestickList)
	{

		//Check if the candlesticks are between the start and end dates specified in the DateTimePickers
		if (candlestick->date >= start && candlestick->date <= end)
		{
			//add a candlestick to tempList
			tempList->Add(candlestick);
			if (candlestick->high > max)
				max = candlestick->high;
		}
	}

	//Clear the dataCharts in both series areas
	dataChart->Series["SeriesCandle"]->Points->Clear();
	dataChart->Series["SeriesVolume"]->Points->Clear();

	//Iterate through the new tempList and add the points to both charts
	/*for each (aSmartCandlestick ^ candlestick in tempList) {
		dataChart->Series["SeriesCandle"]->Points->AddXY(candlestick->date, candlestick->high, candlestick->low, candlestick->open, candlestick->close);
		dataChart->Series["SeriesVolume"]->Points->AddXY(candlestick->date, candlestick->volume);
	}
	*/
	//set the value of the y-axis maximum to be 20 higher
	dataChart->ChartAreas["ChartArea_Candle"]->AxisY->Maximum = max + 20;

	//set the DataSource of dataChat to tempList
	dataChart->DataSource = tempList;
	dataChart->DataBind();
}
	   //WHen an item is clicked in the checkedListBox
private: System::Void checkedListBox_properties_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//deselect all annotations
	dataChart->Annotations->Clear();

	//i checks if a property is available or not
	int i = 0;
	//j counts the iterations (for testing)
	int j = 0;
	//bool to set the state of Select All
	bool iState = true;

	//create a list of strings to iterate through, because items cannot have 
	// their checked state changed when iterating through the checked items
	List<String^>^ checkItems = gcnew List<String^>();

	//if the method was called through the update button, simply skip this step
	if (updating == true);
	//Check if the user selected the Select All option
	else if (checkedListBox_properties->SelectedItem->ToString() == "Select All") {
		//if the state was true before, flip to false
		if (checkedListBox_properties->GetItemChecked(checkedListBox_properties->SelectedIndex) == true)
			iState = false;
		//if the state was false, flip to true
		else
			iState = true;
		//for all items, not including Select All, set the checked state to iState
		for (int a = 0; a < checkedListBox_properties->Items->Count - 1; a++)
			checkedListBox_properties->SetItemChecked(a, iState);
	}
	
	//for each checked item, add that item to the list
	for each (String^ item in checkedListBox_properties->CheckedItems)
		checkItems->Add(item);
	
	//if the method was called through the update button, simply skip this step
	if (updating == true);

	//it is important to add or remove the selected item since the click is not updated
	// until after the method ends

	//if the selected item was false before the click, add it to the checkitems list
	else if (checkedListBox_properties->GetItemChecked(checkedListBox_properties->SelectedIndex) == false)
		checkItems->Add(checkedListBox_properties->SelectedItem->ToString());
	
	//else (it was true before), remove it from the list
	else
		checkItems->Remove(checkedListBox_properties->SelectedItem->ToString());

	//iterate through all the strings in check items, checking which items were selected
	for each (String^ prop in checkItems)
	{
		//set i to 0 at the start of every prop check
		i = 0;
		//check which item prop matches
		if (prop == "Bullish") {
			
			//create a new instance of the Recognizer that matches prop
			BullishRecognizer^ bullReg = gcnew BullishRecognizer();
			//create a list of integers that contain the index of candlesticks matching prop
			List <int>^ bullInt = bullReg->Recognize(tempList);
			
			//for each index in the list
			for each (int value in bullInt)
			{
				//annotate function
				createAnnotation(tempList[value], Color::DarkGreen, prop);

				//add 1 to i
				i++;

			}
			//if i = 0 simply implies that no candlesticks had the specified property
			if (i == 0) {
				//produce an error message and set the checked property to false
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(0, false);
			}
			//add 1 to the iterations counter (for testing purposes)
			j++;
		}
		//all other else if statements are similar to the one above unless specified
		else if (prop == "Bearish") {
			
			BearishRecognizer^ bearReg = gcnew BearishRecognizer();
			List <int>^ bearInt = bearReg->Recognize(tempList);

			for each (int value in bearInt) 
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkRed, prop);

				i++;
			}

			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(1, false);
			}
			j++;
		}

		else if (prop == "Neutral") {
			
			NeutralRecognizer^ NeutReg = gcnew NeutralRecognizer();
			List <int>^ neutInt = NeutReg->Recognize(tempList);
			
			for each (int value in neutInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkGray, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(2, false);
			}
			j++;
		}
		else if (prop == "Marubozu") {
			
			MarubozuRecognizer^ MaruReg = gcnew MarubozuRecognizer();
			List <int>^ maruInt = MaruReg->Recognize(tempList);
			
			for each (int value in maruInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkGoldenrod, prop);

				i++;

			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(3, false);
			}
			j++;
		}
		else if (prop == "Doji") {

			DojiRecognizer^ DojiReg = gcnew DojiRecognizer();
			List <int>^ dojiInt = DojiReg->Recognize(tempList);

			for each (int value in dojiInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkBlue, prop);
				
				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(4, false);
			}
			j++;
		}
		else if (prop == "Dragonfly") {

			DragonflyRecognizer^ DragReg = gcnew DragonflyRecognizer();
			List <int>^ dragInt = DragReg->Recognize(tempList);

			for each (int value in dragInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkOrange, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(5, false);
			}
			j++;
		}
		else if (prop == "Gravestone") {

			GravestoneRecognizer^ GravReg = gcnew GravestoneRecognizer();
			List <int>^ gravInt = GravReg->Recognize(tempList);

			for each (int value in gravInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkViolet, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(6, false);
			}
			j++;
		}
		else if (prop == "Hangman") {

			HangmanRecognizer^ HangReg = gcnew HangmanRecognizer();
			List <int>^ hangInt = HangReg->Recognize(tempList);

			for each (int value in hangInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkMagenta, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(7, false);
			}
			j++;
		}
		else if (prop == "Hammer") {

			HammerRecognizer^ HammReg = gcnew HammerRecognizer();
			List <int>^ hammInt = HammReg->Recognize(tempList);

			for each (int value in hammInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkSalmon, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(8, false);
			}
			j++;
		}
		else if (prop == "Inverted Hammer") {

			InvertedHammerRecognizer^ InHaReg = gcnew InvertedHammerRecognizer();
			List <int>^ inhaInt = InHaReg->Recognize(tempList);

			for each (int value in inhaInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::DarkOrchid, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(9, false);
			}
			j++;
		}
		else if (prop == "Shooting Star") {

			ShootingStarRecognizer^ StarReg = gcnew ShootingStarRecognizer();
			List <int>^ starInt = StarReg->Recognize(tempList);

			for each (int value in starInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::LightYellow, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(10, false);
			}
			j++;
		}
		else if (prop == "Shaven Bottom") {

			ShavenBottomRecognizer^ BottReg = gcnew ShavenBottomRecognizer();
			List <int>^ bottInt = BottReg->Recognize(tempList);

			for each (int value in bottInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::RosyBrown, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(11, false);
			}
			j++;
		}
		else if (prop == "Shaven Head") {

			ShavenHeadRecognizer^ HeadReg = gcnew ShavenHeadRecognizer();
			List <int>^ headInt = HeadReg->Recognize(tempList);

			for each (int value in headInt)
			{
				//annotate
				createAnnotation(tempList[value], Color::Black, prop);
					
				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(12, false);
			}
			j++;
		}
		else if (prop == "Engulfing Bearish") {

			EngulfingBearishRecognizer^ EnBeReg = gcnew EngulfingBearishRecognizer();
			List <int>^ enbeInt = EnBeReg->Recognize(tempList);

			for each (int value in enbeInt)
			{
				//annotate (the right candlestick of the two will be annotated)
				createAnnotation(tempList[value], Color::LightCoral, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(13, false);
			}
			j++;
		}
		else if (prop == "Engulfing Bullish") {

			EngulfingBullishRecognizer^ EnBuReg = gcnew EngulfingBullishRecognizer();
			List <int>^ enbuInt = EnBuReg->Recognize(tempList);

			for each (int value in enbuInt)
			{
				//annotate (the right candlestick of the two will be annotated)
				createAnnotation(tempList[value], Color::LightSeaGreen, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(14, false);
			}
			j++;
		}
		else if (prop == "Bearish Harami") {

			BearishHaramiRecognizer^ BeHaReg = gcnew BearishHaramiRecognizer();
			List <int>^ bnhaInt = BeHaReg->Recognize(tempList);

			for each (int value in bnhaInt)
			{
				//annotate (the right candlestick of the two will be annotated)
				createAnnotation(tempList[value], Color::PaleVioletRed, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(15, false);
			}
			j++;
		}
		else if (prop == "Bullish Harami") {

			BullishHaramiRecognizer^ BuHaReg = gcnew BullishHaramiRecognizer();
			List <int>^ buhaInt = BuHaReg->Recognize(tempList);

			for each (int value in buhaInt)
			{
				//annotate (the right candlestick of the two will be annotated)
				createAnnotation(tempList[value], Color::PaleGreen, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(16, false);
			}
			j++;
		}
		else if (prop == "Peak") {

			PeakRecognizer^ PeakReg = gcnew PeakRecognizer();
			List <int>^ peakInt = PeakReg->Recognize(tempList);

			for each (int value in peakInt)
			{
				//annotate (the middle candlestick of the three will be annotated)
				createAnnotation(tempList[value - 1], Color::Chocolate, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(17, false);
			}
			j++;
		}
		else if (prop == "Valley") {

			ValleyRecognizer^ VallReg = gcnew ValleyRecognizer();
			List <int>^ vallInt = VallReg->Recognize(tempList);

			for each (int value in vallInt)
			{
				//annotate (the middle candlestick of the three will be annotated)
				createAnnotation(tempList[value - 1], Color::Maroon, prop);

				i++;
			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(18, false);
			}
			j++;
		}
		//simply do nothing if the prop is Select All
		else if (prop == "Select All");
		//If somehow the prop is unrecognized (used mainly in testing)
		else 
		{
			MessageBox::Show("Unrecognized Property", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Message to delay another press (quick clicks causes some errors)
		if (i > 0)
			MessageBox::Show(i.ToString() + " Found", prop + " Property Found", MessageBoxButtons::OK, MessageBoxIcon::None);
	}
	//Message to delay another press (quick clicks causes some errors)
	if (i == 0)
		MessageBox::Show("No Property Found","Attention!", MessageBoxButtons::OK, MessageBoxIcon::Information);
	//Message Box to print the number of Iterations (used for testing)
	//MessageBox::Show(j.ToString(), "Number of Iterations", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
/*
else if (prop == "Bearish") {
			for each (aSmartCandlestick^ candlestick in tempList)
			{
				if (candlestick->isBearish) {
					//annotate
					createAnnotation(candlestick, Color::DarkRed, prop);

					i++;
				}

			}
			if (i == 0) {
				MessageBox::Show(prop + " Property Not Found", "Attention!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				checkedListBox_properties->SetItemChecked(1, false);
			}
			j++;
		}
*/

		//create annotation function
private: void createAnnotation(aSmartCandlestick^ candlestick, Color color, String^ prop) {
	
	//create a new arrow annotation
	ArrowAnnotation^ arrow = gcnew ArrowAnnotation();

	//bind the x axis and y axis to the Candle chart area
	arrow->AxisX = dataChart->ChartAreas["ChartArea_Candle"]->AxisX;
	arrow->AxisY = dataChart->ChartAreas["ChartArea_Candle"]->AxisY;
	arrow->ClipToChartArea = "ChartArea_Candle";

	//set the arrow's looks and size
	arrow->ArrowSize = 1;
	arrow->ArrowStyle = ArrowStyle::Simple;
	arrow->LineWidth = 1;
	//width of 0 allows the arrow to stand vertically
	arrow->Width = 0;
	//set the color depending on which property the arrow represents
	arrow->LineColor = color;
	arrow->BackColor = color;
	arrow->Visible = true;

	// Set the ending point using ArrowSize and Y value
	//have the Bullish, Bearish, and Neutral property arrows appear above 
	// the candlestick, for better visibility on multiple selects
	if (prop == "Bullish" || prop == "Bearish" || prop == "Neutral")
	{
		arrow->Height = -5;
		arrow->Y = candlestick->high + 5;
		arrow->AnchorDataPoint = gcnew DataPoint(candlestick->date.ToOADate(), candlestick->high);
	}
	//have all other property arrows appear below the candlestick
	else
	{
		arrow->Height = 5;
		arrow->Y = candlestick->low - 5;
		arrow->AnchorDataPoint = gcnew DataPoint(candlestick->date.ToOADate(), candlestick->low);
	}
	arrow->X = candlestick->date.ToOADate();
	
	//add arrow
	dataChart->Annotations->Add(arrow);
}
};
};

