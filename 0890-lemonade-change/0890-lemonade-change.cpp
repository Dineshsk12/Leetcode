class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;  // Counters for $5 and $10 bills

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;  // No $5 bill to give as change
                five--;
                ten++;
            } else {  // bill == 20
                if (ten > 0 && five > 0) {  // Prefer giving one $10 and one $5
                    ten--;
                    five--;
                } else if (five >= 3) {  // Otherwise, give three $5 bills
                    five -= 3;
                } else {
                    return false;  // Cannot give the correct change
                }
            }
        }
        return true;
    }
};
