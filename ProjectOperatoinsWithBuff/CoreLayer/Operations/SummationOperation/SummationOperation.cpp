#include "SummationOperation.h"

void SummationOperation::execute()
{
	vector<double> vect = input->data;
	double sum = 0;
	for (double item : vect)
	{
		sum += item;
	}
	output->data = sum;
}
