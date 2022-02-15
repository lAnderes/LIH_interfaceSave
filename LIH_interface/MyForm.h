#pragma once

#include <stdlib.h>   
#include <stdio.h>
#include <string.h>
#include< tgmath.h >
#include< limits.h >

#include "EpcDLL.h"
#include <chrono>
#include <cmath>

#pragma comment(lib, "EpcDLL.lib")


namespace LIHinterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	EPC_INT16 DacChannelNumber = 0;
	EPC_INT16 AdcChannelNumber = 4;

	EPC_INT32 DacSamplesPerChannel = 11;
	EPC_INT32 AdcSamplesPerChannel = 11;

	EPC_INT16 DacChannels_[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	EPC_INT16 AdcChannels_[17] = { 0, 1, 2, 3, 0, 0,0,0,0,0,0,0,0,0,0,0,0 };

	EPC_SET16 AcquisitionMode = LIH_EnableDacOutput;

	EPC_LONGREAL SampleInterval_ = 1;
	EPC_LONGREAL* SampleInterval = &SampleInterval_;

	double time = 0;

	int maxBlockSize = 1000;

	int daBlockSize = maxBlockSize;
	int AdBlockSize = maxBlockSize;

	int writtenSamples = 0;
	int remainingDaSamples = 0;

	int readSamples = 0;
	int remainingAdSamples = 0;

	int SamplesToWriteToFifo = 0;


	bool liveViewMode = 0;
	bool liveIsRunning = 0;


	EPC_INT16* InData[6];
	EPC_INT16* OutData[6];

	double value = 0;

	int endLive = 0;
	


	/*OutData[0] = new EPC_INT16[AdcSamplesPerChannel];*/
	//EPC_INT16 OutData1[11] = { 0 };
	//EPC_INT16 OutData2[11] = { 0 };
	//EPC_INT16 OutData3[11] = { 0 };
	//EPC_INT16 OutData4[11] = { 0 };

	//Les donées à mettre dans la FIFO pour l'écriture et les buffers ou les mesures seront enregistrées
	/*EPC_ADDR32 OutData[11] = { OutData0, OutData3 };*/



	//EPC_ADDR32 InData[11] = { InData0, InData1, InData2, InData3, InData4, InData5, InData6 };


	//EPC_INT16 InData[8][11] = { 0 };






	EPC_BOOLEAN immediateData = false;

	EPC_BOOLEAN SetStimEnd = 1;
	EPC_BOOLEAN ReadContinuously = true;

	EPC_BOOLEAN isRunning;



	int doHalt = 0;


	int result;
	unsigned char* error_message[256] = { 0 };
	unsigned char* path[256] = { 0 };
	LIH_OptionsType options;




	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

	

	array< Queue^ >^ Queues = gcnew array< Queue^ >(5);
	Mutex^ mut = gcnew Mutex();
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	public:
		Mutex^ mutLiveBoolean = gcnew Mutex();

		MyForm(void)
		{

			for(int i = 0; i< 5; i++)
				Queues[i] = gcnew Queue();

			for (int i = 0; i < 5; i++)
				InData[i] = NULL;

			InitializeComponent();

			comboBox3->SelectedIndex = 0;
			comboBox2->SelectedIndex = 0;

			memset(&options, 0, sizeof(options));
			strcpy_s((char*)&options.DeviceNumber, sizeof(options.DeviceNumber), "560118080708100");




			options.UseUSB = true;
			result =
				LIH_InitializeInterface(
					(EPC_Str256Ptr)error_message,
					EPC9_Epc7Ampl,
					LIH_ITC18Board,
					&options,
					sizeof(options));

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^ ADCcheckedListBox;
	private: System::Windows::Forms::CheckedListBox^ DACcheckedListBox;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::TextBox^ durationTextBox;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;



	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->ADCcheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->DACcheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->durationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ADCcheckedListBox
			// 
			this->ADCcheckedListBox->FormattingEnabled = true;
			this->ADCcheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7"
			});
			this->ADCcheckedListBox->Location = System::Drawing::Point(3, 3);
			this->ADCcheckedListBox->Name = L"ADCcheckedListBox";
			this->ADCcheckedListBox->Size = System::Drawing::Size(42, 124);
			this->ADCcheckedListBox->TabIndex = 0;
			this->ADCcheckedListBox->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MyForm::ADCcheckedListBox_ItemCheck);
			// 
			// DACcheckedListBox
			// 
			this->DACcheckedListBox->FormattingEnabled = true;
			this->DACcheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6",
					L"7"
			});
			this->DACcheckedListBox->Location = System::Drawing::Point(51, 3);
			this->DACcheckedListBox->Name = L"DACcheckedListBox";
			this->DACcheckedListBox->Size = System::Drawing::Size(42, 124);
			this->DACcheckedListBox->TabIndex = 1;
			this->DACcheckedListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::DACcheckedListBox_SelectedIndexChanged);
			// 
			// durationTextBox
			// 
			this->durationTextBox->Location = System::Drawing::Point(3, 83);
			this->durationTextBox->Name = L"durationTextBox";
			this->durationTextBox->Size = System::Drawing::Size(131, 20);
			this->durationTextBox->TabIndex = 3;
			this->durationTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::durationTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"duration [sec]";
			// 
			// StartButton
			// 
			this->StartButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->StartButton->Location = System::Drawing::Point(3, 133);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(75, 23);
			this->StartButton->TabIndex = 5;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::StartButton_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 120;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Statut";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Stim 1", L"Stim 2", L"Stim 3" });
			this->comboBox1->Location = System::Drawing::Point(99, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(38, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// chart1
			// 
			chartArea1->AxisX->IsStartedFromZero = false;
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->Name = L"ChartArea1";
			chartArea2->CursorX->IsUserSelectionEnabled = true;
			chartArea2->Name = L"ChartArea2";
			chartArea3->CursorX->IsUserSelectionEnabled = true;
			chartArea3->Name = L"ChartArea3";
			chartArea4->CursorX->IsUserSelectionEnabled = true;
			chartArea4->Name = L"ChartArea4";
			chartArea5->CursorX->IsUserSelectionEnabled = true;
			chartArea5->Name = L"ChartArea5";
			chartArea6->CursorX->IsUserSelectionEnabled = true;
			chartArea6->Name = L"ChartArea6";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->ChartAreas->Add(chartArea3);
			this->chart1->ChartAreas->Add(chartArea4);
			this->chart1->ChartAreas->Add(chartArea5);
			this->chart1->ChartAreas->Add(chartArea6);
			this->chart1->Cursor = System::Windows::Forms::Cursors::Default;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(209, 3);
			this->chart1->MaximumSize = System::Drawing::Size(904, 1500);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea2";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea3";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series3->Legend = L"Legend1";
			series3->Name = L"Series3";
			series4->ChartArea = L"ChartArea4";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series4->Legend = L"Legend1";
			series4->Name = L"Series4";
			series5->ChartArea = L"ChartArea5";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series5->Legend = L"Legend1";
			series5->Name = L"Series5";
			series6->ChartArea = L"ChartArea6";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series6->Legend = L"Legend1";
			series6->Name = L"Series6";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Size = System::Drawing::Size(904, 878);
			this->chart1->TabIndex = 8;
			this->chart1->Text = L"chart1";
			// 
			// comboBox2
			// 
			this->comboBox2->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(6) {
				L"1", L"10", L"100", L"200",
					L"500", L"1000"
			});
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"50", L"100", L"200", L"500" });
			this->comboBox2->Location = System::Drawing::Point(3, 43);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(128, 21);
			this->comboBox2->TabIndex = 9;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 407);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 374);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 432);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 12;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(3, 307);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(163, 26);
			this->progressBar1->TabIndex = 13;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->flowLayoutPanel1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(5, 3);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(187, 499);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"New acquisition";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->comboBox3);
			this->flowLayoutPanel1->Controls->Add(this->label6);
			this->flowLayoutPanel1->Controls->Add(this->comboBox2);
			this->flowLayoutPanel1->Controls->Add(this->label1);
			this->flowLayoutPanel1->Controls->Add(this->durationTextBox);
			this->flowLayoutPanel1->Controls->Add(this->checkBox1);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel2);
			this->flowLayoutPanel1->Controls->Add(this->progressBar1);
			this->flowLayoutPanel1->Controls->Add(this->label8);
			this->flowLayoutPanel1->Location = System::Drawing::Point(6, 50);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(175, 460);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"EnableDacOutput", L"DontStopDacOnUnderrun", L"DontStopDacOnOverrun",
					L"TriggeredAcquisition"
			});
			this->comboBox3->Location = System::Drawing::Point(3, 3);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 16;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 27);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"sample rate";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(3, 109);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(69, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"LiveView";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->ADCcheckedListBox);
			this->flowLayoutPanel2->Controls->Add(this->DACcheckedListBox);
			this->flowLayoutPanel2->Controls->Add(this->comboBox1);
			this->flowLayoutPanel2->Controls->Add(this->StartButton);
			this->flowLayoutPanel2->Controls->Add(this->button1);
			this->flowLayoutPanel2->Controls->Add(this->label7);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 132);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(172, 169);
			this->flowLayoutPanel2->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(84, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 159);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 336);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"label8";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				13.85542F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				86.14458F)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chart1, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(-9, 1);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1494, 919);
			this->tableLayoutPanel1->TabIndex = 15;
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(3, 892);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 24);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1484, 961);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximumSize = System::Drawing::Size(1500, 2000);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion





	private: System::Void DACcheckedListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {



		if (!backgroundWorker1->IsBusy)
		{
			if (initParamAcquis())
				startAcquis();
		}
		else
		{
			MessageBox::Show("You need to stop the current acquisition first");
		}
		
	}


	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SampleInterval_ = 1 / (Convert::ToDouble(this->comboBox2->SelectedItem->ToString()) * 1000);

		label3->Text = (1 / SampleInterval_ / 1000).ToString() + "kHz" + " - " + SampleInterval_.ToString();
	}

	private: System::Void durationTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (!String::IsNullOrEmpty(durationTextBox->Text) && durationTextBox->Text)
		{
			double duration = 0;
			if (double::TryParse(this->durationTextBox->Text, duration))
			{
				AdcSamplesPerChannel = ceil(Convert::ToInt32(this->durationTextBox->Text) / SampleInterval_);
				label4->Text = AdcSamplesPerChannel.ToString() + " samples \n recorded at";
			}
			else
			{
				label4->Text = "Invalid Value";
			}
		}
		else
		{
			label4->Text = "";
		}

	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}



	private : System::Void updateChart()
	{
		mut->WaitOne();
		for (int actualChan = 0; actualChan < AdcChannelNumber; actualChan++)
		{
			this->chart1->Series[actualChan]->Points->DataBindY(Queues[actualChan]);
			
		}
		
		mut->ReleaseMutex();
		this->chart1->Update();
		//this->chart1->Update();
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		MethodInvoker^ mi = gcnew MethodInvoker(this, &MyForm::updateChart);
		chart1->Invoke(mi);
		
			
	}


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}


		void Control_PreviewKeyDown(Object^ sender, PreviewKeyDownEventArgs^ e)
		{
			if (e->KeyCode == Keys::Enter)
			{
				StartButton->PerformClick();
			}
		}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked)
		{
			this->durationTextBox->Text = "";
			this->durationTextBox->Enabled = 0;
			liveViewMode = 1;
		}
		else
		{
			this->durationTextBox->Enabled = 1;
			liveViewMode = 0;
		}
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		
		bool out = 0;
		do
		{
			//Get the number of samples in the fifo
			int samplesInFifo = LIH_AvailableStimAndSample(&isRunning);



			if (isRunning == 0)
			{
				printf("isRunning = 0\n");
				exit;
			}

			if (samplesInFifo >= 1000)
			{
				int samplesToReadInFIFO;

				if (samplesInFifo > AdBlockSize)
					samplesToReadInFIFO = AdBlockSize;
				else
					samplesToReadInFIFO = samplesInFifo;


				LIH_ReadStimAndSample(
					samplesToReadInFIFO,
					doHalt,
					InData);




				mut->WaitOne();
				//For each channels :
				for (int actualChan = 0; actualChan < AdcChannelNumber; actualChan++)
				{
					String^ nameStringSerie = "Series" + (actualChan + 1).ToString("D");

					//For each samples recorded
					for (int actualSample = 0; actualSample < samplesToReadInFIFO; actualSample++)
					{
						time = (actualSample + readSamples);

						//time += SampleInterval_;

						//this->chart1->Series[nameStringSerie]->Points->AddXY(time, LIH_AdcUnitsToVolts(1, InData[actualChan][actualSample]));
						//this->chart1->Series[nameStringSerie]->Points->AddXY(time, LIH_AdcUnitsToVolts(1, InData[actualChan][actualSample]));
						value = LIH_AdcUnitsToVolts(1, InData[actualChan][actualSample]);
						Queues[actualChan]->Enqueue(value);
					}
				}



				if (Queues[0]->Count > 2000 && liveViewMode == 1)
				{
					for (int actualChan = 0; actualChan < AdcChannelNumber; actualChan++)
					{
						for (unsigned int i = 0; i < 1000; i++)
						{
							Queues[actualChan]->Dequeue();
						}
						//this->chart1->Series[actualChan]->Points->DataBindY(Queues[actualChan]);
					}
					//this->chart1->Update();
					//label7->Text = samplesInFifo.ToString();
				}

				/*	if (liveViewMode == 1 && this->chart1->Series[0]->Points->Count > 1000)
					{
						this->chart1->Update();
						for(int i = 0; i< 100; i++)
							this->chart1->Series[0]->Points->RemoveAt(i);
						this->chart1->ResetAutoValues();
					}*/


				mut->ReleaseMutex();
				readSamples = readSamples + samplesToReadInFIFO;




				//STIMULATION

				if (remainingDaSamples > samplesToReadInFIFO)
					SetStimEnd = 0;
				else
				{
					SamplesToWriteToFifo = remainingDaSamples;
					SetStimEnd = 1;
				}


				/*	LIH_AppendToFIFO(
						SamplesToWriteToFifo,
						SetStimEnd,
						OutData);*/


						//writtenSamples = writtenSamples + SamplesToWriteToFifo;
			}


				
			if (liveViewMode)
				if (liveIsRunning)
					out = 0;
				else
					out = 1;

			else
				if (readSamples < AdcSamplesPerChannel)
					out = 0;
				else
					out = 1;

		
				
			
		} while (!out);

		MethodInvoker^ mi = gcnew MethodInvoker(this, &MyForm::updateChart);
		chart1->Invoke(mi);
	}


private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	for (int i = 0; i < AdcChannelNumber; i++) {
		Queues[i]->Clear();
		delete[](InData[i]);
		//InData[i] = NULL;
	}
	timer1->Stop();
	readSamples = 0;
	endLive = 1;
	
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (backgroundWorker1->IsBusy)
	{
		LIH_Halt();
		mutLiveBoolean->WaitOne();
		liveIsRunning = 0;
		mutLiveBoolean->ReleaseMutex();
	/*	backgroundWorker1->CancelAsync();*/
	}
}
private: System::Void ADCcheckedListBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
	//if (backgroundWorker1->IsBusy)
	//{
	//	mutLiveBoolean->WaitOne();
	//	liveIsRunning = 0;
	//	mutLiveBoolean->ReleaseMutex();
	//
	//	while (endLive != 0)
	//	{
	//	}
	//	this->StartButton->PerformClick();
	//	
	//}

	/*if (liveViewMode == 1)
	{
		initParamAcquis();
		startAcquis();
	}*/

	if(backgroundWorker1->IsBusy)
		button1->PerformClick();



}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox3->SelectedIndex == 0)
		AcquisitionMode = 0;
	else
		AcquisitionMode = std::pow(2,comboBox3->SelectedIndex);
}


	private: System::Int16 initParamAcquis(/*System::Object^ sender, System::EventArgs^ e*/) {

		if (liveViewMode == 1)
		{
			//A live acquisition is currently being done
			if (liveIsRunning == 1)
			{
				//The stop button has been pressed => we stop the acquisition
				this->checkBox1->Checked = 0;
				exit;
			}
			//First time the live acquisition has been asked
			else
			{
				AdcSamplesPerChannel = INT_MAX;
				SampleInterval_ = 0.0001;
			}
			timer1->Start();
			liveIsRunning = 1;
		}
		//IF we are not in a live view
		else
		{

			//show the progress bar
			this->progressBar1->Show();
			readSamples = 0;
		}



		//Reset of the adc channel used
		for (int i = 0; i < 16; i++) {
			AdcChannels_[i] = 0;

			
		}

		//Reset the dispaly of data
		for (int i = 0; i < 5; i++)
		{
			this->chart1->Series[i]->Points->Clear();
			this->chart1->Series[i]->Enabled = 0;
			this->chart1->ChartAreas[i]->Visible = 0;
			this->chart1->ChartAreas[i]->AxisY->Maximum = 1;
			this->chart1->ChartAreas[i]->AxisY->Minimum = -1;
			
			Queues[i]->Clear();
			
	

		}


		AdcChannelNumber = this->ADCcheckedListBox->CheckedItems->Count;




		if (AdcChannelNumber != 0)
		{
			doHalt = 0;
			ReadContinuously = 0;

			if (DacSamplesPerChannel > maxBlockSize)
			{
				daBlockSize = maxBlockSize;
				SetStimEnd = 0;
			}
			else
			{
				daBlockSize = DacSamplesPerChannel;
				SetStimEnd = 1;
			}

			writtenSamples = daBlockSize;
			remainingDaSamples = DacSamplesPerChannel - writtenSamples;

			if (AdcSamplesPerChannel > maxBlockSize)
			{
				AdBlockSize = maxBlockSize;
				ReadContinuously = 1;
			}
			else
			{
				AdBlockSize = AdcSamplesPerChannel;
				ReadContinuously = 1;
			}


			String^ AdcString = "ADC: {";
			for (int i = 0; i < this->ADCcheckedListBox->CheckedItems->Count; i++)
			{
				String^ chanString = ADCcheckedListBox->CheckedItems[i]->ToString();

				AdcChannels_[i] = Convert::ToInt32(chanString);

				//Prepare the display of the data
				this->chart1->ChartAreas[i]->Visible = 1;
				this->chart1->Series[i]->Enabled = 1;

				//this->chart1->ChartAreas[i]->AxisY->Maximum = .4;
				//this->chart1->ChartAreas[i]->AxisY->Minimum = -.4;




				//prepare the buffer the required channel
				InData[i] = new EPC_INT16[AdBlockSize];

		
					


				label5->Text = AdcString + ", " + chanString;

			}

			label5->Text = AdcString + "}";


			if (liveViewMode)
			{
				AdBlockSize = 1000;
				ReadContinuously = 1;
			}

			return 1;
		}
		else
		{
			
		MessageBox::Show("Atleast one ADC has to be selected");
		return 0;
		}

	}


	private: System::Void startAcquis(/*System::Object^ sender, System::EventArgs^ e*/) {

		LIH_Halt();


		////Start the recording of the data on the mentioned channels
		bool success = LIH_StartStimAndSample(
			DacChannelNumber,
			AdcChannelNumber,
			daBlockSize,
			AdBlockSize,
			AcquisitionMode,
			DacChannels_,
			AdcChannels_,
			SampleInterval,
			OutData,
			InData,            // for Immediate mode only
			&immediateData,
			SetStimEnd,
			ReadContinuously);

		//this->Cursor = Cursors::WaitCursor;
		//if the acquisition has successfully started :

		
		if (success == 1)
		{
			backgroundWorker1->RunWorkerAsync();
			//update sampleInt
			label8->Text = (1 / SampleInterval_ / 1000).ToString() + "kHz" + " - " + SampleInterval_.ToString();
		}
		else
		{
			MessageBox::Show("Unable to start the acquisition");
		}

		/*		LIH_Halt();*/
		//this->progressBar1->Hide();

	}




};


}
