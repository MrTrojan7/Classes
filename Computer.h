#pragma once
#include <iostream>
class Computer
{
private:
	char* model;
	char* os;
	char* processor;
	int generation;
	const double exp_benchmark = 2.5;
public:
	Computer();
	Computer(const char* _model, const char* _os, 
			const char* _processor, int _generaion);
	const char* const GetModel();
	const char* const GetOS();
	const char* const GetProcessor();
	double SetBenchmark();
	int GetGeneration();
	void SetModel(const char* model_);
	void SetOS(const char* os_);
	void SetProcessor(const char* processor_);
	void Show();
	~Computer();
};

