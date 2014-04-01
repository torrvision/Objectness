#pragma once

struct ImgContrastBB
{
	ImgContrastBB(CStr &imgPath);
	ImgContrastBB(CMat &img3u);

	inline float contrastVal(Vec4i &center);
	inline int regSum(Vec4i &box, Vec3i &sumColor); // Return region size and sum color

private:
	Mat iImg;
	int _w, _h;
	inline void assertBBox(Vec4i &center, CStr &name);
};

ImgContrastBB::ImgContrastBB(CStr &imgPath)
{
	Mat img3u = imread(imgPath);
	integral(img3u, iImg, CV_32SC3);
	_w = img3u.cols;
	_h = img3u.rows;
}

ImgContrastBB::ImgContrastBB(CMat &img3u)
{
	integral(img3u, iImg, CV_32SC3);
	_w = img3u.cols;
	_h = img3u.rows;
}

int ImgContrastBB::regSum(Vec4i &box, Vec3i &sumColor)
{
	int x1 = box[0] - 1, y1 = box[1] - 1, x2 = box[2] - 1, y2 = box[3] - 1;
	sumColor = iImg.at<Vec3i>(y2, x2) + iImg.at<Vec3i>(y1, x1) - iImg.at<Vec3i>(y1, x2) - iImg.at<Vec3i>(y2, x1);
	return (x2 - x1)*(y2 - y1);
}


float ImgContrastBB::contrastVal(Vec4i &center)
{
	int wd = (center[2] - center[0])/2, hd = (center[3] - center[1])/2;
	Vec4i surround(max(center[0] - wd, 1), max(center[1] - hd, 1), min(center[2] + wd, _w), min(center[3] + hd, _h));
	Vec3i cColr, sColr;

	assertBBox(center, "Center");
	assertBBox(center, "Surround");
	int cSz = regSum(center, cColr);
	int sSz = regSum(surround, sColr);

	sColr -= cColr;
	sSz -= cSz;
	sColr /= sSz;
	cColr /= cSz;
	return sqrtf((float)(sqr(sColr[0] - cColr[0]) + sqr(sColr[1] - cColr[1]) + sqr(sColr[2] - cColr[2])))/100.0f;
}

void ImgContrastBB::assertBBox(Vec4i &center, CStr &name)
{
	if (center[0] < 1 || center[1] < 1 || center[2] > _w || center[3] > _h)
		printf("%s: (%d, %d, %d, %d), (%d, %d)\n", _S(name), center[0], center[1], center[2], center[3], _w, _h);
}