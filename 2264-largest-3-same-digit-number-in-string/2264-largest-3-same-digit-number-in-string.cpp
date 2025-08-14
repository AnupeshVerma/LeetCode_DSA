class Solution {
private:
    string singleIteration(string num) {
        string maxDigit = "";
        
        for(int i=2; i<num.size(); i++) {
            if(num[i]==num[i-1] && num[i-1]==num[i-2])
                maxDigit = max(maxDigit, string(3, num[i]));
        }
        return maxDigit;
    }

    string storingDigits(string num) {
        vector<string> sameDigits = {"000", "111", "222", "333", "444", "555","666","777","888","999"};

        for(int i=9; i>=0; i--) {
            for(int j=2; j<num.size(); j++) {
                char digit = sameDigits[i][0];
                cout<<digit<<" ";
                if(num[j]==digit && num[j-1]==digit && num[j-2]==digit)
                    return sameDigits[i];
            }
        }
        return "";
    }


public:
    string largestGoodInteger(string num) {

        return storingDigits(num);

        return singleIteration(num);
    }
};