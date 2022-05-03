#include <jni.h>
#include <opencv2/opencv.hpp>

#include <android/log.h>

using namespace std;

using namespace cv;

float resize(Mat img_src, Mat &img_resize, int resize_width){

    float scale = resize_width / (float)img_src.cols ;
    if (img_src.cols > resize_width) {
        int new_height = cvRound(img_src.rows * scale);
        resize(img_src, img_resize, Size(resize_width, new_height));
    }
    else {
        img_resize = img_src;
    }
    return scale;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_useopencvwithcmake_MainActivity_ConvertRGBtoGray(JNIEnv *env, jobject thiz,
                                                                  jlong mat_addr_input,
                                                                  jlong mat_addr_result) {
    // TODO: implement ConvertRGBtoGray()
    Mat &matInput = *(Mat *)mat_addr_input;
    Mat &matResult = *(Mat *)mat_addr_result;

    cvtColor(matInput, matResult, COLOR_RGBA2GRAY);

}





extern "C"
JNIEXPORT void JNICALL
Java_com_example_useopencvwithcmake_MainActivity_detect(JNIEnv *env, jobject thiz,
                                                        jlong matAddrInput) {
    // TODO: implement detect()
    Mat &img_input = *(Mat *) matAddrInput;

    Mat img_result = img_input.clone();

    vector<Vec3f> circles;
    HoughCircles(img_result, circles, HOUGH_GRADIENT, 1, 100, 50, 35, 0, 0);
/*
    for (size_t i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center(c[0], c[1]);
        int radius = c[2];

        circle(img_result, center, radius, Scalar(0, 255, 0), 2);
        circle(img_result, center, 2, Scalar(0, 0, 255), 3);
    }
*/
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_useopencvwithcmake_MainActivity_search(JNIEnv *env, jobject thiz,
                                                        jlong mat_addr_input) {
    // TODO: implement search()



}