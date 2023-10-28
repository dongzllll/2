#include <stdio.h>

// 判断某年份是否是闰年
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// 获取某年某月的天数
int getDaysInMonth(int year, int month) {
    int daysInMonth;

    switch (month) {
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
        case 12: // December
            daysInMonth = 31;
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            daysInMonth = 30;
            break;
        case 2: // February
            if (isLeapYear(year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            daysInMonth = -1; // 无效的月份
            break;
    }

    return daysInMonth;
}

// 打印日历
void printCalendar(int year, int month) {
    // 获取该月的天数
    int daysInMonth = getDaysInMonth(year, month);

    // 获取该月的第一天是星期几
    int firstDayOfWeek = 1; // 假设为星期一（1-7，分别对应星期一至星期日）

    // 打印日历标题
    printf("     %d年%d月\n", year, month);
    printf("Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

    // 打印第一天之前的空格
    for (int i = 1; i < firstDayOfWeek; i++) {
        printf("     ");
    }

    // 打印每一天的日期
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%-5d", day);

        // 换行
        if ((firstDayOfWeek + day - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int year, month;

    // 获取用户输入的年份和月份
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);

    // 打印日历
    printCalendar(year, month);

    return 0;
}
