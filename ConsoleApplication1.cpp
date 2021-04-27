#include "pbPlots.hpp"
#include "supportLib.hpp"
#include "math.h"

using namespace std;
double f(double x) {
	return cos(x);
}

int main() {
	cout << "Plotting!\n";
	RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

	vector<double> xs; // = { -2, -1, 0, 1, 2 };
	vector<double> ys;//= { 2, -1, -2, -1, 2 };
	for (int i = -10; i <= 10; i++){
	double x = (double)i / 10;
	xs.push_back(x);
	double y = f(x);
	ys.push_back(y);
}
	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &xs;
	series->ys = &ys;
	series->linearInterpolation = true;
	series->lineType = toVector(L"dashed");
	series->lineThickness = 1;
	series->color = CreateRGBColor(1,0,0);
	ScatterPlotSettings*settings = GetDefaultScatterPlotSettings();
	settings->width = 600;
	settings->height = 400;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"x^2 - 2");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);

	DrawScatterPlotFromSettings(imageReference,settings);

	vector<double>* pngdata = ConvertToPNG(imageReference->image);
	WriteToFile(pngdata, "example1.png");
	DeleteImage(imageReference->image);
	cout << "Done!\n";

	return 0;
}