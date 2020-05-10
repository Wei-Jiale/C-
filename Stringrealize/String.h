#pragma warning(disable : 4996)
// ����������ͻ���Զ��������ռ䡣
namespace WJL{
	class string{
	public:
		//// 1.���캯���޲�
		//string()
		//	// �����ָ������
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';
		//}

		// 2.���캯������
		string(char* str = "")
			:_str(new char[strlen(str)+1])
		{
			// _strָ��Ŀռ��ڶ��ϣ��ɽ���������:�޸ġ����ݣ�
			strcpy(_str, str);
		}

		// 3.��������
		~string(){
			delete[] _str;
			_str = nullptr;
		}

		// 4.�������죨���ǳ������ͬһ�ռ��ͷ����Σ� string s2(s1);
		string(const string& s)
			// ����������ռ�
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		// 5.��ֵ�����ǳ������s1 = s3;
		string& operator=(const string& s){
			// ��ֹ�Լ����Լ���ֵ
			if (this != &s){
				// ���ٺ�s3��ͬ��С����ʱ�ռ�
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				// �ͷ�s1�Ŀռ�
				delete[] _str;
				// s1ָ���¿ռ�
				_str = temp;
			}

			return *this;
		}

	private:
		// string�ǹ����ַ������飬�ײ���һ��ָ�������ָ��
		char* _str;
	};

	void test_string1(){
		// ���캯������������
		string s1;
		string s2("hello");
	}

	void test_string2(){
		// ��������
		string s1("hello");
		string s2(s1);

		// ��ֵ
		string s3("world");
		s1 = s3;
	}
}