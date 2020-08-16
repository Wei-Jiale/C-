#include "cppjieba/Jieba.hpp"
using namespace std;

// ��ͷִ���ʹ�õĴʵ�
const char* const DICT_PATH = "../dict/jieba.dict.utf8";
const char* const HMM_PATH = "../dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "../dict/user.dict.utf8";
const char* const IDF_PATH = "../dict/idf.utf8";
const char* const STOP_WORD_PATH = "../dict/stop_words.utf8";

int main(int argc, char** argv) {
	// �����Ͷ��󣬹��캯���д���ʵ��·����
	cppjieba::Jieba jieba(DICT_PATH,
		HMM_PATH,
		USER_DICT_PATH,
		IDF_PATH,
		STOP_WORD_PATH);
	// ��ŷִʽ����vector
	vector<string> words;
	// ��ѯ��
	string s;
	string result;

	s = "С��˶ʿ��ҵ���й���ѧԺ�������������ձ�������ѧ����";
	cout << s << endl;
	cout << "[demo] CutForSearch" << endl;
	jieba.CutForSearch(s, words);
	cout << limonp::Join(words.begin(), words.end(), "/") << endl;

	return EXIT_SUCCESS;
}