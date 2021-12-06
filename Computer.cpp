#include "Computer.h"

using namespace std;

Computer::Computer()
{
	this->model = new char[50];
	this->os = new char[50];
	this->processor = new char[50];
	this->generation = rand() % (12 - 1) + 1;
	strcpy_s(this->model, 49, "Lenovo");
	strcpy_s(this->os, 49, "Windows");
	strcpy_s(this->processor, 49, "Intel");
}

Computer::Computer(const char* _model, const char* _os, 
					const char* _processor, int _generaion)
{
	this->model = new char[50];
	this->os = new char[50];
	this->processor = new char[50];
	strcpy_s(model, 49, _model);
	strcpy_s(os, 49, _os);
	strcpy_s(processor, 49, _processor);
	this->generation = _generaion;
	/*delete[] _model;
	delete[] _os;
	delete[] _processor;*/
}

const char* const Computer::GetModel()
{
	return model;
}

const char* const Computer::GetOS()
{
	return os;
}

const char* const Computer::GetProcessor()
{
	return processor;
}

double Computer::SetBenchmark()
{
	return exp_benchmark * generation;
}

int Computer::GetGeneration()
{
	return generation;
}

void Computer::SetModel(const char* model_)
{
	strcpy_s(model, 49, model_);
}

void Computer::SetOS(const char* os_)
{
	strcpy_s(os, 49, os_);
}

void Computer::SetProcessor(const char* processor_)
{
	strcpy_s(processor, 49, processor_);
}

void Computer::Show()
{
	cout << GetModel() << endl;
	cout << GetOS() << endl;
	cout << GetProcessor() << endl;
	cout << GetGeneration() << endl;
	cout << SetBenchmark() << endl;
}

Computer::~Computer()
{
	delete[] model;
	delete[] os;
	delete[] processor;
}
