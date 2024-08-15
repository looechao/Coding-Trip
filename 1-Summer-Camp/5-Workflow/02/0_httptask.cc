#include <iostream>
#include <string>
#include <unordered_map>
#include <workflow/WFTask.h>

// 模拟 Redis 数据存储
std::unordered_map<std::string, std::string> redis_db = {
    {"x1", "x2"},
    {"x2", "x3"},
    {"x3", "x4"},
    {"x4", "100"}
};

// 查询函数
std::string query_value(const std::string &key) {
    std::string value = redis_db[key];
    if (value.empty()) {
        return "";  // 如果没有找到，返回空字符串
    }
    return value;
}

// 工作流函数
void find_final_value(WFTask *task, const std::string &key) {
    std::string current_key = key;
    std::string final_value;

    // 逐步查找
    while (true) {
        final_value = query_value(current_key);
        if (final_value.empty()) {
            std::cerr << "Key not found: " << current_key << std::endl;
            break;
        }

        // 如果找到的值是最终值（即不是另一个键），则退出循环
        if (final_value.find_first_not_of("0123456789") == std::string::npos) {
            // final_value 是一个数字，表示我们找到了最终值
            break;
        }

        // 更新当前键
        current_key = final_value;
    }

    // 设置结果
    task->get_resp()->append(final_value);
}

int main() {
    // 创建工作流任务
    WFTask *task = new WFTask();
    task->set_callback(find_final_value, "x1");

    // 执行工作流
    task->dispatch();

    // 打印结果
    std::cout << "Final value: " << task->get_resp()->get_body() << std::endl;

    delete task;
    return 0;
}