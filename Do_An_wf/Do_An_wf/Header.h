#pragma once

#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace System::Runtime::InteropServices;

namespace tung
{
	class camera
	{
	public:
		camera();
		System::Drawing::Bitmap^ Show(Mat & colorImage);

	};
}
