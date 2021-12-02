#include "Computer.h"

Computer::Computer()
{
	this->model = new char[50];
	this->os = new char[50];
	this->processor = new char[50];
	this->generation = rand() % 12;
	this->exp_benchmark = 2.5;
}

const char* Computer::GetModel()
{
	return model;
}

const char* Computer::GetOS()
{
	return os;
}

const char* Computer::GetProcessor()
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

Computer::~Computer()
{
	delete[] model;
	delete[] os;
	delete[] processor;
}
