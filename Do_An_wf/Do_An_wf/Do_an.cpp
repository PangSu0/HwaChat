#include "Do_an.h"

using namespace cv;
using namespace std;
//bien toan cuc
Mat video;
VideoCapture cam;
String anhmau[5] = { "anhmau0.png","anhmau1.png","12.png","anhmau3.png","anhmau4.png" };
//ten win
string ten_anh = "My Picture";
String tenmau[10];
// cac bien dieu khien chuot
Point diem_bd, diem_ht;
bool keo_chuot;
bool di_chuot;
bool chup;
//thuc hien lenh tempalte matching
bool TemplateMatching;
Rect HCN;
int dem = 0;

///

void MatchingMethod(Mat anh_mau, int R, int G, int B, int n) {
	Mat anh_kq;
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	int result_cols = video.cols - anh_mau.cols + 1;
	int result_rows = video.rows - anh_mau.rows + 1;
	anh_kq.create(result_cols, result_rows, CV_32FC1);

	matchTemplate(video, anh_mau, anh_kq, 5);
	//threshold(trunggian,trunggian,0.8,1.,CV_THRESH_TOZERO);

	while (1)
	{
		minMaxLoc(anh_kq, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		if (maxVal >= 0.8)
		{
			putText(video, tenmau[n], Point(maxLoc.x + anh_mau.cols - 20, maxLoc.y + anh_mau.rows + 20), 2, 1, Scalar(0, 255, 0), 2);
			rectangle(video, maxLoc, Point(maxLoc.x + anh_mau.cols, maxLoc.y + anh_mau.rows), CV_RGB(R, G, B), 2, 8, 0);
			rectangle(anh_kq, maxLoc, Point(maxLoc.x + anh_mau.cols, maxLoc.y + anh_mau.rows), CV_RGB(R, G, B), 2, 8, 0);
			floodFill(video, maxLoc, Scalar(R, G, B), 0, Scalar(.1), Scalar(1.));
		}
		else
		{
			break;
		}
	}

}
void dk_chuot(int event, int x, int y, int flags, void* userdata)
{
	if (event == CV_EVENT_LBUTTONDOWN&&keo_chuot == false)
	{
		diem_bd = Point(x, y);
		keo_chuot = true;
	}
	if (event == CV_EVENT_MOUSEMOVE&& keo_chuot == true)
	{
		diem_ht = Point(x, y);
		di_chuot = true;
	}
	if (event == CV_EVENT_LBUTTONUP&& di_chuot == true)
	{
		HCN = Rect(diem_bd, diem_ht);
		keo_chuot = false;
		di_chuot = false;
		chup = true;
		dem = dem + 1;
	}
}
void chup_anh(Mat frame)
{
	Mat khung;
	Mat anh;
	Mat kq;
	string ten;
	Mat anh_mau;
	if (chup == true)
	{
		cam.read(anh);
		khung = anh(HCN);
		khung.copyTo(anh_mau);
		bool tg = imwrite(anhmau[dem], anh_mau);
		imshow("kq", anh_mau);
		cout << "ten linh kien: ";
		cin >> ten;
		tenmau[dem] = ten;
		chup = false;
	}


	if (di_chuot == true)
	{
		rectangle(frame, diem_bd, Point(diem_ht.x, diem_ht.y), Scalar(0, 255, 0));
	}
}