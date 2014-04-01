#include "kyheader.h"
#include "Objectness.h"
#include "ValStructVec.h"
#include "CmShow.h"


void RunObjectness(CStr &resName, double base, int W, int NSS, int numPerSz);

void illutrateLoG()
{
    for (float delta = 0.5f; delta < 1.1f; delta+=0.1f){
        Mat f = Objectness::aFilter(delta, 8);
        normalize(f, f, 0, 1, NORM_MINMAX);
        CmShow::showTinyMat(format("D=%g", delta), f);
    }
    waitKey(0);
}



int main(int argc, char* argv[])
{
    //CStr wkDir = "D:/WkDir/DetectionProposals/VOC2007/Local/";
    //illutrateLoG();
    //RunObjectness("WinRecall.m", 2, 8, 2, 130);
    //RunObjectness("WinRecall.m", 2, 8, 2, 130);
    RunObjectness("WinRecall.m", 2, 8, 2, 130);
    //RunObjectness("WinRecall.m", 2, 8, 2, 130);
    //RunObjectness("WinRecall.m", 2, 8, 2, 130);

    return 0;
}

void RunObjectness(CStr &resName, double base, int W, int NSS, int numPerSz)
{
    srand((unsigned int)time(NULL));
    DataSetVOC voc2007("/home/bittnt/BING/BING_beta1/VOC/VOC2007/");
    voc2007.loadAnnotations();
    //voc2007.loadDataGenericOverCls();

    printf("Dataset:`%s' with %d training and %d testing\n", _S(voc2007.wkDir), voc2007.trainNum, voc2007.testNum);
    printf("%s Base = %g, W = %d, NSS = %d, perSz = %d\n", _S(resName), base, W, NSS, numPerSz);

    Objectness objNess(voc2007, base, W, NSS);

    vector<vector<Vec4i>> boxesTests;
    //objNess.getObjBndBoxesForTests(boxesTests, 250);
    objNess.getObjBndBoxesForTestsFast(boxesTests, numPerSz);
    //objNess.getRandomBoxes(boxesTests);

    //objNess.evaluatePerClassRecall(boxesTests, resName, 1000);
    //objNess.illuTestReults(boxesTests);
    //objNess.evaluatePAMI12();
    //objNess.evaluateIJCV13();
}
