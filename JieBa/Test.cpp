#include "cppjieba/Jieba.hpp"
using namespace std;

// 结巴分词所使用的词典
const char* const DICT_PATH = "../dict/jieba.dict.utf8";
const char* const HMM_PATH = "../dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "../dict/user.dict.utf8";
const char* const IDF_PATH = "../dict/idf.utf8";
const char* const STOP_WORD_PATH = "../dict/stop_words.utf8";

int main(int argc, char** argv) {
	// 构造结巴对象，构造函数中传入词典的路径。
	cppjieba::Jieba jieba(DICT_PATH,
		HMM_PATH,
		USER_DICT_PATH,
		IDF_PATH,
		STOP_WORD_PATH);
	// 存放分词结果的vector
	vector<string> words;
	// 查询词
	string s;
	string result;

	s = "小明硕士毕业于中国科学院计算所，后在日本京都大学深造";
	cout << s << endl;
	cout << "[demo] CutForSearch" << endl;
	jieba.CutForSearch(s, words);
	cout << limonp::Join(words.begin(), words.end(), "/") << endl;

	return EXIT_SUCCESS;
}