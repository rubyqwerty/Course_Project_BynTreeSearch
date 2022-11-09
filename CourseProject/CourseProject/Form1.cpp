#include "pch.h"
#include "Form1.h"
#include "string"
using namespace CourseProject;

using namespace System::Drawing;




System::Void Form1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	bts->push(Decimal::ToInt32(numericUpDown1->Value));
	bts->coordinate.clear();
	bts->arrowsCor.clear();
	bts->Visualization(450,10, 220);
	
	pictureBox1->Refresh();
}

System::Void Form1::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	for (int i = 0; i < bts->coordinate.size(); ++i)
	{
		int x, y;
		x = bts->coordinate[i].x;
		y = bts->coordinate[i].y;
		e->Graphics->DrawEllipse(System::Drawing::Pens::Green, x, y, 30, 30);
		
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Verdana", 10);
	    SolidBrush^ fontBrush = gcnew SolidBrush(Color::Blue);
	    e->Graphics->DrawString(gcnew System::String(to_string(bts->coordinate[i].value).c_str()) , drawFont, fontBrush, PointF(x+8, y+7));
	}

	for (int i = 0; i < bts->arrowsCor.size(); ++i)
	{
		int x1, x2, y1, y2;
		x1 = bts->arrowsCor[i].x+15;
		y1 = bts->arrowsCor[i].y+30;
		x2 = bts->arrowsCor[i].x1+15;
		y2 = bts->arrowsCor[i].y1;
		e->Graphics->DrawLine(System::Drawing::Pens::Green, x1, y1, x2, y2);
	}
}

System::Void Form1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	bts->deleteNode(Decimal::ToInt32(numericUpDown2->Value));

	bts->coordinate.clear();
	bts->arrowsCor.clear();
	bts->Visualization(450, 10, 220);

	pictureBox1->Refresh();
}

System::Void Form1::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	bts->replace(Decimal::ToInt32(numericUpDown4->Value), Decimal::ToInt32(numericUpDown5->Value));

	bts->coordinate.clear();
	bts->arrowsCor.clear();
	bts->Visualization(450, 10, 220);

	pictureBox1->Refresh();
}

System::Void Form1::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	delete[] Array;

	Size = Decimal::ToInt32(numericUpDown6->Value);
	Array = new int[Size];

	unsigned rand_value = 11;
	srand(rand_value); // рандомизация генератора случайных чисел

	for (int i = 0; i < Size; ++i)
		Array[i] = (rand()%100000);


}

System::Void Form1::таблицаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	button1->Visible = false;
	button2->Visible = false;
	button3->Visible = false;
	button4->Visible = false;
	button5->Visible = false;
	button6->Visible = false;
	numericUpDown1->Visible = false;
	numericUpDown2->Visible = false;
	numericUpDown3->Visible = false;
	numericUpDown4->Visible = false;
	numericUpDown5->Visible = false;
	numericUpDown6->Visible = false;
	pictureBox1->Visible = false;
	dataGridView1->Visible = true;
	chart1->Visible = false;
	label1->Visible = false;
	if (this->Width == width)
	{
		this->Width = this->Width - 300;
		this->Height = this->Height - 100;
	}
}

System::Void Form1::графикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	button1->Visible = false;
	button2->Visible = false;
	button3->Visible = false;
	button4->Visible = false;
	button5->Visible = false;
	button6->Visible = false;
	numericUpDown1->Visible = false;
	numericUpDown2->Visible = false;
	numericUpDown3->Visible = false;
	numericUpDown4->Visible = false;
	numericUpDown5->Visible = false;
	numericUpDown6->Visible = false;
	pictureBox1->Visible = false;
	dataGridView1->Visible = false;
	chart1->Visible = true;
	label1->Visible = false;
	chart1->Location = Point(85, 35);
	if (this->Width == width)
	{
		this->Width = this->Width - 300;
		this->Height = this->Height - 100;
	}
}

System::Void Form1::главнаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	button1->Visible = true;
	button2->Visible = true;
	button3->Visible = true;
	button4->Visible = true;
	button5->Visible = true;
	button6->Visible = true;
	numericUpDown1->Visible = true;
	numericUpDown2->Visible = true;
	numericUpDown3->Visible = true;
	numericUpDown4->Visible = true;
	numericUpDown5->Visible = true;
	numericUpDown6->Visible = true;
	pictureBox1->Visible = true;
	chart1->Visible = false;
	dataGridView1->Visible = false;
	label1->Visible = true;
	if (this->Width != width)
	{
		this->Width = this->Width + 300;
		this->Height = this->Height + 100;
	}

}

System::Void Form1::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	double TimeBynTreeS = SortByBynaryTreeSearch(Array, Size);

	double TimeBubbleSort = BubbleSorting(Array, Size);

	chart1->Series[0]->Points->AddXY(Size, TimeBynTreeS);
	chart1->Series[1]->Points->AddXY(Size, TimeBubbleSort);

	DataGridViewCell^ number = gcnew DataGridViewTextBoxCell();
	DataGridViewCell^ size = gcnew DataGridViewTextBoxCell();
	DataGridViewCell^ time1 = gcnew DataGridViewTextBoxCell();
	DataGridViewCell^ time2 = gcnew DataGridViewTextBoxCell();

	static int num = 1;

	number->Value = num++;
	size->Value = Size;
	time1->Value = TimeBubbleSort;
	time2->Value = TimeBynTreeS;

	DataGridViewRow ^row0 = gcnew DataGridViewRow();
	row0->Cells->AddRange(number, size, time1, time2);

	dataGridView1->Rows->Add(row0);
}

