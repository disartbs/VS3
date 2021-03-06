#include "ServiceOperationBuilder.h"

using namespace std;

vector<Operation*> ServiceOperationBuilder::obtainOperations(string str)
{
	vector<Operation*> operations;



	ConversionOperation* converOper = new ConversionOperation;
	SquaringOperation* squarOper = new SquaringOperation;
	SummationOperation* sumOper = new SummationOperation;
	OutputOperation* outOper = new OutputOperation;
	operations.push_back(converOper);
	operations.push_back(squarOper);
	operations.push_back(sumOper);
	operations.push_back(outOper);

	Chainer* chainer = new Chainer;

	chainer->chain(converOper, squarOper);
	converOper->input->data = str;
	chainer->chain(squarOper, sumOper);
	chainer->chain(sumOper, outOper);

	//Chainer<Operation>* chainer = new Chainer<Operation>;
	//chainer->chain(converOp, squarOper);




	/*Chainer<string, vector<double>>* chainer1 = new Chainer<string, vector<double>>;
	GenericOperation<string, vector<double>>* converOper = chainer1->chain(new ConversionOperation);
	converOper->input->data = str;
	operations.push_back(converOper);

	Chainer<vector<double>, vector<double>>* chainer2 = new Chainer<vector<double>, vector<double>>;
	GenericOperation<vector<double>, vector<double>>* sqearOper = chainer2->chain(new SquaringOperation, converOper->output);
	operations.push_back(sqearOper);

	Chainer<vector<double>, double>* chainer3 = new Chainer<vector<double>, double>;
	GenericOperation<vector<double>, double>* summOper = chainer3->chain(new SummationOperation, sqearOper->output);
	operations.push_back(summOper);*/

	return operations;
}
