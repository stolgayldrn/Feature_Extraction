//////////////////////////////////////////////////////////////////////////
/// This code creates features from frames		
//////////////////////////////////////////////////////////////////////////
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc.hpp"
//#include "helpers.h"
#include <string>
#include "helpers2.h"
#include "TFeatureExtractor.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	vector<string> fileList;
	get_directory_images(argv[1],fileList);//@param argv[1] is directory of frames' folder
	t_feat_init();// initialization of TFeatureExtractor
	
	
	for(int i = 0; i < fileList.size(); i++)
	{
		string fileName = argv[1];
		fileName = fileName + "\\" + fileList[i]; 
		Mat im = imread(fileName,IMREAD_GRAYSCALE);
		TByte * IM = im.data;
		t_feat_extract(IM, 480, 360, 20, 3, 200);
		//	TAPISTD(TSignature)		t_feat_extract_buffer(TByte* imageData, TUInt dataSize, TUInt maxFeaturesPerImage, TFeatureMode featMode = T_FEAT_CV_SIFT, TFeatDistMode distMode = T_FEAT_DIST_EUC, TFeatCompressMode compressMode = T_FEAT_CMPRS_NONE);

	}
	

	//{
	//	//
	//	string fn = fileList[i].substr(0,fileList[i].length()-4);
	//	//TChar *FileName = (TChar)fn.c_str();
	//	TSignature signature;
	//	t_feat_init_sig(signature);
	//	//t_feat_extract(image, 480, 360, 20, 3, 200);
	//	//t_feat_write_sig_v2(signature,FileName);

	//}
	

	return 0;
}