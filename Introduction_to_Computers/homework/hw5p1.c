/*題目:密碼強度鑑驗
夢之城雲端服務需要帳號與密碼才可以登入系統使用。為了保障個人帳戶的安全，系統會要求使用者設定密碼時需有足夠的強度。設定密碼時要求下列四項條件：

密碼至少需要8個字元
密碼內容需要同時包含大小寫字母
密碼內容需要包含數字0-9
密碼正寫與反寫不可以相同(大小寫視為不同)
請協助完成負責上述第四項條件之函式，檢查密碼正反寫不可相同之條件。密碼會經由主程式檢驗以上1~4項條件，通過1項可以得1分，並計算強度總分。



輸入格式

pwdStr：密碼字串，字串長度不超過100


輸出格式

r1：條件一結果(通過顯示Pass，沒通過顯示Fail)
r2：條件二結果(通過顯示Pass，沒通過顯示Fail)
r3：條件三結果(通過顯示Pass，沒通過顯示Fail)
r4：條件四結果(通過顯示Pass，沒通過顯示Fail)
score：密碼強度檢驗總分
需要完成及繳交的函式：
bool CheckPwdPattern(char password[]) 函式

password 密碼字串，傳入欲判斷的使用者設置的密碼。
此函式判斷通過與否，通過則回傳true(1)，未通過則回傳false(0)。
bool CheckPwdPattern(char password[]) {
          // 請完成並繳交本函式
}

範例測資1

輸入

abc123CBA

輸出

Pass
Pass
Pass
Pass
4

範例測資2

輸入

ab3c3ba

輸出

Fail
Fail
Pass
Fail
1
*/
/*
01　	#include <iostream>
02　	#include <cstring>
03　	using namespace std;
04　	
05　	bool Message(bool flg) { // 印出結果，並回傳分數（0或1）
06　	if (flg == 0) {
07　	cout << "Fail" << endl;
08　	}
09　	else {
10　	cout << "Pass" << endl;
11　	}
12　	return flg;
13　	}
14　	
15　	bool CheckPwdLength(char password[]) { // r1：密碼至少需要8個字元
16　	    int len = strlen(password);
17　	    return len >= 8;
18　	}
19　	
20　	bool CheckPwdLetter(char password[]) { // r2：密碼內容需要同時包含大小寫字母
21　	    bool upper = false, lower = false;
22　	    int len = strlen(password);
23　	    for(int i = 0; i < len; i++) {
24　	        if(password[i] >= 'a' && password[i] <= 'z') {
25　	            lower = true;
26　	        }
27　	        else if(password[i] >= 'A' && password[i] <= 'Z') {
28　	            upper = true;
29　	        }
30　	    }
31　	    return lower&&upper;
32　	}
33　	bool CheckPwdWithDigit(char password[]) { // r3：密碼內容需要包含數字0-9
34　	    int len = strlen(password);
35　	    for(int i = 0; i < len; i++) {
36　	        if(password[i] >= '0' && password[i] <= '9') {
37　	            return true;
38　	        }
39　	    }
40　	    return false;
41　	}
42　	
43　	bool CheckPwdPattern(char password[]) { // r4：密碼正寫與反寫不可以相同(大小寫視為不同)
44	        (作答區，雖然其他程式碼是C++，但作答區請打C)
45　	}
46　	
47　	int main() {
48　	char pwdStr[105] = {};
49　	int score = 0;
50　	
51　	cin >> pwdStr;
52　	
53　	score += Message(CheckPwdLength(pwdStr)); // Call r1
54　	    score += Message(CheckPwdLetter(pwdStr)); // Call r2
55　	    score += Message(CheckPwdWithDigit(pwdStr)); // Call r3
56　	    score += Message(CheckPwdPattern(pwdStr)); // Call r4
57　	
58　	    cout << score << endl; // 印出密碼強度檢驗總分
59　	    return 0;
60　	}
61　	*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//bool型別，則需要 #include <stdbool.h>   https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/90337/
bool CheckPwdPattern(char password[]) { // r4：密碼正寫與反寫不可以相同(大小寫視為不同)
    int len = strlen(password); //計算字串長度
    for(int i=0;i<len/2;i++){
        if(password[i] != password[len-1-i]){ //len-1是把長度轉換為陣列的位置符
            return true;
        }
    }
    return false;
}
int main() {
    char pwdStr[105];
	int score = 0;
    scanf("%s",&pwdStr);
    printf("%d",CheckPwdPattern(pwdStr));
}