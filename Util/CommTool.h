#pragma  once

#include <filesystem>
#include <vector>
#include <string>

//��ȡָ��Ŀ¼�£�ָ����չ���ļ��б���vecFiles����
void GetAllFiles(char *filePath, char *suffix, std::vector<std::string> &vecFiles);

//��ȡ��ǰ����ִ�еĸ�Ŀ¼
void GetExeRootPath(std::string &strRootPath);

//���б������nRandomNum��index��index�����ظ���
void RandomFromList(std::vector<int> &vecIndex, int nNeedNum, int nMaxNum);

//����weightȨ�ؽ��������������������
int GetWeightOutput(std::vector<int> &vecWeight);