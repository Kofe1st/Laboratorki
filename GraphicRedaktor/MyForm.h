#pragma once

namespace GraphicRedaktor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			ñîçäàòüToolStripMenuItem_Click(nullptr, nullptr);

			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnLine_Click);
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::btnEllipse_Click);
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::btnRect_Click);
			this->btnPenColor->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem_Click);
			this->btnBrushColor->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem1_Click);

			// ÍÀÑÒÐÎÉÊÀ ÑÏÈÑÊÀ ÒÎËÙÈÍÛ
			this->thicknessCombo->ComboBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->thicknessCombo->ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			for (int i = 1; i <= 10; i++) this->thicknessCombo->Items->Add(i);
			this->thicknessCombo->SelectedIndex = 0;
			this->thicknessCombo->ComboBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MyForm::thicknessCombo_DrawItem);
		}

	private:
		static int startX, startY;
		static int prevX, prevY;
		static int tool = 1;
		static bool isChanged = false;
		static System::Drawing::Rectangle previewRect;

		// Ìåòîä îòðèñîâêè ëèíèé â ñïèñêå
		void thicknessCombo_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
			if (e->Index < 0) return;
			e->DrawBackground();
			int thickness = safe_cast<int>(this->thicknessCombo->Items[e->Index]);
			System::Drawing::Pen^ p = gcnew System::Drawing::Pen(System::Drawing::Color::Black, (float)thickness);
			int y = e->Bounds.Top + e->Bounds.Height / 2;
			e->Graphics->DrawLine(p, e->Bounds.Left + 5, y, e->Bounds.Right - 5, y);
			delete p;
			e->DrawFocusRectangle();
		}

	protected:
		~MyForm() { if (components) delete components; }

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ñîçäàòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îòêðûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ñîõðàíèòüÊàêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ êàðàíäàøToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ öâåòToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ òîëùèíàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^ thicknessCombo;
	private: System::Windows::Forms::ToolStripMenuItem^ êèñòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ öâåòToolStripMenuItem1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ColorDialog^ penColorDialog;
	private: System::Windows::Forms::ColorDialog^ brushColorDialog;
	private: System::Windows::Forms::Button^ btnPenColor;
	private: System::Windows::Forms::Button^ btnBrushColor;
	private: System::Windows::Forms::CheckBox^ chkFill;

	private: System::Void btnEllipse_Click(System::Object^ sender, System::EventArgs^ e) { tool = 1; }
	private: System::Void btnRect_Click(System::Object^ sender, System::EventArgs^ e) { tool = 2; }
	private: System::Void btnLine_Click(System::Object^ sender, System::EventArgs^ e) { tool = 3; }

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ñîçäàòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->îòêðûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ñîõðàíèòüÊàêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->êàðàíäàøToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->öâåòToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->òîëùèíàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->thicknessCombo = (gcnew System::Windows::Forms::ToolStripComboBox());
			   this->êèñòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->öâåòToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->btnBrushColor = (gcnew System::Windows::Forms::Button());
			   this->btnPenColor = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->chkFill = (gcnew System::Windows::Forms::CheckBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->penColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			   this->brushColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->menuStrip1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->ôàéëToolStripMenuItem,
					   this->êàðàíäàøToolStripMenuItem, this->êèñòüToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(906, 28);
			   this->menuStrip1->TabIndex = 2;
			   // 
			   // ôàéëToolStripMenuItem
			   // 
			   this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->ñîçäàòüToolStripMenuItem,
					   this->îòêðûòüToolStripMenuItem, this->ñîõðàíèòüÊàêToolStripMenuItem, this->âûõîäToolStripMenuItem
			   });
			   this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			   this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			   this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			   // 
			   // ñîçäàòüToolStripMenuItem
			   // 
			   this->ñîçäàòüToolStripMenuItem->Name = L"ñîçäàòüToolStripMenuItem";
			   this->ñîçäàòüToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			   this->ñîçäàòüToolStripMenuItem->Text = L"Ñîçäàòü";
			   this->ñîçäàòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîçäàòüToolStripMenuItem_Click);
			   // 
			   // îòêðûòüToolStripMenuItem
			   // 
			   this->îòêðûòüToolStripMenuItem->Name = L"îòêðûòüToolStripMenuItem";
			   this->îòêðûòüToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			   this->îòêðûòüToolStripMenuItem->Text = L"Îòêðûòü";
			   this->îòêðûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòêðûòüToolStripMenuItem_Click);
			   // 
			   // ñîõðàíèòüÊàêToolStripMenuItem
			   // 
			   this->ñîõðàíèòüÊàêToolStripMenuItem->Name = L"ñîõðàíèòüÊàêToolStripMenuItem";
			   this->ñîõðàíèòüÊàêToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			   this->ñîõðàíèòüÊàêToolStripMenuItem->Text = L"Ñîõðàíèòü êàê";
			   this->ñîõðàíèòüÊàêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîõðàíèòüÊàêToolStripMenuItem_Click);
			   // 
			   // âûõîäToolStripMenuItem
			   // 
			   this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			   this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			   this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			   this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âûõîäToolStripMenuItem_Click);
			   // 
			   // êàðàíäàøToolStripMenuItem
			   // 
			   this->êàðàíäàøToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->öâåòToolStripMenuItem,
					   this->òîëùèíàToolStripMenuItem
			   });
			   this->êàðàíäàøToolStripMenuItem->Name = L"êàðàíäàøToolStripMenuItem";
			   this->êàðàíäàøToolStripMenuItem->Size = System::Drawing::Size(94, 24);
			   this->êàðàíäàøToolStripMenuItem->Text = L"Êàðàíäàø";
			   // 
			   // öâåòToolStripMenuItem
			   // 
			   this->öâåòToolStripMenuItem->Name = L"öâåòToolStripMenuItem";
			   this->öâåòToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			   this->öâåòToolStripMenuItem->Text = L"Öâåò";
			   this->öâåòToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem_Click);
			   // 
			   // òîëùèíàToolStripMenuItem
			   // 
			   this->òîëùèíàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->thicknessCombo });
			   this->òîëùèíàToolStripMenuItem->Name = L"òîëùèíàToolStripMenuItem";
			   this->òîëùèíàToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			   this->òîëùèíàToolStripMenuItem->Text = L"Òîëùèíà";
			   // 
			   // thicknessCombo
			   // 
			   this->thicknessCombo->Name = L"thicknessCombo";
			   this->thicknessCombo->Size = System::Drawing::Size(121, 24);
			   // 
			   // êèñòüToolStripMenuItem
			   // 
			   this->êèñòüToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->öâåòToolStripMenuItem1 });
			   this->êèñòüToolStripMenuItem->Name = L"êèñòüToolStripMenuItem";
			   this->êèñòüToolStripMenuItem->Size = System::Drawing::Size(62, 24);
			   this->êèñòüToolStripMenuItem->Text = L"Êèñòü";
			   // 
			   // öâåòToolStripMenuItem1
			   // 
			   this->öâåòToolStripMenuItem1->Name = L"öâåòToolStripMenuItem1";
			   this->öâåòToolStripMenuItem1->Size = System::Drawing::Size(32, 19);
			   this->öâåòToolStripMenuItem1->Text = L"Öâåò";
			   this->öâåòToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem1_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->btnBrushColor);
			   this->panel1->Controls->Add(this->btnPenColor);
			   this->panel1->Controls->Add(this->button3);
			   this->panel1->Controls->Add(this->button2);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->chkFill);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->panel1->Location = System::Drawing::Point(0, 28);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(906, 74);
			   this->panel1->TabIndex = 1;
			   // 
			   // btnBrushColor
			   // 
			   this->btnBrushColor->BackColor = System::Drawing::Color::White;
			   this->btnBrushColor->Location = System::Drawing::Point(513, 10);
			   this->btnBrushColor->Name = L"btnBrushColor";
			   this->btnBrushColor->Size = System::Drawing::Size(132, 50);
			   this->btnBrushColor->TabIndex = 0;
			   this->btnBrushColor->Text = L"Öâåò êèñòè";
			   this->btnBrushColor->UseVisualStyleBackColor = false;
			   // 
			   // btnPenColor
			   // 
			   this->btnPenColor->BackColor = System::Drawing::Color::Black;
			   this->btnPenColor->ForeColor = System::Drawing::Color::White;
			   this->btnPenColor->Location = System::Drawing::Point(366, 10);
			   this->btnPenColor->Name = L"btnPenColor";
			   this->btnPenColor->Size = System::Drawing::Size(132, 50);
			   this->btnPenColor->TabIndex = 1;
			   this->btnPenColor->Text = L"Öâåò ïåðà";
			   this->btnPenColor->UseVisualStyleBackColor = false;
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(230, 10);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(130, 50);
			   this->button3->TabIndex = 2;
			   this->button3->Text = L"Ïðÿìîóãîëüíèê";
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(120, 10);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(100, 50);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"Ýëëèïñ";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(10, 10);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(100, 50);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Ëèíèÿ";
			   // 
			   // chkFill
			   // 
			   this->chkFill->Checked = true;
			   this->chkFill->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->chkFill->Location = System::Drawing::Point(650, 25);
			   this->chkFill->Name = L"chkFill";
			   this->chkFill->Size = System::Drawing::Size(100, 24);
			   this->chkFill->TabIndex = 5;
			   this->chkFill->Text = L"Çàëèâêà";
			   this->chkFill->UseVisualStyleBackColor = true;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::White;
			   this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pictureBox1->Location = System::Drawing::Point(0, 102);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(906, 318);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			   this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			   this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			   this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			   // 
			   // MyForm
			   // 
			   this->ClientSize = System::Drawing::Size(906, 420);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->menuStrip1);
			   this->DoubleBuffered = true;
			   this->Name = L"MyForm";
			   this->Text = L"Ãðàôè÷åñêèé ðåäàêòîð";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void ñîçäàòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Image = gcnew System::Drawing::Bitmap(pictureBox1->Width, pictureBox1->Height);
		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(pictureBox1->Image);
		g->Clear(System::Drawing::Color::White);
		delete g;
		pictureBox1->Invalidate();
		isChanged = false;
	}

	private: System::Void îòêðûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image = System::Drawing::Image::FromFile(openFileDialog1->FileName);
			isChanged = false;
		}
	}

	private: System::Void ñîõðàíèòüÊàêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->Image != nullptr && saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image->Save(saveFileDialog1->FileName);
		}
	}

	private: System::Void öâåòToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (penColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->btnPenColor->BackColor = penColorDialog->Color;
			this->btnPenColor->ForeColor = (penColorDialog->Color.R < 120) ? System::Drawing::Color::White : System::Drawing::Color::Black;
		}
	}

	private: System::Void öâåòToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (brushColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->btnBrushColor->BackColor = brushColorDialog->Color;
			this->btnBrushColor->ForeColor = (brushColorDialog->Color.R < 120) ? System::Drawing::Color::White : System::Drawing::Color::Black;
		}
	}

	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }

	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (pictureBox1->Image == nullptr) return;
		startX = prevX = e->X; startY = prevY = e->Y;
		isChanged = true;
	}

	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button != System::Windows::Forms::MouseButtons::Left) return;
		prevX = e->X; prevY = e->Y;
		previewRect = System::Drawing::Rectangle(Math::Min(startX, e->X), Math::Min(startY, e->Y), Math::Abs(e->X - startX), Math::Abs(e->Y - startY));
		pictureBox1->Invalidate();
	}

	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (pictureBox1->Image == nullptr || e->Button != System::Windows::Forms::MouseButtons::Left) return;
		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(pictureBox1->Image);
		float thickness = (float)safe_cast<int>(this->thicknessCombo->SelectedItem);
		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(penColorDialog->Color, thickness);
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(brushColorDialog->Color);

		int nx = Math::Min(startX, e->X); int ny = Math::Min(startY, e->Y);
		int nw = Math::Abs(e->X - startX); int nh = Math::Abs(e->Y - startY);

		// ÐÈÑÓÅÌ ÏÎÑÒÎßÍÍÓÞ ÔÈÃÓÐÓ ÍÀ ÕÎËÑÒÅ Ñ Ó×ÅÒÎÌ ÔËÀÆÊÀ ÇÀËÈÂÊÈ
		if (tool == 1) { // Ýëëèïñ
			// Åñëè ôëàæîê óñòàíîâëåí, ñíà÷àëà äåëàåì çàëèâêó
			if (this->chkFill->Checked) {
				g->FillEllipse(brush, nx, ny, nw, nh);
			}
			// Êîíòóð ðèñóåì âñåãäà
			g->DrawEllipse(pen, nx, ny, nw, nh);
		}
		if (tool == 2) { // Ïðÿìîóãîëüíèê
			// Åñëè ôëàæîê óñòàíîâëåí, ñíà÷àëà äåëàåì çàëèâêó
			if (this->chkFill->Checked) {
				g->FillRectangle(brush, nx, ny, nw, nh);
			}
			// Êîíòóð ðèñóåì âñåãäà
			g->DrawRectangle(pen, nx, ny, nw, nh);
		}
		if (tool == 3) { // Ëèíèÿ (ôëàæîê çàëèâêè íå âëèÿåò)
			g->DrawLine(pen, startX, startY, e->X, e->Y);
		}


		delete pen; delete brush; delete g;
		previewRect = System::Drawing::Rectangle(0, 0, 0, 0);
		pictureBox1->Invalidate();
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (previewRect.Width == 0 && tool != 3) return;
		float thickness = (float)safe_cast<int>(this->thicknessCombo->SelectedItem);
		System::Drawing::Pen^ pPreview = gcnew System::Drawing::Pen(penColorDialog->Color, thickness);
		System::Drawing::SolidBrush^ bPreview = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(100, brushColorDialog->Color));

		// ÐÈÑÓÅÌ ÏÐÅÂÜÞ ÊÎÍÒÓÐÀ Ñ Ó×ÅÒÎÌ ÔËÀÆÊÀ ÇÀËÈÂÊÈ
		if (tool == 1) { // Ýëëèïñ
			if (this->chkFill->Checked) {
				e->Graphics->FillEllipse(bPreview, previewRect);
			}
			e->Graphics->DrawEllipse(pPreview, previewRect);
		}
		if (tool == 2) { // Ïðÿìîóãîëüíèê
			if (this->chkFill->Checked) {
				e->Graphics->FillRectangle(bPreview, previewRect);
			}
			e->Graphics->DrawRectangle(pPreview, previewRect);
		}
		if (tool == 3) { // Ëèíèÿ
			e->Graphics->DrawLine(pPreview, startX, startY, prevX, prevY);
		}
		delete pPreview; delete bPreview;
	}
	};
}