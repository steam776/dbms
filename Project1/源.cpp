#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// 定义有符号BIGINT的最大值和最小值
const long long BIGINT_MAX = 9223372036854775807;
const long long BIGINT_MIN = 0-9223372036854775808;

// 定义BIGINT类型
struct BIGINT {
    long long value;

    BIGINT() : value(0) {}
    BIGINT(long long val) : value(val) {}
};

// 数据库表中的一行记录
struct Record {
    BIGINT bid; // 有符号BIGINT字段
    int sid;    // INT字段

    Record() : sid(0) {}
};

// 数据库表
class Table {
public:
    void insert(const Record& record);
    void remove(const Record& record);
    void update(const Record& old_record, const Record& new_record);
    std::vector<Record> selectAll() const;

private:
    std::vector<Record> records;
};

void Table::insert(const Record& record) {
    records.push_back(record);
}

void Table::remove(const Record& record) {
    // 实现删除记录的功能
}

void Table::update(const Record& old_record, const Record& new_record) {
    // 实现更新记录的功能
}

std::vector<Record> Table::selectAll() const {
    return records; // 返回存储在表中的所有记录
}

void writeOutputToFile(const std::vector<Record>& records) {
    std::ofstream outputFile("output.txt"); // 打开output.txt文件

    if (outputFile.is_open()) {
        // 将查询结果写入output.txt文件
        for (const auto& record : records) {
            outputFile << "bid: " << record.bid.value << ", sid: " << record.sid << std::endl;
        }

        outputFile.close(); // 关闭output.txt文件
    }
    else {
        std::cout << "Unable to open output.txt" << std::endl;
    }
}

int main() {
    Table t;

    // 添加测试数据
    Record r1;
    r1.bid.value = 372036854775807;
    r1.sid = 233421;

    Record r2;
    r2.bid.value = -922337203685477580;
    r2.sid = 124332;

    t.insert(r1);
    t.insert(r2);

    // 查询并将结果写入output.txt文件
    std::vector<Record> records = t.selectAll();
    writeOutputToFile(records);

    return 0;
}
