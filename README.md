Objectness
==========
BING Objectness proposal estimator linux/mac/windows version implementation, 
runs at 1000 FPS. This code is under BSD License.
Objectness Proposal estimator运行代码，已经在linux/mac/windows下测试成功，
执行速度超过1000帧每秒。


This is the 1000 FPS BING objectness linux version library for efficient 
objectness proposal estimator following the CVPR 2014 paper BING, please 
consider to cite and refer to this paper.

@inproceedings{BingObj2014,
  title={{BING}: Binarized Normed Gradients for Objectness Estimation at 300fps},
  author={Ming-Ming Cheng and Ziming Zhang and Wen-Yan Lin and Philip H. S. Torr},
  booktitle={IEEE CVPR},
  year={2014},
}

The original author Ming-Ming Cheng has already released the source code for 
windows 64-bit platform. In this library, we intend to release the code for the 
linux/mac/windows users. You can maintain the code with Qt Creator IDE.

Please find the original windows code / FAQ / Paper from this link:
http://mmcheng.net/bing/

In order to make the code running as the original version in windows, you need
to download the images/annotations PASCAL VOC 2007 data from the website.
(http://pascallin.ecs.soton.ac.uk/challenges/VOC/voc2007/#testdata)

We have tested the code, it produces the same accuracy results as the original windows
version, while it runs at 1111 FPS(frame per second) at Ubuntu 12.04 with a Dell T7600 
workstation computer, which has two Intel Xeon E5-2687W (3.1GHz, 1600MHz) and 64 GB 
1600MHz DDR3 Memory.

FAQ

1. Why it shows slower speed than what you said?
Please ensure that you have enable release mode, in Ubuntu 14.04 (or other linux system), do this:
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ../

If you would like to enjoy the debug information, please make sure you do this:
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ../

2. To run the code, you have to install OpenCV in the your ubuntu linux system. 
We specify the dependencies on opencv at
"
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
"
3. You can use/debug/change the code with Qt Creator IDE on ubuntu/mac.

4. "Invalidate class name in /home/yukin/dev/Objectness/Src/DataSetVOC.cpp:125 OpenCV Error: Assertion failed (Invalidate class name ) in loadBox, file /home/yukin/dev/Objectness/Src/DataSetVOC.cpp, line 125 terminate called after throwing an instance of 'cv::Exception' what(): /home/yukin/dev/Objectness/Src/DataSetVOC.cpp:125: error: (-215) Invalidate class name
in function loadBox Aborted I tracked into the code and found out that the fName extracted in the loadBBoxes function seems to be wrong: 'MYDATAPATH/Annotations/00000.yml'. And it seems like ''ImageSets/Main/train.txt" does not exist "

This message shows that you do not have correct path for the VOC files, or you do not have them in your PC. You need to download all the files properly from VOC website, by which i mean that you need to download all files from:
http://pascallin.ecs.soton.ac.uk/challenges/VOC/voc2007/VOCtest_06-Nov-2007.tar
http://pascallin.ecs.soton.ac.uk/challenges/VOC/voc2007/VOCtrainval_06-Nov-2007.tar
You also need to convert all the xml files into yml. You might find XML2YML tools to do so or you can use the tool we put on here.

5. "OpenCV Error: Assertion failed (matRead(_modelName + ".xP", xP1f) && matRead(_modelName + ".xN", xN1f)) in trainStageI, file /home/yukin/dev/Objectness/Src/Objectness.cpp, line 555
terminate called after throwing an instance of 'cv::Exception'
what(): /home/yukin/dev/Objectness/Src/Objectness.cpp:555: error: (-215) matRead(_modelName + ".xP", xP1f) && matRead(_modelName + ".xN", xN1f) in function trainStageI"

This message indicates that you do not have correct path to read the preprocessed positive and negative samples. You might need to use root user to run the program. You might need to set up the result folder and path correctly.




Author: Ming-Ming Cheng(程明明) removethisifyouarehuman-cmm.thu@gmail.com
Linux Author: Shuai Zheng (Kyle,郑帅) removethisifyouarehuman-szhengcvpr@gmail.com
Please find more information from http://kylezheng.org/objectproposal/
Date: 19, February 
