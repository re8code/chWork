/**************************************************************
 * 빌더 패턴을 사용하는 애플리케이션 파일                     *
 **************************************************************/
#include "director.h"

int main() {  
    // 여행 유형 선택
    int type=1;
    while (type >= 1 && type <= 3) {
        cout << "Enter the type of vacation (1, 2, 3): "; // 실행 화면 내용으로 변경
        cin >> type;

        // 여행 계획 확인
        Director::book(type);
    }

    return 0;
}
