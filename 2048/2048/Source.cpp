#include "Prerequires.h"


void DrawADog(Mat &img, int x, int y, int stepStyle, char *text)
{
	const int HEAD_SIZE = 20;
	circle(img, Point(x, y), HEAD_SIZE,
	Scalar(255, 0, 0), 2);
	rectangle(img, Point(x - 3 * HEAD_SIZE, y),
	Point(x - HEAD_SIZE, y + HEAD_SIZE / 2),
	Scalar(0, 0, 255));
	line(img, Point(x - 3 * HEAD_SIZE, y),
	Point(x - 3 * HEAD_SIZE - HEAD_SIZE / 5, y - HEAD_SIZE / 3),
	Scalar(0, 0, 255));
	const int STEP_STYLE = stepStyle;
	line(img, Point(x - 1.5*HEAD_SIZE - HEAD_SIZE / 10, y + HEAD_SIZE / 2),
	Point(x - 1.5*HEAD_SIZE - HEAD_SIZE / 10 -
		STEP_STYLE, y + HEAD_SIZE),
	Scalar(0, 0, 255));
	line(img, Point(x - 1.5*HEAD_SIZE - HEAD_SIZE / 10, y + HEAD_SIZE / 2),
	Point(x - 1.5*HEAD_SIZE - HEAD_SIZE / 10 +
		STEP_STYLE, y + HEAD_SIZE),
	Scalar(0, 0, 255));
	line(img, Point(x - 3 * HEAD_SIZE, y + HEAD_SIZE / 2),
		Point(x - 3 * HEAD_SIZE - STEP_STYLE, y + HEAD_SIZE),
		Scalar(0, 0, 255));
	line(img, Point(x - 3 * HEAD_SIZE, y + HEAD_SIZE / 2),
		Point(x - 3 * HEAD_SIZE + STEP_STYLE, y + HEAD_SIZE),
		Scalar(0, 0, 255));
	putText(img, text, Point(x, y - 1.5*HEAD_SIZE),
		FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0));
}

void DrawFrame(Mat &img, int xStartFrame, int yStartFrame) {
	int xEndFrame = xStartFrame + SQUARE_SIZE * NUMBER_SQUARE;
	int yEndFrame = yStartFrame + SQUARE_SIZE * NUMBER_SQUARE;
	Scalar frameColor = Scalar(0, 255, 0);
	rectangle(img, Point(xStartFrame, yStartFrame), Point(xEndFrame, yEndFrame), frameColor);

	/* Draw vertical lines to create small squares with properties: */
	/*  > Start point: y not change = yStart; */
	/*  > End point: y not change = yEnd */
	/*  > x increases by SQUARE_SIZE */
	for (int i = 0; i < NUMBER_SQUARE; i++) {
		int x = xStartFrame + SQUARE_SIZE * (i + 1);
		line(img, Point(x, yStartFrame), Point(x, yEndFrame), frameColor);
	}

	/* Draw vertical lines to create small squares with properties: */
	/*  > Start point: x not change = xStart; */
	/*  > End point: x not change = xEnd */
	/*  > y increases by SQUARE_SIZE */
	for (int i = 0; i < NUMBER_SQUARE; i++) {
		int y = yStartFrame + SQUARE_SIZE * (i + 1);
		line(img, Point(xStartFrame, y), Point(xEndFrame, y), frameColor);
	}
}

void DrawInitNumber(Mat &img) {
	string textNumber = "2";
	/* Apply For text length is 1 */
	int textSize = SQUARE_SIZE/50;
	int leftSpace = SQUARE_SIZE / 10 * 3;	// 30;
	int bottomSpace = SQUARE_SIZE / 10 * 3;

	/* Draw first number in the first square (Toa do la goc phai duoi cua square*/
	int x11 = FRAME_X_START, y11 = FRAME_Y_START;
	int x12 = x11 + SQUARE_SIZE, y12 = y11 + SQUARE_SIZE;
	putText(img, textNumber, Point(x11 + leftSpace, y12 - bottomSpace), FONT_HERSHEY_SIMPLEX, textSize, Scalar(0, 0, 255));

	/* Draw second number in the second square */
	int x21 = FRAME_X_START, y21 = FRAME_Y_START + SQUARE_SIZE;
	int x22 = x21 + SQUARE_SIZE, y22 = y21 + SQUARE_SIZE;
	putText(img, textNumber, Point(x21 + leftSpace, y22 - bottomSpace), FONT_HERSHEY_SIMPLEX, textSize, Scalar(0, 0, 255));
}

void randomNextNumPosition() {
	// Find blank positions
}

void plusNumbers() {

}

void main() {
	/* Khai báo biến img kiểu Mat (là một ma trận)*/
/* có kích thước WINDOWS_WIDTH dòng và WINDOWS_HEIGHT cột */
/* ảnh gồm 3 lớp R, G và B (ảnh màu) */
	Mat img(WINDOWS_WIDTH, WINDOWS_HEIGHT, CV_32FC3);
	/* Khai báo tọa độ ban đầu của đối tượng (chó) */


	/* Draw 2048 frame */
	img = Mat::zeros(img.rows, img.cols, CV_32FC3);
	DrawFrame(img, FRAME_X_START, FRAME_Y_START); 
	DrawInitNumber(img);
	imshow("2048 PLAY SCREEN - TRAN THIEN AN", img);
	waitKey(10);
	img = Mat::zeros(img.rows, img.cols, CV_32FC3);
	


	//while (x < 1000)
	//{
	//	/* Vẽ đối tượng */
	//	DrawADog(img, x, y, x % 15, (char*)"gau");
	//	/* Dùng imshow để hiển thị thông tin ảnh trên biến img */
	//	imshow("main window", img);
	//	/* Tạm dừng màn hình trong 10 miliseconds */
	//	waitKey(10);
	//	/* Dùng hàm zeros để đưa img về ma trận 0 (màu đen) */
	//	/* Thao tác này tương đương với xóa màn hình */
	//	img = Mat::zeros(img.rows, img.cols, CV_32FC3);
	//	imshow("main window", img);
	//	x+=100;

	//}

	cout << "An's Production" << endl;
	system("pause");
}
