#include <stdio.h>

// �ж�ĳ����Ƿ�������
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// ��ȡĳ��ĳ�µ�����
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
            daysInMonth = -1; // ��Ч���·�
            break;
    }

    return daysInMonth;
}

// ��ӡ����
void printCalendar(int year, int month) {
    // ��ȡ���µ�����
    int daysInMonth = getDaysInMonth(year, month);

    // ��ȡ���µĵ�һ�������ڼ�
    int firstDayOfWeek = 1; // ����Ϊ����һ��1-7���ֱ��Ӧ����һ�������գ�

    // ��ӡ��������
    printf("     %d��%d��\n", year, month);
    printf("Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

    // ��ӡ��һ��֮ǰ�Ŀո�
    for (int i = 1; i < firstDayOfWeek; i++) {
        printf("     ");
    }

    // ��ӡÿһ�������
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%-5d", day);

        // ����
        if ((firstDayOfWeek + day - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int year, month;

    // ��ȡ�û��������ݺ��·�
    printf("��������ݣ�");
    scanf("%d", &year);
    printf("�������·ݣ�");
    scanf("%d", &month);

    // ��ӡ����
    printCalendar(year, month);

    return 0;
}
