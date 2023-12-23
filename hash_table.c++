#include <iostream>
#include <string>

using namespace std;

class ChainStudentNode
{
private:
    int studentID;
    string name;
    string dept;
    ChainStudentNode *next;

    friend class StudentHashTable;
};

class StudentHashTable
{
public:
    void insertStudent(int sID, string sName, string sDept)
    {
        // 實作插入學生的邏輯
        int slotID = hashIndex(sID);
        // 直接做一個新的ChainStudentNode
        ChainStudentNode* new_node = new ChainStudentNode(sID, sName, sDept);
        if(StudentHashTable[slotID] == NULL){
            StudentHashTable[slotID] = new_node;
        }
        else{
            new_node -> next = StudentHashTable[slotID];
            StudentHashTable[slotID] = new_node;
        }
    };
    void retrieveName(int sID)
    {
        // 實作檢索學生名字的邏輯
        int slotID = hashIndex(sID);
        while (StudentHashTable[slotID])
        {
            if(StudentHashTable[slotID] -> studentID == sID)
            {
            cout << StudentHashTable[slotID] -> name << endl;
            };
            StudentHashTable[slotID] = StudentHashTable[slotID] -> next
        }
        cout << "" << endl;
    };
    
protected:
    int hashIndex(int sID)
    {
        // 實作哈希函數
        return (sID%10 + (sID/10%10)*10 + (sID/100%10)*100) % 101;
    };

private:
    static const int HASH_TABLE_SIZE = 101;
    ChainStudentNode *table[HASH_TABLE_SIZE];
};

int main()
{
    StudentHashTable a;

    return 0;
}

// 顯式 MyClass m1 = MyClass(str);

// 隱式 MyClass m2(str, 12345, 67890);
