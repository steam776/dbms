#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// �����з���BIGINT�����ֵ����Сֵ
const long long BIGINT_MAX = 9223372036854775807;
const long long BIGINT_MIN = 0-9223372036854775808;

// ����BIGINT����
struct BIGINT {
    long long value;

    BIGINT() : value(0) {}
    BIGINT(long long val) : value(val) {}
};

// ���ݿ���е�һ�м�¼
struct Record {
    BIGINT bid; // �з���BIGINT�ֶ�
    int sid;    // INT�ֶ�

    Record() : sid(0) {}
};

// ���ݿ��
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
    // ʵ��ɾ����¼�Ĺ���
}

void Table::update(const Record& old_record, const Record& new_record) {
    // ʵ�ָ��¼�¼�Ĺ���
}

std::vector<Record> Table::selectAll() const {
    return records; // ���ش洢�ڱ��е����м�¼
}

void writeOutputToFile(const std::vector<Record>& records) {
    std::ofstream outputFile("output.txt"); // ��output.txt�ļ�

    if (outputFile.is_open()) {
        // ����ѯ���д��output.txt�ļ�
        for (const auto& record : records) {
            outputFile << "bid: " << record.bid.value << ", sid: " << record.sid << std::endl;
        }

        outputFile.close(); // �ر�output.txt�ļ�
    }
    else {
        std::cout << "Unable to open output.txt" << std::endl;
    }
}

int main() {
    Table t;

    // ��Ӳ�������
    Record r1;
    r1.bid.value = 372036854775807;
    r1.sid = 233421;

    Record r2;
    r2.bid.value = -922337203685477580;
    r2.sid = 124332;

    t.insert(r1);
    t.insert(r2);

    // ��ѯ�������д��output.txt�ļ�
    std::vector<Record> records = t.selectAll();
    writeOutputToFile(records);

    return 0;
}
