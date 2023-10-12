string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), std::not_fn(isspace));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), std::not_fn(isspace).base(),
        s.end()
    );

    return s;
}

std::string ltrim(const std::string& str) {
	return std::string(std::find_if(str.cbegin(), str.cend(), [](unsigned char ch) {return !std::isspace(ch); }), str.cend());
}

std::string rtrim(const std::string& str) {
	return std::string(str.cbegin(), std::find_if(str.crbegin(), str.crend(), [](unsigned char ch) {return !std::isspace(ch); }).base());
}


// bool isspace(char ch); 判断字符是否为空格
// base() 将反向迭代器转换为正向迭代器
