#pragma once
#include <iostream>
class Computer
{
private:
	char* model;
	char* os;
	char* processor;
	double benchmark;
	int generation;
	double exp_benchmark;
public:
	Computer();
	const char* GetModel();
	const char* GetOS();
	const char* GetProcessor();
	double SetBenchmark();
	int GetGeneration();
	void SetModel(const char* model_);
	void SetOS(const char* os_);
	void SetProcessor(const char* processor_);
	~Computer();
};

