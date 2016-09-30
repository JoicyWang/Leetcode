class Solution {
public:
    string toHex(int num) {
        unsigned int newNum = (int)num;
        string res = "";
        do{
            res = num2Hex(newNum % 16) + res;
            newNum /= 16;
        }while(newNum);
        return res;
    }
private:
    char num2Hex(unsigned int num) {
        char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        return hex[num];
    }
};