#include <iostream>
#include <cstring>

class CowString {
private:
    int refcount;    // 引用计数
    char *str;       // 指向实际字符串数据的指针
    char *copy;      // 指向拷贝字符串数据的指针

public:
    // 构造函数
    CowString();

    CowString(const char *s) {
        str = new char[strlen(s) + 1];  // 分配内存并复制字符串
        strcpy(str, s);
        copy = str;
        refcount = 1;
    }

    // 拷贝构造函数
    CowString(const CowString &other) {
        str = other.str;  // 浅拷贝字符串指针
        copy = other.copy;
        refcount = other.refcount;
        refcount++;  // 增加引用计数
    }

    // 析构函数
    ~CowString() {
        if (--refcount == 0) {
            delete[] str;  // 当引用计数减为零时释放内存
        }
    }

    // 下标访问运算符重载，返回 CharProxy 对象
    class CharProxy {
    private:
        CowString &cowStr;  // 引用父对象的实例
        size_t index;       // 字符索引

    public:
        CharProxy(CowString &str, size_t idx) : cowStr(str), index(idx) {}

        // 重载赋值运算符，用于写操作
        CharProxy &operator=(char c) {
            if (cowStr.refcount > 1) {
                cowStr.refcount--;  // 减少原有数据的引用计数
                cowStr.str = new char[strlen(cowStr.copy) + 1];  // 分配新的内存
                strcpy(cowStr.str, cowStr.copy);  // 复制数据到新内存
                cowStr.copy = cowStr.str;  // 更新拷贝指针
                cowStr.refcount = 1;  // 重置引用计数为 1
            }
            cowStr.str[index] = c;  // 修改字符, 进行写操作
            return *this;
        }

        // 转换为 char，用于读操作
        operator char() const {
            return cowStr.str[index];  // 返回字符
        }
    };

    // 下标访问运算符重载，返回 CharProxy 对象
    // 只能利用str1对象和下标0来进行创建
    // 所以CharProxy的构造函数携程如下形式
    //
    // str1[0] = 'H';  需要给CharProxy定义赋值运算符函数
    // cout << str1[0] << endl; 需要为charProxy重载输出流运算符
    CharProxy operator[](size_t index) {
        return CharProxy(*this, index);  // 返回 CharProxy 对象
    }


    // 获取引用计数（用于测试和调试目的）
    int getRefCount() const {
        return refcount;  // 返回引用计数
    }

    // 友元函数，用于比较两个 CowString 对象（用于测试和调试目的）
    friend bool operator==(const CowString &lhs, const CowString &rhs) {
        return std::strcmp(lhs.str, rhs.str) == 0;  // 比较字符串是否相等
    }

    // 友元函数，用于比较两个 CowString 对象（用于测试和调试目的）
    friend bool operator!=(const CowString &lhs, const CowString &rhs) {
        return !(lhs == rhs);  // 比较字符串是否不相等
    }

    // 友元函数，直接输出 CowString 对象（用于测试和调试目的）
    friend std::ostream& operator<<(std::ostream &os, const CowString &cowStr) {
        os << cowStr.str;  // 输出字符串内容
        return os;
    }

    // 赋值运算符重载
    CowString& operator=(const CowString &other) {
        if (this != &other) {
            if (--refcount == 0) {
                delete[] str;  // 减少引用计数并释放内存
            }
            str = other.str;  // 浅拷贝字符串指针
            copy = other.copy;
            refcount = other.refcount;
            refcount++;  // 增加引用计数
        }
        return *this;
    }
};

int main() {
    CowString str1("Hello");
    CowString str2 = str1; // 使用拷贝构造函数，'Hello' 的引用计数变为 2
    CowString str3("World");

    std::cout << "初始状态:\n";
    std::cout << "str1: " << str1 << ", 引用计数: " << str1.getRefCount() << "\n";
    std::cout << "str2: " << str2 << ", 引用计数: " << str2.getRefCount() << "\n";
    std::cout << "str3: " << str3 << ", 引用计数: " << str3.getRefCount() << "\n";

    str1[0] = 'X'; // 执行写操作，只修改了 str1 的内容

    std::cout << "\n修改 str1 后:\n";
    std::cout << "str1: " << str1 << ", 引用计数: " << str1.getRefCount() << "\n";
    std::cout << "str2: " << str2 << ", 引用计数: " << str2.getRefCount() << "\n";
    std::cout << "str3: " << str3 << ", 引用计数: " << str3.getRefCount() << "\n";

    std::cout << "\nstr2 的内容应保持不变:\n";
    std::cout << "str2: " << str2 << ", 引用计数: " << str2.getRefCount() << "\n";

    return 0;
}

